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

// Mirror the thumbs on left-handed layout
#ifdef LAYOUT_KOLIBRI_LEFTY
#   define LAYOUT_KOLIBRI(                                \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                       K33, K34, K35, K36) LAYOUT_KOLIBRI_LEFTY( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09, \
        K10,     K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19, \
        K20,     K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29, \
                                   K36,     K35,     K34,     K33)
#   ifndef KOLIBRI_ONE_HANDED_NAV
#       define KOLIBRE_NAV_ON_RIGHT
#   endif
#else
#   ifdef KOLIBRI_ONE_HANDED_NAV
#       define KOLIBRI_NAV_ON_RIGHT
#   endif
#endif

// Layer definitions
enum layers {
    L_BASE,
    L_NAV_FN_LOCKED,
    L_BASE_OVERRIDE,
    L_NUM_SYM,
    L_NAV_FN,
    L_CTL_MAC,
#ifdef MOUSEKEY_ENABLE
    L_MOUSE,
#endif
    L_NUM_LAYERS
};

// Macro keys
enum custom_keycodes {
  M_EMAIL = SAFE_RANGE,
  M_XARGS
};

// Hi-jack an unused 8-bit keycode for the Nav+Fn-(un)lock that can be used in
// a Layer-Tap
#define KC_FNLK KC_EXSEL

// Short cuts for mod-tap and layer-tap keys. 16-bit key codes need special
// handling in process_record_user

// Base layer
#define LC_Z    LCTL_T(KC_Z)
#define LG_X    LGUI_T(KC_X)
#define LA_C    LALT_T(KC_C)
#define LA_COMM LALT_T(KC_COMM)
#define RG_DOT  RGUI_T(KC_DOT)
#define RC_SLSH RCTL_T(KC_SLSH)
#define LS_QUOT LSFT_T(KC_QUOT)
#define SY_UNDS LT(L_NUM_SYM, KC_UNDS) // 16-bit
#define CT_UNDS LT(L_CTL_MAC, KC_UNDS) // 16-bit
#define FN_TAB  LT(L_NAV_FN, KC_TAB)
#define RA_SPC  RALT_T(KC_SPC)

// Num+Sym layer
#define LC_LBRC LCTL_T(KC_LBRC)
#define LG_LCBR LGUI_T(KC_LCBR) // 16-bit
#define LA_RCBR LALT_T(KC_RCBR) // 16-bit
#define RA_RBRC RALT_T(KC_RBRC)
#define LA_LT   LALT_T(KC_LT)   // 16-bit
#define RG_GT   RGUI_T(KC_GT)   // 16-bit
#define RC_PIPE RCTL_T(KC_PIPE) // 16-bit
#define CT_DQUO LT(L_CTL_MAC, KC_DQUO) // 16-bit
#define RA_MINS RALT_T(KC_MINS)

// Nav+Fn layer
#define LC_F5   LCTL_T(KC_F5)
#define LG_F6   LGUI_T(KC_F6)
#define LA_F7   LALT_T(KC_F7)
#define LA_F10  LALT_T(KC_F10)
#define RG_F11  RGUI_T(KC_F11)
#define RC_F12  RCTL_T(KC_F12)
#define RS_CAPS RSFT_T(KC_CAPS)
#define SY_FNLK LT(L_NUM_SYM, KC_FNLK)
#define CT_FNLK LT(L_CTL_MAC, KC_FNLK)
#define OV_TAB  LT(L_BASE_OVERRIDE, KC_TAB)

// The Base layer gets duplicated to add a Base-Override layer that can be
// layered on top of a locked Nav+Fn layer. The layer keys are parametrized.
#define KEYMAP_BASE(K34, K35) LAYOUT_KOLIBRI( \
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, \
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
        LC_Z,    LG_X,    LA_C,    KC_D,    KC_V,    KC_K,    KC_H,    LA_COMM, RG_DOT,  RC_SLSH, \
                                   LS_QUOT, K34,     K35,     RA_SPC)

