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
 * This configuration maps each of the 87 WS2812 LEDs to their physical
 * position on the keyboard. The LED chain goes:
 *   Up Arrow → Right Arrow → Down Arrow → ... → Pause → LED0 (underglow) → ...
 *
 * TODO: Map each LED to its actual matrix position for per-key effects
 * Currently using placeholder positions to allow firmware to build.
 */
#define WK87_STATUS_BRIGHTNESS_LEVEL 80

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        /* Matrix to LED mapping - maps each key position to its LED index */
        /* 8 rows × 12 columns */
        /* NO_LED (255) means no LED at that position */
        /* LED chain: UP(0) → RGHT(1) → ... → PAUS(86), underglow(87-110), status(111-112) */

        /* Row 0: [col 0-11] */
        /*  ESC      `       PGUP    END     LSFT    LCTL    PAUS    HOME    DEL     (empty) (empty) (empty) */
        {    71,    70,     54,    52,     12,    11,     86,    55,    51, NO_LED, NO_LED, NO_LED },

        /* Row 1: [col 0-11] */
        /*  F1       1       TAB     PGDN    Z       LGUI    SCLK    INS     \       ENTER   (empty) (empty) */
        {    72,    69,     37,    53,     13,    10,     85,    56,    50,    24, NO_LED, NO_LED },

        /* Row 2: [col 0-11] */
        /*  F2       2       Q       CAPS    X       LALT    PSCR    BSPC    ]       '       (empty) (empty) */
        {    73,    68,     38,    36,     14,     9,     84,    57,    49,    25, NO_LED, NO_LED },

        /* Row 3: [col 0-11] */
        /*  F3       3       W       A       C       SPC     F12     =       [       ;       (empty) (empty) */
        {    74,    67,     39,    35,     15,     8,     83,    58,    48,    26, NO_LED, NO_LED },

        /* Row 4: [col 0-11] */
        /*  F4       4       E       S       V       RALT    F11     -       P       L       RSFT    DOWN    */
        {    75,    66,     40,    34,     16,     7,     82,    59,    47,    27,    23,     2 },

        /* Row 5: [col 0-11] */
        /*  F5       5       R       D       B       RGUI    F10     0       O       K       /       RGHT    */
        {    76,    65,     41,    33,     17,     6,     81,    60,    46,    28,    22,     1 },

        /* Row 6: [col 0-11] */
        /*  F6       6       T       F       N       FN      F9      9       I       J       .       LEFT    */
        {    77,    64,     42,    32,     18,     5,     80,    61,    45,    29,    21,     3 },

        /* Row 7: [col 0-11] */
        /*  F7       7       Y       G       M       RCTL    F8      8       U       H       ,       (empty) */
        {    78,    63,     43,    31,     19,     4,     79,    62,    44,    30,    20, NO_LED }
    },
    {
        /* LED physical positions (x, y) in grid coordinates (0-224, 0-64) */
        /* MUST be in LED chain order - array index = LED number */
        /* LED chain: UP → RGHT → DOWN → ... → PAUS (0-86), then underglow (87-110), then status (111-112) */

        /*  0: UP     */ { 211,  51 },
        /*  1: RGHT   */ { 224,  64 },
        /*  2: DOWN   */ { 211,  64 },
        /*  3: LEFT   */ { 198,  64 },
        /*  4: RCTL   */ { 178,  64 },
        /*  5: FN     */ { 162,  64 },
        /*  6: RGUI   */ { 146,  64 },
        /*  7: RALT   */ { 130,  64 },
        /*  8: SPC    */ {  49,  64 },
        /*  9: LALT   */ {  32,  64 },
        /* 10: LGUI   */ {  16,  64 },
        /* 11: LCTL   */ {   0,  64 },
        /* 12: LSFT   */ {   0,  51 },
        /* 13: Z      */ {  29,  51 },
        /* 14: X      */ {  42,  51 },
        /* 15: C      */ {  55,  51 },
        /* 16: V      */ {  68,  51 },
        /* 17: B      */ {  81,  51 },
        /* 18: N      */ {  94,  51 },
        /* 19: M      */ { 107,  51 },
        /* 20: ,      */ { 120,  51 },
        /* 21: .      */ { 133,  51 },
        /* 22: /      */ { 146,  51 },
        /* 23: RSFT   */ { 159,  51 },
        /* 24: ENTER  */ { 166,  38 },
        /* 25: '      */ { 153,  38 },
        /* 26: ;      */ { 140,  38 },
        /* 27: L      */ { 127,  38 },
        /* 28: K      */ { 114,  38 },
        /* 29: J      */ { 101,  38 },
        /* 30: H      */ {  88,  38 },
        /* 31: G      */ {  75,  38 },
        /* 32: F      */ {  62,  38 },
        /* 33: D      */ {  49,  38 },
        /* 34: S      */ {  36,  38 },
        /* 35: A      */ {  23,  38 },
        /* 36: CAPS   */ {   0,  38 },
        /* 37: TAB    */ {   0,  26 },
        /* 38: Q      */ {  19,  26 },
        /* 39: W      */ {  32,  26 },
        /* 40: E      */ {  45,  26 },
        /* 41: R      */ {  58,  26 },
        /* 42: T      */ {  71,  26 },
        /* 43: Y      */ {  84,  26 },
        /* 44: U      */ {  97,  26 },
        /* 45: I      */ { 110,  26 },
        /* 46: O      */ { 123,  26 },
        /* 47: P      */ { 136,  26 },
        /* 48: [      */ { 149,  26 },
        /* 49: ]      */ { 162,  26 },
        /* 50: \      */ { 175,  26 },
        /* 51: DEL    */ { 198,  26 },
        /* 52: END    */ { 211,  26 },
        /* 53: PGDN   */ { 224,  26 },
        /* 54: PGUP   */ { 224,  13 },
        /* 55: HOME   */ { 211,  13 },
        /* 56: INS    */ { 198,  13 },
        /* 57: BSPC   */ { 169,  13 },
        /* 58: =      */ { 156,  13 },
        /* 59: -      */ { 143,  13 },
        /* 60: 0      */ { 130,  13 },
        /* 61: 9      */ { 117,  13 },
        /* 62: 8      */ { 104,  13 },
        /* 63: 7      */ {  91,  13 },
        /* 64: 6      */ {  78,  13 },
        /* 65: 5      */ {  65,  13 },
        /* 66: 4      */ {  52,  13 },
        /* 67: 3      */ {  39,  13 },
        /* 68: 2      */ {  26,  13 },
        /* 69: 1      */ {  13,  13 },
        /* 70: `      */ {   0,  13 },
        /* 71: ESC    */ {   0,   0 },
        /* 72: F1     */ {  26,   0 },
        /* 73: F2     */ {  39,   0 },
        /* 74: F3     */ {  52,   0 },
        /* 75: F4     */ {  65,   0 },
        /* 76: F5     */ {  84,   0 },
        /* 77: F6     */ {  97,   0 },
        /* 78: F7     */ { 110,   0 },
        /* 79: F8     */ { 123,   0 },
        /* 80: F9     */ { 143,   0 },
        /* 81: F10    */ { 156,   0 },
        /* 82: F11    */ { 169,   0 },
        /* 83: F12    */ { 182,   0 },
        /* 84: PSCR   */ { 198,   0 },
        /* 85: SCLK   */ { 211,   0 },
        /* 86: PAUS   */ { 224,   0 },

        /* Underglow LEDs 87-110 (24 LEDs around perimeter) */
        /* Approximate positions around keyboard edge */
        /* Top edge (left to right) */
        /* 87 */ {   0,   0 },
        /* 88 */ {  32,   0 },
        /* 89 */ {  64,   0 },
        /* 90 */ {  96,   0 },
        /* 91 */ { 128,   0 },
        /* 92 */ { 160,   0 },
        /* 93 */ { 192,   0 },
        /* 94 */ { 224,   0 },
        /* Right edge (top to bottom) */
        /* 95 */ { 224,  16 },
        /* 96 */ { 224,  32 },
        /* 97 */ { 224,  48 },
        /* 98 */ { 224,  64 },
        /* Bottom edge (right to left) */
        /* 99 */ { 192,  64 },
        /*100 */ { 160,  64 },
        /*101 */ { 128,  64 },
        /*102 */ {  96,  64 },
        /*103 */ {  64,  64 },
        /*104 */ {  32,  64 },
        /*105 */ {   0,  64 },
        /* Left edge (bottom to top) */
        /*106 */ {   0,  48 },
        /*107 */ {   0,  32 },
        /*108 */ {   0,  16 },
        /* Fill remaining positions */
        /*109 */ { 112,  32 },
        /*110 */ { 112,  32 },

        /* Status LEDs 111-112 (2 LEDs facing upward for indicators) */
        /*111 */ {   0,   0 },  // Caps Lock indicator
        /*112 */ {   0,   0 }   // Layer indicator
    },
    {
        /* LED flags - what type of LED each one is */
        /* LED_FLAG_KEYLIGHT (0x04) for per-key LEDs */
        /* LED_FLAG_MODIFIER (0x01) for modifier keys */
        /* LED_FLAG_UNDERGLOW (0x02) for underglow LEDs */
        /* MUST be in LED chain order - array index = LED number */

        /*  0: UP     */ 4,
        /*  1: RGHT   */ 4,
        /*  2: DOWN   */ 4,
        /*  3: LEFT   */ 4,
        /*  4: RCTL   */ 1,  // Modifier
        /*  5: FN     */ 1,  // Modifier
        /*  6: RGUI   */ 1,  // Modifier
        /*  7: RALT   */ 1,  // Modifier
        /*  8: SPC    */ 4,
        /*  9: LALT   */ 1,  // Modifier
        /* 10: LGUI   */ 1,  // Modifier
        /* 11: LCTL   */ 1,  // Modifier
        /* 12: LSFT   */ 1,  // Modifier
        /* 13: Z      */ 4,
        /* 14: X      */ 4,
        /* 15: C      */ 4,
        /* 16: V      */ 4,
        /* 17: B      */ 4,
        /* 18: N      */ 4,
        /* 19: M      */ 4,
        /* 20: ,      */ 4,
        /* 21: .      */ 4,
        /* 22: /      */ 4,
        /* 23: RSFT   */ 1,  // Modifier
        /* 24: ENTER  */ 1,  // Modifier
        /* 25: '      */ 4,
        /* 26: ;      */ 4,
        /* 27: L      */ 4,
        /* 28: K      */ 4,
        /* 29: J      */ 4,
        /* 30: H      */ 4,
        /* 31: G      */ 4,
        /* 32: F      */ 4,
        /* 33: D      */ 4,
        /* 34: S      */ 4,
        /* 35: A      */ 4,
        /* 36: CAPS   */ 1,  // Modifier
        /* 37: TAB    */ 1,  // Modifier
        /* 38: Q      */ 4,
        /* 39: W      */ 4,
        /* 40: E      */ 4,
        /* 41: R      */ 4,
        /* 42: T      */ 4,
        /* 43: Y      */ 4,
        /* 44: U      */ 4,
        /* 45: I      */ 4,
        /* 46: O      */ 4,
        /* 47: P      */ 4,
        /* 48: [      */ 4,
        /* 49: ]      */ 4,
        /* 50: \      */ 4,
        /* 51: DEL    */ 4,
        /* 52: END    */ 4,
        /* 53: PGDN   */ 4,
        /* 54: PGUP   */ 4,
        /* 55: HOME   */ 4,
        /* 56: INS    */ 4,
        /* 57: BSPC   */ 4,
        /* 58: =      */ 4,
        /* 59: -      */ 4,
        /* 60: 0      */ 4,
        /* 61: 9      */ 4,
        /* 62: 8      */ 4,
        /* 63: 7      */ 4,
        /* 64: 6      */ 4,
        /* 65: 5      */ 4,
        /* 66: 4      */ 4,
        /* 67: 3      */ 4,
        /* 68: 2      */ 4,
        /* 69: 1      */ 4,
        /* 70: `      */ 4,
        /* 71: ESC    */ 4,
        /* 72: F1     */ 4,
        /* 73: F2     */ 4,
        /* 74: F3     */ 4,
        /* 75: F4     */ 4,
        /* 76: F5     */ 4,
        /* 77: F6     */ 4,
        /* 78: F7     */ 4,
        /* 79: F8     */ 4,
        /* 80: F9     */ 4,
        /* 81: F10    */ 4,
        /* 82: F11    */ 4,
        /* 83: F12    */ 4,
        /* 84: PSCR   */ 4,
        /* 85: SCLK   */ 4,
        /* 86: PAUS   */ 4,

        /* Underglow LEDs 87-110 (24 LEDs) */
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

        /* Status indicator LEDs 111-112 (2 LEDs) */
        8,  // Caps Lock indicator (LED_FLAG_INDICATOR)
        8   // Layer indicator (LED_FLAG_INDICATOR)
    }
};

/* Custom RGB Matrix indicator control */
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    /* Caps Lock indicator (LED 111) - 20% brightness (51/255) */
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(RGB_MATRIX_CAPS_LOCK_INDEX, WK87_STATUS_BRIGHTNESS_LEVEL, 0, 0);  // Red at configured brightness
    } else {
        rgb_matrix_set_color(RGB_MATRIX_CAPS_LOCK_INDEX, 0, 0, 0);    // Off
    }

    /* Layer indicator (LED 112) - 20% brightness (51/255) */
    uint8_t layer = get_highest_layer(layer_state);
    switch(layer) {
        case 0:
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, 0, 0, 0);  // Blue at configured brightness
            break;
        case 1:
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, 0, 0, WK87_STATUS_BRIGHTNESS_LEVEL);  // Blue at configured brightness
            break;
        case 2:
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, 0, WK87_STATUS_BRIGHTNESS_LEVEL, 0);  // Green at configured brightness
            break;
        case 3:
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, WK87_STATUS_BRIGHTNESS_LEVEL, WK87_STATUS_BRIGHTNESS_LEVEL, 0);  // Yellow at configured brightness
            break;
    }

    return true;
}

#endif // RGB_MATRIX_ENABLE
