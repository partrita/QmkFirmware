/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

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

#define EE_HANDS

#pragma once

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define RETRO_TAPPING

// combokey
#define COMBO_COUNT 1 // number of combo
#define COMBO_TERM 40 // timeout period for combos to 40ms.
#define DYNAMIC_TAPPING_TERM_INCREMENT 10

// Configuring mouse keys
// Setting MOUSEKEY_DELAY too low makes the cursor unresponsive. Setting it too high makes small movements difficult.
// For smoother cursor movements, lower the value of MOUSEKEY_INTERVAL. If the refresh rate of your display is 60Hz, you could set it to 16 (1/60). As this raises the cursor speed significantly, you may want to lower MOUSEKEY_MAX_SPEED.
// Setting MOUSEKEY_TIME_TO_MAX or MOUSEKEY_WHEEL_TIME_TO_MAX to 0 will disable acceleration for the cursor or scrolling respectively. This way you can make one of them constant while keeping the other accelerated, which is not possible in constant speed mode.
// Setting MOUSEKEY_WHEEL_INTERVAL too low will make scrolling too fast. Setting it too high will make scrolling too slow when the wheel key is held down.

// Accelerated mode
// #define MOUSEKEY_DELAY 10 // Delay between pressing a movement key and cursor movement
// #define MOUSEKEY_INTERVAL 20 // Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA 8 // Step size
// #define MOUSEKEY_MAX_SPEED 10 // Maximum cursor speed at which acceleration stops
// #define MOUSEKEY_TIME_TO_MAX 30 // Time until maximum cursor speed is reached
// #define MOUSEKEY_WHEEL_DELAY 10 // Delay between pressing a wheel key and wheel movement
// #define MOUSEKEY_WHEEL_INTERVAL 80 // Time between wheel movements
// #define MOUSEKEY_WHEEL_MAX_SPEED 8 // Maximum number of scroll steps per scroll action
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time until maximum scroll speed is reached

// Kinetic Mode
// The kinetic mode uses a quadratic curve on the cursor speed which allows precise movements at the beginning and allows to cover large distances by increasing cursor speed quickly thereafter.
// #define MK_KINETIC_SPEED // Enable kinetic mode
// #define MOUSEKEY_DELAY 5 // Delay between pressing a movement key and cursor movement
// #define MOUSEKEY_INTERVAL 10 // Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA 16 // Step size for accelerating from initial to base speed
// #define MOUSEKEY_INITIAL_SPEED 100 // Initial speed of the cursor in pixel per second
// #define MOUSEKEY_BASE_SPEED 5000 //	Maximum cursor speed at which acceleration stops
// #define MOUSEKEY_DECELERATED_SPEED 400 // Decelerated cursor speed
// #define MOUSEKEY_ACCELERATED_SPEED 3000 // Accelerated cursor speed
// #define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16 // Initial number of movements of the mouse wheel
// #define MOUSEKEY_WHEEL_BASE_MOVEMENTS 32 // Maximum number of movements at which acceleration stops
// #define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 // Accelerated wheel movements
// #define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8 // Decelerated wheel movements

// Tips:
// The smoothness of the cursor movement depends on the MOUSEKEY_INTERVAL setting. The shorter the interval is set the smoother the movement will be. Setting the value too low makes the cursor unresponsive. Lower settings are possible if the micro processor is fast enough. For example: At an interval of 8 milliseconds, 125 movements per second will be initiated. With a base speed of 1000 each movement will move the cursor by 8 pixels.
// Mouse wheel movements are implemented differently from cursor movements. While it's okay for the cursor to move multiple pixels at once for the mouse wheel this would lead to jerky movements. Instead, the mouse wheel operates at step size 2. Setting mouse wheel speed is done by adjusting the number of wheel movements per second.

// Combined mode
// This mode functions like Accelerated mode, however, you can hold KC_ACL0, KC_ACL1 and KC_ACL2 to momentarily (while held) set the cursor and scroll speeds to constant speeds. When no acceleration keys are held, this mode is identical to Accelerated mode, and can be modified using all of the relevant settings.
// : This acceleration sets your cursor to the slowest possible speed. This is useful for very small and detailed movements of the cursor.
// KC_ACL1: This acceleration sets your cursor to half the maximum (user defined) speed.
// KC_ACL2: This acceleration sets your cursor to the maximum (computer defined) speed. This is useful for moving the cursor large distances without much accuracy.

#define MK_COMBINED
#define MOUSEKEY_DELAY 10 // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 16 // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 8 // Step size
#define MOUSEKEY_MAX_SPEED 8 // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 30 // Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY 10 // Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL 80 // Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED 8 // Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time until maximum scroll speed is reached