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

#pragma once

#include "quantum.h"

/*
 * ===========================================================================
 * 74HC595 SHIFT REGISTER DRIVER
 * ===========================================================================
 *
 * This driver controls the 74HC595 shift register used to expand column pins.
 * The shift register allows controlling 8 outputs using only 3 GPIO pins.
 *
 * Pin mapping:
 *   - SHR_DATA_PIN  -> 74HC595 pin 14 (SER/DS)   - Serial data input
 *   - SHR_CLOCK_PIN -> 74HC595 pin 11 (SRCLK)    - Shift register clock
 *   - SHR_LATCH_PIN -> 74HC595 pin 12 (RCLK)     - Storage register clock
 *   - SHR_OE_PIN    -> 74HC595 pin 13 (OE)       - Output enable (active low, optional)
 *
 * Shift register outputs (Q0-Q7) are connected to keyboard matrix columns.
 */

/*
 * Virtual pin definitions for shift register outputs
 * These represent the 8 outputs of the 74HC595 (Q0-Q7)
 * Used in keyboard.json matrix_pins.cols as SR0-SR7
 */
enum shift_register_pins {
    SR0 = 0x40,  // First virtual pin = 64 (outside normal GPIO range)
    SR1, SR2, SR3, SR4, SR5, SR6, SR7
};

/*
 * Initialize shift register GPIO pins
 * Call this during keyboard initialization
 */
void shift_init(void);

/*
 * Enable shift register outputs
 * Sets OE pin low (if defined) to activate outputs
 */
void shift_enable(void);

/*
 * Disable shift register outputs
 * Sets OE pin high (if defined) to disable outputs
 */
void shift_disable(void);

/*
 * Write to a single shift register pin
 * pin: One of H0-H7
 * level: 1 for high, 0 for low
 */
void shift_writePin(pin_t pin, int level);

/*
 * Write an 8-bit value to all pins of a shift register group
 * group: Shift register index (0 for first chip, 1 for second if daisy-chained)
 * value: 8-bit value where each bit represents one output (bit 0 = Q0, bit 7 = Q7)
 */
void shift_writeGroup(int group, uint8_t value);

/*
 * Set all shift register outputs to same level
 * level: 1 for all high, 0 for all low
 */
void shift_writeAll(int level);
