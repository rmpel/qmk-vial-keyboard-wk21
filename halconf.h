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
 * ChibiOS HAL CONFIGURATION
 * ===========================================================================
 *
 * This file configures which ChibiOS Hardware Abstraction Layer (HAL)
 * drivers are enabled.
 *
 * WS2812 uses bitbang driver (no PWM needed)
 */

#pragma once

/* No additional HAL drivers needed for bitbang WS2812 driver */

#include_next <halconf.h>
