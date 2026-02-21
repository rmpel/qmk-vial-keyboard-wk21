/* Copyright 2026 rmpel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "shift_register.h"

/*
 * ===========================================================================
 * CUSTOM MATRIX IMPLEMENTATION WITH SHIFT REGISTER
 * ===========================================================================
 *
 * This keyboard uses:
 *   - 8 rows (via 74HC595 shift register outputs)
 *   - 12 columns (direct GPIO pins)
 *
 * The matrix scanning process:
 * 1. For each row (0-7):
 *    a. Activate that row via shift register (drive LOW)
 *    b. Read all column pins
 *    c. Store any key presses detected
 * 2. Repeat for all rows
 *
 * ROW2COL configuration means:
 * - Rows are outputs (driven by shift register)
 * - Columns are inputs (read via GPIO with pull-ups)
 * - Diodes point from rows to columns
 */

/* Matrix state storage */
static matrix_row_t raw_matrix[MATRIX_ROWS];  // Raw matrix values
static matrix_row_t matrix[MATRIX_ROWS];       // Debounced matrix values

/* Row pins - shift register outputs (8 rows) */
static const pin_t row_pins[MATRIX_ROWS] = {SR0, SR1, SR2, SR3, SR4, SR5, SR6, SR7};

/* Column pins - direct GPIO (12 columns) */
static const pin_t col_pins[MATRIX_COLS] = {A3, A5, A7, B1, B10, B13, A4, A6, B0, B2, B12, B14};

/*
 * ===========================================================================
 * MATRIX INITIALIZATION
 * ===========================================================================
 */

void matrix_init_custom(void) {
    /* Initialize shift register hardware */
    shift_init();
    shift_enable();

    /* Configure column pins as inputs with pull-DOWN resistors
     * (inverted logic due to diode orientation) */
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        gpio_set_pin_input_low(col_pins[col]);
    }

    /* Set all rows LOW (inactive) via shift register - INVERTED LOGIC */
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        shift_writePin(row_pins[row], 0);
    }

    /* Initialize matrix state to all keys released */
    memset(matrix, 0, sizeof(matrix));
    memset(raw_matrix, 0, sizeof(raw_matrix));

    /* Longer delay to let hardware stabilize */
    wait_ms(10);
}

/*
 * ===========================================================================
 * MATRIX SCANNING
 * ===========================================================================
 */

/*
 * Read a single row's state
 * Returns a bitmask where each bit represents a column
 * Bit is set (1) if key is pressed, clear (0) if released
 */
static inline matrix_row_t read_row(uint8_t row) {
    matrix_row_t row_value = 0;

    /* Activate this row (set HIGH - INVERTED due to diode orientation) */
    shift_writePin(row_pins[row], 1);

    /* Read all columns for this row */
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        /* Read the column pin - if HIGH, key is pressed (INVERTED) */
        if (gpio_read_pin(col_pins[col])) {
            row_value |= (1 << col);
        }
    }

    /* Deactivate this row (set LOW - INVERTED) */
    shift_writePin(row_pins[row], 0);

    return row_value;
}

/*
 * Scan the entire matrix
 * Returns true if matrix state changed
 */
bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    /* Scan each row */
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        /* Read current state of this row */
        matrix_row_t row_value = read_row(row);

        /* Check if this row changed */
        if (raw_matrix[row] != row_value) {
            raw_matrix[row] = row_value;
            changed = true;
        }

        /* Update output matrix */
        current_matrix[row] = raw_matrix[row];
    }

    return changed;
}

/*
 * ===========================================================================
 * DEBUGGING SUPPORT
 * ===========================================================================
 */

#ifdef DEBUG_MATRIX_SCAN_RATE
/* Print matrix state for debugging */
void matrix_print(void) {
    uprintf("Matrix:\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        uprintf("  Row %2d: ", row);
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uprintf("%c", (matrix[row] & (1 << col)) ? 'X' : '.');
        }
        uprintf(" (0x%02X)\n", matrix[row]);
    }
}
#endif