// The Nav+Fn layer gets duplicated for a momentary and a locked version.
// The layer keys are parametrized. There are two versions with arrows on the
// right and left respectively. If mousekeys are enabled, AltGr on the locked
// Nav+FN layer is repurposed as mouse layer-tap.
#ifdef MOUSEKEY_ENABLE
#define MS_SPC LT(L_MOUSE, KC_SPC)
#else
#define MS_SPC KC_TRNS
#endif

#ifdef KOLIBRI_NAV_ON_RIGHT
#   define KEYMAP_NAV_FN(K34, K35) LAYOUT_KOLIBRI( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_SLCK, KC_HOME, KC_UP,   KC_END,  KC_VOLU, \
        KC_ESC,  KC_INS,  KC_BSPC, KC_DEL,  KC_ENT,  KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, \
        LC_F5,   LG_F6,   LA_F7,   KC_F8,   KC_APP,  KC_PGDN, KC_F9,   LA_F10,  RG_F11,  RC_F12,  \
                                   RS_CAPS, K34,     K35,     MS_SPC)
#else
#   define KEYMAP_NAV_FN(K34, K35) LAYOUT_KOLIBRI( \
        KC_VOLU, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_SLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,  \
        KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_ENT,  KC_BSPC, KC_DEL,  KC_INS,  KC_ESC, \
        LC_F5,   LG_F6,   LA_F7,   KC_F8,   KC_PGDN, KC_APP,  KC_F9,   LA_F10,  RG_F11,  RC_F12, \
                                   RS_CAPS, K34,     K35,     MS_SPC)
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = KEYMAP_BASE(SY_UNDS, FN_TAB),

    // Locked Nav+Fn layer sits below the Num+Sym layer:
    // - Left key is Fn-unlock/Sym
    // - Right key is Tab/Base-Override
    //
    // Unlock disables the locked Nav+Fn layer. Base-Override temporarily
    // restores a (slightly modified) base layer on top of it.
    [L_NAV_FN_LOCKED] = KEYMAP_NAV_FN(SY_FNLK, OV_TAB),

    // Base-Override layer that overlays the locked Nav+Fn layer:
    // - Left key is Underscore/Ctl+Macro
    //   (both layer keys together always lead to Ctl+Macro)
    // - Right key is transparent
    [L_BASE_OVERRIDE] = KEYMAP_BASE(CT_UNDS, _______),

    [L_NUM_SYM] = LAYOUT_KOLIBRI(
        KC_EXLM, KC_GRV,  KC_TILD, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        LC_LBRC, LG_LCBR, LA_RCBR, RA_RBRC, KC_BSLS, KC_PLUS, KC_EQL,  LA_LT,   RG_GT,   RC_PIPE,
                                   _______, _______, CT_DQUO, RA_MINS),

    // Momentary Nav+Fn layer:
    // - Left key is Fn-lock/Ctl+Macro
    // - Right key is transparent
    [L_NAV_FN] = KEYMAP_NAV_FN(CT_FNLK, _______),

    [L_CTL_MAC] = LAYOUT_KOLIBRI(
        RESET,   _______, _______, _______, DEBUG,   KC_PAUS, DT_PRNT, DT_DOWN, DT_UP,   _______,
        _______, _______, M_XARGS, M_EMAIL, _______, RGB_TOG, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI,
        _______, _______, _______, _______, _______, _______, RGB_RMOD,RGB_VAD, RGB_SAD, RGB_HUD,
                                   _______, _______, _______, _______),

#ifdef MOUSEKEY_ENABLE
    [L_MOUSE] = LAYOUT_KOLIBRI(
        KC_BTN5, KC_BTN3, KC_WH_U, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______,
        KC_BTN4, KC_BTN2, KC_WH_D, KC_BTN1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, KC_LALT, KC_RGUI, KC_RCTL,
                                   KC_LSFT, KC_ACL0, _______, _______)
