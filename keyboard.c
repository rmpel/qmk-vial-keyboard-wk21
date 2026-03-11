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

        /*  0: UP     */ { 217,  55 },
        /*  1: RGHT   */ { 230,  68 },
        /*  2: DOWN   */ { 217,  68 },
        /*  3: LEFT   */ { 204,  68 },
        /*  4: RCTL   */ { 186,  68 },
        /*  5: FN     */ { 170,  68 },
        /*  6: RGUI   */ { 154,  68 },
        /*  7: RALT   */ { 138,  68 },
        /*  8: SPC    */ {  90,  68 },
        /*  9: LALT   */ {  40,  68 },
        /* 10: LGUI   */ {  24,  68 },
        /* 11: LCTL   */ {   8,  68 },
        /* 12: LSFT   */ {  15,  55 },
        /* 13: Z      */ {  35,  55 },
        /* 14: X      */ {  48,  55 },
        /* 15: C      */ {  61,  55 },
        /* 16: V      */ {  74,  55 },
        /* 17: B      */ {  87,  55 },
        /* 18: N      */ { 100,  55 },
        /* 19: M      */ { 113,  55 },
        /* 20: ,      */ { 126,  55 },
        /* 21: .      */ { 139,  55 },
        /* 22: /      */ { 152,  55 },
        /* 23: RSFT   */ { 177,  55 },
        /* 24: ENTER  */ { 181,  42 },
        /* 25: '      */ { 159,  42 },
        /* 26: ;      */ { 146,  42 },
        /* 27: L      */ { 133,  42 },
        /* 28: K      */ { 120,  42 },
        /* 29: J      */ { 107,  42 },
        /* 30: H      */ {  94,  42 },
        /* 31: G      */ {  81,  42 },
        /* 32: F      */ {  68,  42 },
        /* 33: D      */ {  55,  42 },
        /* 34: S      */ {  42,  42 },
        /* 35: A      */ {  29,  42 },
        /* 36: CAPS   */ {   5,  42 },
        /* 37: TAB    */ {  10,  29 },
        /* 38: Q      */ {  25,  29 },
        /* 39: W      */ {  38,  29 },
        /* 40: E      */ {  51,  29 },
        /* 41: R      */ {  64,  29 },
        /* 42: T      */ {  77,  29 },
        /* 43: Y      */ {  90,  29 },
        /* 44: U      */ { 103,  29 },
        /* 45: I      */ { 116,  29 },
        /* 46: O      */ { 129,  29 },
        /* 47: P      */ { 142,  29 },
        /* 48: [      */ { 155,  29 },
        /* 49: ]      */ { 168,  29 },
        /* 50: \      */ { 185,  29 },
        /* 51: DEL    */ { 204,  29 },
        /* 52: END    */ { 217,  29 },
        /* 53: PGDN   */ { 230,  29 },
        /* 54: PGUP   */ { 230,  16 },
        /* 55: HOME   */ { 217,  16 },
        /* 56: INS    */ { 204,  16 },
        /* 57: BSPC   */ { 182,  16 },
        /* 58: =      */ { 162,  16 },
        /* 59: -      */ { 149,  16 },
        /* 60: 0      */ { 136,  16 },
        /* 61: 9      */ { 123,  16 },
        /* 62: 8      */ { 110,  16 },
        /* 63: 7      */ {  97,  16 },
        /* 64: 6      */ {  84,  16 },
        /* 65: 5      */ {  71,  16 },
        /* 66: 4      */ {  58,  16 },
        /* 67: 3      */ {  45,  16 },
        /* 68: 2      */ {  32,  16 },
        /* 69: 1      */ {  19,  16 },
        /* 70: `      */ {   6,  16 },
        /* 71: ESC    */ {   6,   0 },
        /* 72: F1     */ {  32,   0 },
        /* 73: F2     */ {  45,   0 },
        /* 74: F3     */ {  58,   0 },
        /* 75: F4     */ {  71,   0 },
        /* 76: F5     */ {  90,   0 },
        /* 77: F6     */ { 103,   0 },
        /* 78: F7     */ { 116,   0 },
        /* 79: F8     */ { 129,   0 },
        /* 80: F9     */ { 149,   0 },
        /* 81: F10    */ { 162,   0 },
        /* 82: F11    */ { 175,   0 },
        /* 83: F12    */ { 188,   0 },
        /* 84: PSCR   */ { 204,   0 },
        /* 85: SCLK   */ { 217,   0 },
        /* 86: PAUS   */ { 230,   0 },

        /* Underglow LEDs 87-110 (24 LEDs around perimeter) */
        /* CORRECTED positions based on physical PCB measurements */
        /* Scale: 1.4654mm per firmware unit (13 units = 1u = 19.05mm) */
        /* Verified from bottom view of PCB */
        /* Right edge (top to bottom) - LED chain starts here */
        /* 87 */ { 219,   3 },  /* LED_00: Right edge, top */
        /* 88 */ { 219,  17 },  /* LED_01: Right edge */
        /* 89 */ { 219,  31 },  /* LED_02: Right edge */
        /* 90 */ { 219,  45 },  /* LED_03: Right edge */
        /* 91 */ { 219,  58 },  /* LED_04: Right edge, bottom */
        /* Bottom edge (right to left) */
        /* 92 */ { 195,  58 },  /* LED_05: Bottom edge */
        /* 93 */ { 167,  58 },  /* LED_06: Bottom edge */
        /* 94 */ { 140,  58 },  /* LED_07: Bottom edge */
        /* 95 */ { 113,  58 },  /* LED_08: Bottom edge */
        /* 96 */ {  87,  58 },  /* LED_09: Bottom edge */
        /* 97 */ {  61,  58 },  /* LED_10: Bottom edge */
        /* 98 */ {  35,  58 },  /* LED_11: Bottom edge */
        /* 99 */ {   9,  58 },  /* LED_12: Bottom left corner */
        /* Left edge (bottom to top) */
        /*100 */ {   9,  45 },  /* LED_13: Left edge */
        /*101 */ {   9,  31 },  /* LED_14: Left edge */
        /*102 */ {   9,  17 },  /* LED_15: Left edge */
        /*103 */ {   9,   3 },  /* LED_16: Left edge, top */
        /* Top edge (left to right) */
        /*104 */ {  35,   3 },  /* LED_17: Top edge */
        /*105 */ {  61,   3 },  /* LED_18: Top edge */
        /*106 */ {  87,   3 },  /* LED_19: Top edge */
        /*107 */ { 113,   3 },  /* LED_20: Top edge */
        /*108 */ { 140,   3 },  /* LED_21: Top edge */
        /*109 */ { 167,   3 },  /* LED_22: Top edge */
        /*110 */ { 195,   3 },  /* LED_23: Top edge, near right */

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

