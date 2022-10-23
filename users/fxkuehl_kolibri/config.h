/*
Copyright 2022 Felix Kuehling <felix.kuehling@gmail.com>

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

#define TAPPING_TERM 175

// Immediate hold on other key press for thumb mod-taps (except space)
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Permissive hold for Space and finger mod-taps to allow fast combos
#define PERMISSIVE_HOLD_PER_KEY
// Mod-taps and layer-taps behave the same way
#define IGNORE_MOD_TAP_INTERRUPT

//#define MK_KINETIC_SPEED
#ifdef MK_KINETIC_SPEED
#   define MOUSEKEY_INTERVAL 16
#   define MOUSEKEY_MOVE_DELTA 2
#   define MOUSEKEY_INITIAL_SPEED 30
#   define MOUSEKEY_BASE_SPEED 1200
#else
#   define MOUSEKEY_INTERVAL 16
#   define MOUSEKEY_MOVE_DELTA 1
#   define MOUSEKEY_MAX_SPEED 40
#   define MOUSEKEY_TIME_TO_MAX 80
#endif

// Mapping the Kolibri layout to Iris
// Define one of the following macros to get a 34 or 36-key layout
// right- or left-handed:
//
// LAYOUT_KOLIBRI_34
// LAYOUT_KOLIBRI_36
// LAYOUT_KOLIBRI_LEFTY_34
// LAYOUT_KOLIBRI_LEFTY_36

// KOLIBRI_BASE_LAYOUT defines the base layer layout for the 10x3 typing area.
// You can define your own or use one of the pre-defined ones:
// * KOLIBRI_BASE_QWERTY
// * KOLIBRI_BASE_DVORAK
// * KOLIBRI_BASE_COLEMAK
// * KOLIBRI_BASE_COLEMAK_DH
//
// If nothing is defined, the default is Colemak-DH

// Options
//#define KOLIBRI_ONE_HANDED_NAV
//#define KOLIBRI_NUMPAD
