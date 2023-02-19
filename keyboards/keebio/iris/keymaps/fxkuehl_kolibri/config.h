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

#define EE_HANDS

#define RGBLIGHT_LAYERS

// Mapping the Kolibri layout to Iris
// Define one of the following macros to get a 34 or 36-key layout
// right- or left-handed:
//
// LAYOUT_KOLIBRI_34
// LAYOUT_KOLIBRI_36
// LAYOUT_KOLIBRI_LEFTY_34
// LAYOUT_KOLIBRI_LEFTY_36
#if 0
#define LAYOUT_KOLIBRI_34(                                \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                       K33, K34, K35, K36)        LAYOUT( \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
        KC_NO,   K00,     K01,     K02,     K03,     K04,                                K05,     K06,     K07,     K08,     K09,     KC_NO, \
        KC_NO,   K10,     K11,     K12,     K13,     K14,                                K15,     K16,     K17,     K18,     K19,     KC_NO, \
        KC_NO,   K20,     K21,     K22,     K23,     K24,     KC_NO,            KC_NO,   K25,     K26,     K27,     K28,     K29,     KC_NO, \
                                            KC_NO,   K33,     K34,              K35,     K36,     KC_NO)
#else
#define LAYOUT_KOLIBRI_36(                                \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  K32, K33, K34, K35, K36, K37)   LAYOUT( \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
        KC_NO,   K00,     K01,     K02,     K03,     K04,                                K05,     K06,     K07,     K08,     K09,     KC_NO, \
        KC_NO,   K10,     K11,     K12,     K13,     K14,                                K15,     K16,     K17,     K18,     K19,     KC_NO, \
        KC_NO,   K20,     K21,     K22,     K23,     K24,     KC_NO,            KC_NO,   K25,     K26,     K27,     K28,     K29,     KC_NO, \
                                            K32,     K33,     K34,              K35,     K36,     K37)
#endif

// KOLIBRI_BASE_LAYOUT defines the base layer layout for the 10x3 typing area.
// You can define your own or use one of the pre-defined ones:
// * KOLIBRI_BASE_QWERTY
// * KOLIBRI_BASE_DVORAK
// * KOLIBRI_BASE_COLEMAK
// * KOLIBRI_BASE_COLEMAK_DH
//
// If nothing is defined, the default is Colemak-DH
#define KOLIBRI_BASE_LAYOUT KOLIBRI_BASE_COLEMAK_DH

// Options
#define KOLIBRI_ONE_HANDED_NAV
#define KOLIBRI_NUMPAD
