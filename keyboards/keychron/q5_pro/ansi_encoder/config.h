/* Copyright 2023 ~ 2025 @ Keychron (https://www.keychron.com)
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

#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix Driver Configuration */
#    define SNLED27351_I2C_ADDRESS_1 SNLED27351_I2C_ADDRESS_VDDIO
#    define SNLED27351_I2C_ADDRESS_2 SNLED27351_I2C_ADDRESS_GND

/* RGB Matrix Configuration */
#    define DRIVER_1_LED_TOTAL 55
#    define DRIVER_2_LED_TOTAL 46
#    define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

/* Set to infinit, which is use in USB mode by default */
#    define RGB_MATRIX_TIMEOUT RGB_MATRIX_TIMEOUT_INFINITE

/* Allow to shutdown driver to save power */
#    define RGB_MATRIX_DRIVER_SHUTDOWN_ENABLE
#    define RGB_MATRIX_DRIVER_LOAD_ENABLE

/* Turn off backllit if brightness value is low */
#    define RGB_MATRIX_BRIGHTNESS_TURN_OFF_VAL 48

/* Indication led index */
#    define NUM_LOCK_INDEX 32
#    define CAPS_LOCK_INDEX 55
#    define LOW_BAT_IND_INDEX 92

#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_KEYPRESSES

/* Set LED driver current */
#    define SNLED27351_CURRENT_TUNE \
        { 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30 }
#endif
