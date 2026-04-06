/* Copyright 2026 rmpel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed it and the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/*
 * ===========================================================================
 * RGB MATRIX CONFIGURATION (WS2812)
 * ===========================================================================
 * The keyboard has addressable RGB LEDs for per-key lighting, underglow, and status.
 * Total: 21 per-key LEDs + 12 underglow LEDs + 1 status LED = 34 total
 */

/* WS2812 Timing Configuration */
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB  // Color order for WS2812B
#define WS2812_TRST_US 200  // Reset time in microseconds

/* RGB Matrix Layout Configuration */
#define RGB_MATRIX_LED_COUNT 34  // 21 per-key + 12 underglow + 1 status

/* Status LED (chain position 33, under NumLock) */
#define WK21_STATUS_LED_INDEX 33

/* Enable RGB Matrix Effects */
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_STARLIGHT
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

/*
 * ===========================================================================
 * VIAL CONFIGURATION
 * ===========================================================================
 * Vial settings are in keymaps/vial/config.h
 */

/*
 * ===========================================================================
 * CUSTOM KEYCODES
 * ===========================================================================
 */

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_SIRI LALT(KC_SPC)

#define KC_LCKW LGUI(KC_L)
#define KC_LCKM LGUI(LCTL(KC_Q))

/**
 * ===========================================================================
 * OTHER CONFIGURATIONS
 * ===========================================================================
 */

/* Brightness level for status LED (0-255) */
#define WK21_STATUS_LED_BRIGHTNESS 80

/* Global RGB timeout (10 minutes) */
#define RGB_MATRIX_TIMEOUT 600000
