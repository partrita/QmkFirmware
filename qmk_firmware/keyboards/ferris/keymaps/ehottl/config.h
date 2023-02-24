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
// #define TAPPING_TERM 200
#define TAPPING_TERM 180
#define RETRO_TAPPING


// mouse key
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY 5
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL 16
// #undef MOUSEKEY_MOVE_DELTA
// #define MOUSEKEY_MOVE_DELTA 1
// #undef MOUSEKEY_INITIAL_SPEED 
// #define MOUSEKEY_INITIAL_SPEED 1
// #undef MOUSEKEY_DECELERATED_SPEED
// #define MOUSEKEY_DECELERATED_SPEED 12
// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED 22
// #define USB_SUSPEND_WAKEUP_DELAY 0
// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 83
// #undef MOUSEKEY_WHEEL_MAX_SPEED
// #define MOUSEKEY_WHEEL_MAX_SPEED 3

// Enable Inertia mode
#undef MOUSEKEY_INERTIA	
// Delay between pressing a movement key and cursor movement
#define MOUSEKEY_DELAY	150	
// Time between cursor movements in milliseconds (16 = 60fps)
#define MOUSEKEY_INTERVAL	16	
// Maximum cursor speed at which acceleration stops
#define MOUSEKEY_MAX_SPEED	32	
// Number of frames until maximum cursor speed is reached
#define MOUSEKEY_TIME_TO_MAX	32	
// How quickly the cursor stops after releasing a key
#define MOUSEKEY_FRICTION	24	
// How much to move on first frame (1 strongly recommended)
#define MOUSEKEY_MOVE_DELTA	1	

/*
Tips:
Set MOUSEKEY_DELAY to roughly the same value as your host computer's key repeat delay, in ms. Recommended values are 100 to 300.
Set MOUSEKEY_INTERVAL to a value of 1000 / your monitor's FPS. For 60 FPS, 1000/60 = 16.
Set MOUSEKEY_MAX_SPEED based on your screen resolution and refresh rate, like Width / FPS. For example, 1920 pixels / 60 FPS = 32 pixels per frame.
Set MOUSEKEY_TIME_TO_MAX to a value of approximately FPS / 2, to make it reach full speed in half a second (or so).
Set MOUSEKEY_FRICTION to something between 1 and 255. Lower makes the cursor glide longer. Values from 8 to 40 are the most effective.
Keep MOUSEKEY_MOVE_DELTA at 1. This allows precise movements before the gliding effect starts.
Mouse wheel options are the same as the default accelerated mode, and do not use inertia.
*/

// combokey
#define COMBO_COUNT 1 // number of combo
#define COMBO_TERM 40 // timeout period for combos to 40ms.
#define DYNAMIC_TAPPING_TERM_INCREMENT 10