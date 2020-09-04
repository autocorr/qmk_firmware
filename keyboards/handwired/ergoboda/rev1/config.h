/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Brian Svoboda

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

// USB Device descriptor parameter
#define PRODUCT         Ergoboda
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    bsvoboda
#define DESCRIPTION     A split keyboard

// Key matrix size
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// Wiring of each half
#define MATRIX_COL_PINS { B6, B2, E6, D7, C6, D4 }
#define MATRIX_ROW_PINS { F7, B1, B3, B4 }

#define DIODE_DIRECTION COL2ROW

// Set to 0 if debouncing isn't needed
#define DEBOUNCE 5

// Mouse config options
#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY    0

// Communication options
#define MASTER_LEFT
#define USE_I2C

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE

// Enables This makes it easier for fast typists to use dual-function keys
#define PERMISSIVE_HOLD

// Enable link time optimizations to reduce binary size
#define LTO_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

// Disable debug print
//#define NO_DEBUG

// Disable print
//#define NO_PRINT

// Disable action features
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
