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

/*
 * ===========================================================================
 * STM32F411 MCU CONFIGURATION
 * ===========================================================================
 *
 * This file configures the STM32F411 microcontroller peripherals.
 *
 * WS2812 RGB LEDs use BITBANG driver (PB8 is not TIM1-capable)
 * No PWM/TIM configuration needed.
 */

#pragma once

#include_next <mcuconf.h>

/* No additional MCU configuration needed for bitbang WS2812 driver */