/* ===========================================================================
 * LED FADE STATE TRACKING
 * ===========================================================================
 * Track layer change timing for fade effect:
 * - 0-5 seconds: full brightness
 * - 5-10 seconds: fade from full to 0
 * - >10 seconds: stay off until layer change
 */

static uint32_t layer_change_timer = 0;

/* Reset timer when layer changes */
layer_state_t layer_state_set_kb(layer_state_t state) {
    layer_change_timer = timer_read32();
    return layer_state_set_user(state);
}

/* Calculate fade brightness based on elapsed time
 * Returns brightness value 0-255
 * time_ms: elapsed time since layer change in milliseconds
 * max_brightness: maximum brightness value (0-255)
 */
static uint8_t calculate_fade_brightness(uint32_t time_ms, uint8_t max_brightness) {
    if (time_ms < WK87_MODE_STATUS_DURATION) {
        // 0-5 seconds: full brightness
        return max_brightness;
    } else if (time_ms < WK87_MODE_STATUS_DURATION + WK87_MODE_STATUS_FADE_DURATION) {
        // 5-10 seconds: fade from max to 0
        uint32_t fade_time = time_ms - WK87_MODE_STATUS_DURATION;  // 0-5000ms
        uint32_t brightness = max_brightness * (WK87_MODE_STATUS_FADE_DURATION - fade_time) / WK87_MODE_STATUS_FADE_DURATION;
        return (uint8_t)brightness;
    } else {
        // >10 seconds: off
        return 0;
    }
}

