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

/*
 * ===========================================================================
 * RGB MATRIX LED CONFIGURATION
 * ===========================================================================
 *
 * This configuration maps each of the 34 WS2812 LEDs to their physical
 * position on the numpad keyboard.
 *
 * LED chain order (0-indexed):
 * 0-20: Per-key LEDs (Plus, Enter, Dot, 3, 2, 0, 1, 4, 5, 6, 9, 8, 7,
 *                      NumLock, Slash, Asterisk, Minus, M4, M3, M2, M1)
 * 21-32: Underglow LEDs (UNDER1-UNDER12)
 * 33: Status LED (LED22, under NumLock)
 */

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        /* Matrix to LED mapping (6 rows × 4 cols) */
        /* NO_LED (255) means no LED at that position */
        /* LED chain: 0-20 per-key, 21-32 underglow, 33 status */

        /* Row 0: M1, M2, M3, M4 */
        {  20,  19,  18,  17 },
        /* Row 1: NumLock, Slash, Asterisk, Minus */
        {  13,  14,  15,  16 },
        /* Row 2: 7, 8, 9 (no key in col 3) */
        {  12,  11,  10, NO_LED },
        /* Row 3: 4, 5, 6 (no key in col 3) */
        {   7,   8,   9,      0 },
        /* Row 4: 1, 2, 3 (no key in col 3) */
        {   6,   4,   3, NO_LED },
        /* Row 5: 0 (2u), Dot, Enter/Plus (2u tall, shares LED chain with row 3) */
        {   5, NO_LED,   2,   1 }
    },
    {
        /* LED physical positions (x, y) in 0-255 grid */
        /* MUST be in LED chain order - array index = LED number */

        /* Per-key LEDs (0-20) */
        { 246, 120 }, /*  0: LED1  (Plus) */
        { 246, 216 }, /*  1: LED2  (Enter) */
        { 160, 252 }, /*  2: LED3  (Dot) */
        { 160, 204 }, /*  3: LED4  (3) */
        {  91, 204 }, /*  4: LED5  (2) */
        {  56, 252 }, /*  5: LED6  (0) */
        {  22, 204 }, /*  6: LED7  (1) */
        {  22, 156 }, /*  7: LED8  (4) */
        {  91, 156 }, /*  8: LED9  (5) */
        { 160, 156 }, /*  9: LED10 (6) */
        { 160, 108 }, /* 10: LED11 (9) */
        {  91, 108 }, /* 11: LED12 (8) */
        {  22, 108 }, /* 12: LED13 (7) */
        {   9,  60 }, /* 13: LED14 (NumLock) */
        {  91,  60 }, /* 14: LED15 (Slash) */
        { 160,  60 }, /* 15: LED16 (Asterisk) */
        { 229,  60 }, /* 16: LED17 (Minus) */
        { 229,   0 }, /* 17: LED18 (M4) */
        { 160,   0 }, /* 18: LED19 (M3) */
        {  91,   0 }, /* 19: LED20 (M2) */
        {  22,   0 }, /* 20: LED21 (M1) */

        /* Underglow LEDs (21-32) */
        {   0,  18 }, /* 21: UNDER1 */
        { 127,  18 }, /* 22: UNDER2 */
        { 255,  18 }, /* 23: UNDER3 */
        { 255,  75 }, /* 24: UNDER4 */
        { 239, 154 }, /* 25: UNDER5 */
        { 239, 194 }, /* 26: UNDER6 */
        { 239, 254 }, /* 27: UNDER7 */
        { 127, 255 }, /* 28: UNDER8 */
        {  10, 255 }, /* 29: UNDER9 */
        {   0, 174 }, /* 30: UNDER10 */
        {   0, 126 }, /* 31: UNDER11 */
        {   0,  79 }, /* 32: UNDER12 */

        /* Status LED (33) */
        {  36,  60 }  /* 33: LED22 (STATUS, under NumLock) */
    },
    {
        /* LED flags - what type of LED each one is */
        /* LED_FLAG_KEYLIGHT (0x04) for per-key LEDs */
        /* LED_FLAG_UNDERGLOW (0x02) for underglow LEDs */
        /* LED_FLAG_INDICATOR (0x08) for status LED */
        /* MUST be in LED chain order - array index = LED number */

        /* Per-key LEDs (0-20) */
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,

        /* Underglow LEDs (21-32) */
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

        /* Status LED (33) */
        8
    }
};

/*
 * ===========================================================================
 * STATUS LED CUSTOM BEHAVIOR
 * ===========================================================================
 * Status LED (LED 33, under NumLock) behavior:
 * - Layer 0: OFF (unless NumLock is ON)
 * - NumLock ON: Green channel
 * - Layer 1 (FN key held): Red channel
 * - Layer 2 (TG(2) toggle): Blue channel
 * - Layer 3 (FN key held from Layer 2): Red channel
 */

/* Custom RGB Matrix indicator control */
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    /* Status LED behavior */
    uint8_t layer = get_highest_layer(layer_state);
    bool numlock_on = host_keyboard_led_state().num_lock;
    uint8_t brightness = WK21_STATUS_LED_BRIGHTNESS;

    if (layer == 0 && !numlock_on) {
        /* Layer 0, no NumLock: OFF */
        rgb_matrix_set_color(WK21_STATUS_LED_INDEX, 0, 0, 0);
    } else if (numlock_on && layer == 0) {
        /* NumLock ON on Layer 0: Green */
        rgb_matrix_set_color(WK21_STATUS_LED_INDEX, 0, brightness, 0);
    } else if (layer == 1) {
        /* Layer 1 (FN key): Red */
        rgb_matrix_set_color(WK21_STATUS_LED_INDEX, brightness, 0, 0);
    } else if (layer == 2 && !numlock_on) {
        /* Layer 2 (toggle): Blue */
        rgb_matrix_set_color(WK21_STATUS_LED_INDEX, 0, 0, brightness);
    } else if (layer == 2 && numlock_on) {
        /* Layer 2 with NumLock: Blue + Green = Cyan */
        rgb_matrix_set_color(WK21_STATUS_LED_INDEX, 0, brightness, brightness);
    } else if (layer == 3) {
        /* Layer 3 (FN from Layer 2): Red */
        rgb_matrix_set_color(WK21_STATUS_LED_INDEX, brightness, 0, 0);
    }

    return true;
}

#endif // RGB_MATRIX_ENABLE