#endif
};

// MTs on the base layer bottom row and Space prefer tap over hold. Everything
// else prefers hold: LTs and MTs on the thumbs and MTs on the other layers.
//
// I suspect that QMK doesn't handle conflicting MT/LT per-key preferences
// very well. So this rule ensures that LTs on the thumbs agree with MTs on
// the fingers (on their layer).
static const uint16_t tap_preferred[] = {
#ifdef MOUSEKEY_ENABLE
    MS_SPC,
#endif
    LC_Z, LG_X, LA_C, LA_COMM, RG_DOT, RC_SLSH, RA_SPC,
    LC_LBRC, LG_LCBR, LA_RCBR, RA_RBRC, LA_LT, RG_GT, RC_PIPE
};

static bool prefer_tap(uint16_t keycode) {
    int i;

    for (i = 0; i < sizeof(tap_preferred)/sizeof(*tap_preferred); i++)
        if (tap_preferred[i] == keycode)
            return true;
    return false;
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !prefer_tap(keycode);
}
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return prefer_tap(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Modify shifted '.' and ',' on the base layer to move '<' and '>' to the
    // Num+Sym layer
    if (get_mods() & MOD_MASK_SHIFT) {
        uint16_t new_code;

        switch (keycode & 0xff) {
        case KC_COMM: new_code = KC_3; break; // '#'
        case KC_DOT:  new_code = KC_2; break; // '@'
        default: goto macros;
        }
        if (record->event.pressed)
            register_code(new_code);
        else
            unregister_code(new_code);
        return false;
    }

macros:
    if (record->event.pressed) { // Macros
        switch (keycode) {
        case M_EMAIL:
            SEND_STRING("Felix Kuehling <Felix.Kuehling@amd.com>");
            return false;
        case M_XARGS:
            SEND_STRING(" -print0 | xargs -0 grep ");
            return false;
        }
    }

    if (record->tap.count) { // Mod-tap with modified tap-action
        uint16_t code16;

        if (IS_LAYER_ON(L_NUM_SYM)) {
            switch (keycode) {
            case CT_DQUO: code16 = KC_DQUO; break;
            case LG_LCBR: code16 = KC_LCBR; break;
            case LA_RCBR: code16 = KC_RCBR; break;
            case LA_LT:   code16 = KC_LT; break;
            case RG_GT:   code16 = KC_GT; break;
            case RC_PIPE: code16 = KC_PIPE; break;
            default: return true;
            }
        } else {
            switch (keycode) {
            case CT_FNLK: // Nav+Fn-Lock
            case SY_FNLK: // Nav+Fn-Unlock
                if (record->event.pressed)
                    layer_invert(L_NAV_FN_LOCKED);
                return false; // doesn't send any keycode
            case SY_UNDS:
            case CT_UNDS: code16 = KC_UNDS; break;
            default: return true;
            }
        }
        if (record->event.pressed)
            register_code16(code16);
        else
            unregister_code16(code16);
	return false;
    }

    return true;
}

#ifdef RGBLIGHT_ENABLE
// Lighting layers
#define CAPSLOCK_COLOR HSV_CYAN
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, CAPSLOCK_COLOR}, // Left hand, top right LED
    { 5, 2, CAPSLOCK_COLOR}, // Bottom center two LEDs
    {11, 1, CAPSLOCK_COLOR}  // Right hand, top left LED
);

#define NAVFLOCK_COLOR HSV_CYAN
const rgblight_segment_t PROGMEM my_navflock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 3, 1, NAVFLOCK_COLOR}, // Left hand, bottom left LED
    { 8, 1, NAVFLOCK_COLOR}  // Right hand, bottom right LED
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
    rgblight_set_layer_state(1, layer_state_cmp(state, L_NAV_FN_LOCKED));
    rgblight_set_layer_state(2, layer_state_cmp(state, L_NUM_SYM));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_NAV_FN));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_CTL_MAC));
    return state;
}
#endif
