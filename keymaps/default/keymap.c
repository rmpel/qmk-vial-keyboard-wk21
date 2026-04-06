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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Numpad Layer
     * ┌───┬───┬───┬───┐
     * │M1 │M2 │M3 │M4 │  M4 = FN (MO(1))
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───────┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_numpad(
        KC_F13,  KC_F14,  KC_F15,  MO(1),
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /* Layer 1: Function Layer (M4/FN key held from Layer 0)
     * ┌───┬───┬───┬───┐
     * │RST│___│TG2│___│  M1 = QK_BOOT, M3 = TG(2), M4 = FN passthrough
     * ├───┼───┼───┼───┤
     * │___│___│___│___│
     * ├───┼───┼───┼───┤
     * │RTg│RMd│RH+│   │
     * ├───┼───┼───┤___│
     * │RV+│RV-│RS+│   │
     * ├───┼───┼───┼───┤
     * │RS+│RS-│RS-│   │
     * ├───────┼───┤___│
     * │  ___  │___│   │
     * └───────┴───┴───┘
     */
    [1] = LAYOUT_numpad(
        QK_BOOT, _______, TG(2),   _______,
        _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI,
        RGB_VAI, RGB_VAD, RGB_SPI, _______,
        RGB_SAI, RGB_SAD, RGB_SPD,
        _______,          _______, _______
    ),

    /* Layer 2: Mouse Keys Layer (toggled via TG(2) from Layer 1)
     * ┌───┬───┬───┬───┐
     * │___│___│___│MO3│  M4 = MO(3) for function access
     * ├───┼───┼───┼───┤
     * │___│___│___│___│
     * ├───┼───┼───┼───┤
     * │Ma1│MsU│Ma2│   │  Mouse buttons and movement
     * ├───┼───┼───┤___│
     * │MsL│MsD│MsR│   │
     * ├───┼───┼───┼───┤
     * │WhU│WhD│WhL│   │  Wheel movement
     * ├───────┼───┤WhR│
     * │  Ma3  │___│   │
     * └───────┴───┴───┘
     */
    [2] = LAYOUT_numpad(
        _______, _______, _______, MO(3),
        _______, _______, _______, _______,
        KC_BTN1, KC_MS_U, KC_BTN2,
        KC_MS_L, KC_MS_D, KC_MS_R, _______,
        KC_WH_U, KC_WH_D, KC_WH_L,
        KC_BTN3,          _______, KC_WH_R
    ),

    /* Layer 3: Function Layer from Layer 2 (M4/FN key held from Layer 2)
     * ┌───┬───┬───┬───┐
     * │RST│___│TG2│___│  M1 = QK_BOOT, M3 = TG(2), M4 = FN passthrough
     * ├───┼───┼───┼───┤
     * │___│___│___│___│
     * ├───┼───┼───┼───┤
     * │RTg│RMd│RH+│   │  Same RGB controls as Layer 1
     * ├───┼───┼───┤___│
     * │RV+│RV-│RS+│   │
     * ├───┼───┼───┼───┤
     * │RS+│RS-│RS-│   │
     * ├───────┼───┤___│
     * │  ___  │___│   │
     * └───────┴───┴───┘
     */
    [3] = LAYOUT_numpad(
        QK_BOOT, _______, TG(2),   _______,
        _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI,
        RGB_VAI, RGB_VAD, RGB_SPI, _______,
        RGB_SAI, RGB_SAD, RGB_SPD,
        _______,          _______, _______
    )
};