#ifdef WK87_STATUS_VARIANT

/* Custom RGB Matrix indicator control */
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    uint8_t layer_led = RGB_MATRIX_CAPS_LOCK_INDEX;
    uint8_t caps_led = RGB_MATRIX_LAYER_INDEX;
    uint8_t layer = get_highest_layer(layer_state);
    if ( layer > 1 ) {
        layer_led = RGB_MATRIX_LAYER_INDEX;
        caps_led = RGB_MATRIX_CAPS_LOCK_INDEX;
    }

    // Layer led goes white with fade on base layer (0 or 2), blue no fade on base layer 1 (1 or 3).
    // Caps lock led goes red 20% when caps lock is on, off otherwise.

    /* Caps Lock indicator - unchanged */
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(caps_led, WK87_LAYER_STATUS_BRIGHTNESS_LEVEL, 0, 0);  // Red at configured brightness
    } else {
        rgb_matrix_set_color(caps_led, 0, 0, 0);    // Off
    }

    /* Layer indicator with fade effect for layers 0 and 2 only */
    uint32_t elapsed = timer_elapsed32(layer_change_timer);
    uint8_t fade_brightness;

    switch(layer & 0x01) {
        case 0:
            // Layer 0/2: White with fade
            fade_brightness = calculate_fade_brightness(elapsed, WK87_MODE_STATUS_BRIGHTNESS_LEVEL);
            rgb_matrix_set_color(layer_led, fade_brightness, fade_brightness, fade_brightness);
            break;
        case 1:
            // Layer 1/3: Blue, no fade
            rgb_matrix_set_color(layer_led, 0, 0, WK87_LAYER_STATUS_BRIGHTNESS_LEVEL);
            break;
    }

    return true;
}

#else

/* Custom RGB Matrix indicator control */
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    /* Caps Lock indicator - unchanged */
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(RGB_MATRIX_CAPS_LOCK_INDEX, WK87_MODE_STATUS_BRIGHTNESS_LEVEL, 0, 0);  // Red at configured brightness
    } else {
        rgb_matrix_set_color(RGB_MATRIX_CAPS_LOCK_INDEX, 0, 0, 0);    // Off
    }

    /* Layer indicator with fade effect for layers 0 and 2 */
    uint8_t layer = get_highest_layer(layer_state);
    uint32_t elapsed = timer_elapsed32(layer_change_timer);
    uint8_t fade_brightness;

    switch(layer) {
        case 0:
            // Layer 0: White with fade
            fade_brightness = calculate_fade_brightness(elapsed, WK87_MODE_STATUS_BRIGHTNESS_LEVEL);
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, fade_brightness, fade_brightness, fade_brightness);
            break;
        case 1:
            // Layer 1: Blue (no fade)
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, 0, 0, WK87_LAYER_STATUS_BRIGHTNESS_LEVEL);
            break;
        case 2:
            // Layer 2: Green with fade
            fade_brightness = calculate_fade_brightness(elapsed, WK87_LAYER_STATUS_BRIGHTNESS_LEVEL);
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, 0, fade_brightness, 0);
            break;
        case 3:
            // Layer 3: Yellow (no fade)
            rgb_matrix_set_color(RGB_MATRIX_LAYER_INDEX, WK87_LAYER_STATUS_BRIGHTNESS_LEVEL, WK87_LAYER_STATUS_BRIGHTNESS_LEVEL, 0);
            break;
    }

    return true;
}

#endif // WK87_STATUS_VARIANT

#endif // RGB_MATRIX_ENABLE
