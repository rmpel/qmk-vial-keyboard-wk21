/* Copyright 2026 rmpel
 * Adapted from miiiw shift_register implementation
 * Original Copyright 2023 ArthurCyy <https://github.com/ArthurCyy>
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

#include "shift_register.h"
#include <string.h>

/*
 * ===========================================================================
 * PRIVATE FUNCTIONS
 * ===========================================================================
 */

/* Shift out current values to the shift register */
static void shift_out(void);

/* Current state of shift register outputs */
static uint8_t shift_values[SHR_SERIES_NUM] = {0};

/*
 * ===========================================================================
 * PUBLIC FUNCTIONS
 * ===========================================================================
 */

void shift_init(void) {
    /* Initialize optional output enable pin (active low) */
#ifdef SHR_OE_PIN
    gpio_set_pin_output(SHR_OE_PIN);
    gpio_write_pin_high(SHR_OE_PIN);  // Disable outputs initially
#endif

    /* Initialize shift register control pins */
    gpio_set_pin_output(SHR_DATA_PIN);
    gpio_set_pin_output(SHR_LATCH_PIN);
    gpio_set_pin_output(SHR_CLOCK_PIN);

    /* Set all pins to known state (low) */
    gpio_write_pin_low(SHR_DATA_PIN);
    gpio_write_pin_low(SHR_LATCH_PIN);
    gpio_write_pin_low(SHR_CLOCK_PIN);
}

void shift_enable(void) {
#ifdef SHR_OE_PIN
    gpio_write_pin_low(SHR_OE_PIN);  // Enable outputs (active low)
#endif
    gpio_write_pin_low(SHR_DATA_PIN);
    gpio_write_pin_low(SHR_LATCH_PIN);
    gpio_write_pin_low(SHR_CLOCK_PIN);
}

void shift_disable(void) {
#ifdef SHR_OE_PIN
    gpio_write_pin_high(SHR_OE_PIN);  // Disable outputs (active low)
#endif
    gpio_write_pin_low(SHR_DATA_PIN);
    gpio_write_pin_low(SHR_LATCH_PIN);
    gpio_write_pin_low(SHR_CLOCK_PIN);
}

void shift_writePin(pin_t pin, int level) {
    /* Calculate which shift register chip and bit position */
    uint8_t group = (pin - SR0) >> 3;  // Divide by 8 to get chip number
    uint8_t bit   = 0x01 << ((pin - SR0) & 0x07);  // Modulo 8 to get bit position

    /* Validate group number */
    if (group >= SHR_SERIES_NUM) {
        return;
    }

    /* Update the bit in our shadow register */
    if (level) {
        shift_values[group] |= bit;   // Set bit
    } else {
        shift_values[group] &= ~bit;  // Clear bit
    }

    /* Output the new state to hardware */
    shift_out();
}

void shift_writeGroup(int group, uint8_t value) {
    /* Validate group number */
    if (group >= SHR_SERIES_NUM) {
        return;
    }

    /* Update entire group */
    shift_values[group] = value;

    /* Output the new state to hardware */
    shift_out();
}

void shift_writeAll(int level) {
    /* Set all bits to same value */
    memset(shift_values, level ? 0xFF : 0, sizeof(shift_values));

    /* Output the new state to hardware */
    shift_out();
}

/*
 * ===========================================================================
 * PRIVATE IMPLEMENTATION
 * ===========================================================================
 */

/*
 * Shift out the current state to the 74HC595 shift register(s)
 *
 * Protocol for 74HC595:
 * 1. Set LATCH low to prepare for data
 * 2. For each bit (MSB first):
 *    a. Set CLOCK low
 *    b. Set DATA to bit value
 *    c. Set CLOCK high (data is shifted in on rising edge)
 * 3. Set LATCH high to transfer shift register to output register
 *
 * If multiple chips are daisy-chained, output starts from the last chip
 * in the chain (furthest from MCU) because data shifts through.
 */
static void shift_out(void) {
    uint8_t n = SHR_SERIES_NUM;

    /* Pull latch low to begin data transmission */
    gpio_write_pin_low(SHR_LATCH_PIN);

    /* Shift out data for each chip (last to first if daisy-chained) */
    while (n--) {
        /* Shift out 8 bits for this chip (MSB first) */
        for (uint8_t i = 0; i < 8; i++) {
            /* Clock must be low before changing data */
            gpio_write_pin_low(SHR_CLOCK_PIN);

            /* Set data pin to current bit value */
            gpio_write_pin(SHR_DATA_PIN, shift_values[n] & (0x80 >> i));

            /* Clock high - data is shifted in on rising edge */
            gpio_write_pin_high(SHR_CLOCK_PIN);
        }
    }

    /* Latch high - transfer shift register contents to output register */
    gpio_write_pin_high(SHR_LATCH_PIN);
}

#ifdef SHR_DEBUG
/* Debug function to print shift register state */
void shift_debug(void) {
    for (uint8_t i = 0; i < SHR_SERIES_NUM; i++) {
        uprintf("SR[%d]: 0x%02X ", i, shift_values[i]);
    }
    uprintf("\n");
}
#endif
