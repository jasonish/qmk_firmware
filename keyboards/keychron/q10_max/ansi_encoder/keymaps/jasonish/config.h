/* Copyright 2026 @ jasonish
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 */

#pragma once

/* 2026 home-row-mod setup: Chordal Hold + Flow Tap with conservative holds. */
#define TAPPING_TERM 200
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150

/* Default RGB Matrix startup: solid white at 50% brightness. */
#define RGB_MATRIX_DEFAULT_ON true
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL (RGB_MATRIX_MAXIMUM_BRIGHTNESS / 2)
