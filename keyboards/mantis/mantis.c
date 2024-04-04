// Copyright 2024 Felix Kuehling (@fxkuehl)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

// Cap indicators to the configured max brightness
#define RGB_SCALED(r, g, b) \
    (uint8_t)((uint16_t)(r) * RGB_MATRIX_MAXIMUM_BRIGHTNESS / 0xff), \
    (uint8_t)((uint16_t)(g) * RGB_MATRIX_MAXIMUM_BRIGHTNESS / 0xff), \
    (uint8_t)((uint16_t)(b) * RGB_MATRIX_MAXIMUM_BRIGHTNESS / 0xff)

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max))
        return false;

    const bool caps_lock = host_keyboard_led_state().caps_lock;
    const bool num_lock = host_keyboard_led_state().num_lock;
    const uint8_t layer = get_highest_layer(layer_state);

    if (!caps_lock && !layer)
        return false;

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t index = g_led_config.matrix_co[row][col];

            if (index < led_min || index >= led_max)
                continue;

            bool arrow = false, edit = false, num = false, numpad = false, kc_num = false;

            if (layer) {
                uint16_t kc = keymap_key_to_keycode(layer, (keypos_t){col,row});

                if (kc >= QK_MOD_TAP && kc <= QK_LAYER_TAP_MAX)
                    kc &= 0xff;

                if (kc >= KC_RIGHT && kc <= KC_UP)
                    arrow = true;
                else if (kc == KC_ESC  || kc == KC_INS ||
                         kc == KC_BSPC || kc == KC_DEL)
                    edit = true;
                else if (kc >= KC_1 && kc <= KC_0)
                    num = true;
                else if (kc == KC_NUM)
                    kc_num = true;
                else if (kc >= KC_KP_1 && kc <= KC_KP_0)
                    numpad = true;
            }

            if (arrow || edit)
                rgb_matrix_set_color(index, RGB_SCALED(0x80, 0x00, 0x04));
            else if (num)
                rgb_matrix_set_color(index, RGB_SCALED(0x20, 0x80, 0x00));
            else if ((numpad && num_lock) || kc_num)
                rgb_matrix_set_color(index, RGB_SCALED(0x00, 0x20, 0x80));
	    else if (numpad && !num_lock)
                rgb_matrix_set_color(index, RGB_SCALED(0x10, 0x00, 0x02));
            else if (caps_lock && (
                        row == 0 ||
                       (row == 3 && (col == 0 || col == 9))
                       )
                    )
                rgb_matrix_set_color(index, RGB_SCALED(0x40, 0x80, 0xff));
        }
    }

    return false;
}
