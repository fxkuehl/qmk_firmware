// Copyright 2024 Felix Kuehling (@fxkuehl)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max))
        return false;

    const bool caps_lock = host_keyboard_led_state().caps_lock;
    const bool num_lock = host_keyboard_led_state().num_lock;
    const uint8_t layer = get_highest_layer(layer_state);
    HSV matrix_hsv = rgb_matrix_get_hsv();

    if (!caps_lock && !layer)
        return false;

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t index = g_led_config.matrix_co[row][col];

            if (index < led_min || index >= led_max)
                continue;

            HSV hsv;
            hsv.s = 255;
            hsv.v = matrix_hsv.v;

            uint16_t kc = layer ?
                keymap_key_to_keycode(layer, (keypos_t){col,row}) : 0;

            if (kc >= QK_MOD_TAP && kc <= QK_LAYER_TAP_MAX)
                kc &= 0xff;

            switch (kc) {
            case KC_RIGHT ... KC_UP:
            case KC_ESC:
            case KC_INS:
            case KC_BSPC:
            case KC_DEL:
                hsv.h = 252;
                break;
            case KC_1 ... KC_0:
                hsv.h = 80;
                break;
            case KC_KP_1 ... KC_KP_0:
                if (!num_lock) {
                    hsv.h = 252;
                    hsv.v >>= 2;
                    break;
                }
                // fall through
            case KC_NUM:
                hsv.h = 149;
                break;
#ifdef MOUSEKEY_ENABLE
            case KC_MS_U ... KC_BTN2:
            case KC_WH_U ... KC_WH_D:
                hsv.h = 40;
                break;
#endif
            case RGB_TOG ... RGB_SPD:
                hsv.h = matrix_hsv.h + ((((kc + 3) >> 1) % 6) * 85 >> 1);
                hsv.s = matrix_hsv.s;
                uint8_t inc = (kc + !!(get_mods() & MOD_LSFT)) & 1;
                hsv.v >>= 1 - inc;
                break;
            default:
                if (caps_lock && (row == 0 ||
                            (row == 3 && (col == 0 || col == 9))
                            ))
                    hsv.h = matrix_hsv.h+128, hsv.s >>= 1,
                        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
                else
                    continue;
            }

            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
        }
    }

    return false;
}
