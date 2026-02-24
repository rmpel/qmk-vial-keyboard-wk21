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
 * SHIFT REGISTER CONFIGURATION (74HC595)
 * ===========================================================================
 * The keyboard uses a 74HC595 shift register to expand column pins.
 * This allows controlling 8 columns using only 3 GPIO pins.
 *
 * TODO: Discover these pins by tracing PCB or testing
 * Typical pins to check: A0-A15, B0-B15, C13-C15
 */

/* Number of 74HC595 chips daisy-chained (1 chip = 8 outputs) */
#define SHR_SERIES_NUM 1

/* Shift register control pins - DISCOVERED */
#define SHR_CLOCK_PIN  A9   // 74HC595 pin 11 (SRCLK) → STM32 PA9
#define SHR_DATA_PIN   A8   // 74HC595 pin 14 (SER) → STM32 PA8
#define SHR_LATCH_PIN  C14  // 74HC595 pin 12 (RCLK) → STM32 PC14

/* Output Enable pin - tied to GND on this PCB (always enabled) */
// #define SHR_OE_PIN  - OE is hardwired to GND, no MCU control needed

/*
 * ===========================================================================
 * RGB MATRIX CONFIGURATION (WS2812)
 * ===========================================================================
 * The keyboard has addressable RGB LEDs for both per-key lighting and underglow.
 * Total: 87 per-key LEDs + underglow LEDs (count TBD)
 *
 * TODO: Verify WS2812 data pin by tracing from LED chain
 */

/* WS2812 Timing Configuration */
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB  // Color order for WS2812B
#define WS2812_TRST_US 200  // Reset time in microseconds

/* Using BITBANG driver since PB8 is not a TIM1-capable pin */
/* LED chain: Up Arrow → Right Arrow → Down Arrow → ... → Pause → LED0 (underglow) → LED1... */
/* No PWM configuration needed for bitbang driver */

/*
 * RGB Matrix Layout Configuration
 * TODO: Map physical LED positions to matrix positions
 * This will require identifying which LED corresponds to which key
 */

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

/* RGB Matrix Limits */
#define RGB_MATRIX_LED_COUNT 113  // 87 per-key + 24 underglow + 2 status LEDs

/* Status LEDs (face upward) */
#define RGB_MATRIX_CAPS_LOCK_INDEX 111   // LED for Caps Lock indicator
#define RGB_MATRIX_LAYER_INDEX 112        // LED for Layer indicator
// Disable underglow by splitting them off from the main.
// #define RGB_MATRIX_SPLIT { 87, 26 }

/* Scanning delay in microseconds to prevent aliasing */
#define WK87_SCAN_DELAY 1

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
 /*
    Without this, status led 1 is caps lock (red = on), led 2 is layer (off = default layer, blue = layer 1, green = layer 2, yellow = layer 3). Colors conficured in keyboard.c.
    With this, status led 1 indidates layer 0 (Mac mode), white for selection, blue for FN (the-layer+1) and led 2 is caps lock (red = on). For windows, it's the opposite; led 1 is the caps lock indicator and led 2 is the layer indicator.
 */
// #define WK87_STATUS_VARIANT
/* Brightness level for status LEDs (0-255), this controls a single color channel to combine into the colors stated above, is used for layer status */
#define WK87_LAYER_STATUS_BRIGHTNESS_LEVEL 80
/* Brightness level for status LEDs (0-255), this controls all three channels for the Mac/Win indication */
#define WK87_MODE_STATUS_BRIGHTNESS_LEVEL 80
#define WK87_MODE_STATUS_DURATION 5000
#define WK87_MODE_STATUS_FADE_DURATION 2000
