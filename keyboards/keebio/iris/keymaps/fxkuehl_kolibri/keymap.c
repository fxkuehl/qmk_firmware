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

#include QMK_KEYBOARD_H
#include "fxkuehl_kolibri.h"

// Keymap is defined in fxkuehl_kolibri.c

#ifdef RGBLIGHT_ENABLE
// Lighting layers
#define CAPSLOCK_COLOR HSV_CYAN
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, CAPSLOCK_COLOR}, // Left hand, top right LED
    { 5, 2, CAPSLOCK_COLOR}, // Bottom center two LEDs
    {11, 1, CAPSLOCK_COLOR}  // Right hand, top left LED
);

#define FNLOCK_COLOR HSV_CYAN
const rgblight_segment_t PROGMEM my_navflock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 3, 1, FNLOCK_COLOR}, // Left hand, bottom left LED
    { 8, 1, FNLOCK_COLOR}  // Right hand, bottom right LED
);

#define LAYER_COLOR HSV_CHARTREUSE
const rgblight_segment_t PROGMEM my_num_sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, LAYER_COLOR}     // Left hand, top right LED
);
const rgblight_segment_t PROGMEM my_nav_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, LAYER_COLOR}     // Right hand, top left LED
);
#define CONTROL_COLOR HSV_ORANGE
const rgblight_segment_t PROGMEM my_control_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, CONTROL_COLOR},    // Left hand, top right LED
    {11, 1, CONTROL_COLOR}     // Right hand, top left LED
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_navflock_layer,
    my_num_sym_layer,
    my_nav_fn_layer,
    my_control_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, L_FN_LOCKED));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_SYM));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_FN));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_MACRO) || layer_state_cmp(state, L_MEDIA));
    return state;
}
#endif
