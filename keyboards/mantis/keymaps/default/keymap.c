#include QMK_KEYBOARD_H

/* Finger assignment:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  p  │  p  │  R  │  M  │             │  M  │  R  │  p  │  p  │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  p  ┃  R  ┃  M  ┃  I  │       │  I  ┃  M  ┃  R  ┃  p  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  p  │  R  │  M  ┃  I  ┃  I  │ │  I  ┃  I  ┃  M  │  R  │  p  │
 * └─────┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─────┘
 *          │  M  │  I  │  I  │       │  I  │  I  │  M  │
 *          └─────┴─────┴─────┘       └─────┴─────┴─────┘     T - Thumb
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐        I - Index finger
 *             │  T  ┃  T  ┃  T  │ │  T  ┃  T  ┃  T  │        M - Middle finger
 *             └─────┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹─────┘        R - Ring finger
 *                      │  T  │       │  T  │                 p - Pinky finger
 *                      └─────┘       └─────┘
 *
 * Base Layer (based on QWERTY):
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  Z  │  Q  │  W  │  E  │             │  I  │  O  │  P  │ '"' │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  A  ┃  S  ┃  D  ┃  R  │       │  U  ┃  K  ┃  L  ┃  M  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  B  │  X  │  C  ┃  F  ┃  T  │ │  Y  ┃  J  ┃  ,@ │  .# │  \? │
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │  V  │  G  │       │  H  │  N  │ App │
 *          └─────┴─────┴─────┘       └─────┴─────┴─Gui─┘     ┌─────┐
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐        │ Tap │
 *             │ Alt ┃ Bsp ┃  _  │ │Enter┃     ┃ Del │        └─Hold┘
 *             └1shot┺Shift┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │  -  │       │ Tab │
 *                      └─Sym─┘       └──Fn─┘
 *
 * Base Layer (based on Colemak-DH):
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  X  │  Q  │  W  │  F  │             │  U  │  Y  │  J  │ '"' │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  A  ┃  R  ┃  S  ┃  P  │       │  L  ┃  E  ┃  I  ┃  O  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  Z  │  V  │  C  ┃  T  ┃  G  │ │  M  ┃  N  ┃  ,@ │  .# │  \? │
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │  D  │  B  │       │  K  │  H  │ App │
 *          └─────┴─────┴─────┘       └─────┴─────┴─Gui─┘     ┌─────┐
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐        │ Tap │
 *             │ Alt ┃ Bsp ┃  _  │ │Enter┃     ┃ Del │        └─Hold┘
 *             └1shot┺Shift┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │  -  │       │ Tab │
 *                      └─Sym─┘       └──Fn─┘
 *
 * Symbol Layer:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  ~  │  !  │  <  │  >  │             │  (  │  )  │  |  │  :  │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  1  ┃  2  ┃  3  ┃  $  │       │  &  ┃  8  ┃  9  ┃  0  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  [  │  {  │  }  ┃  4  ┃  %  │ │  ^  ┃  7  ┃  -  │  *  │  /  │
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │  ]  │  5  │       │  6  │  +  │ App │
 *          └─────┴─────┴─────┘       └─────┴─────┴─Gui─┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │ ... ┃ ... ┃ ... │ │  ;  ┃  =  ┃  `  │
 *             └─────┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │[Sym]│       │  .  │
 *                      └─────┘       └──Fn─┘
 *
 * Function layer:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  F1 │  F2 │  F3 │  F4 │             │  F9 │ F10 │ F11 │ F12 │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃ Esc ┃ Ins ┃ Bsp ┃  F5 │       │  F8 ┃  Up ┃Right┃ End ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │ Undo│Colmk│QWERT┃ Del ┃  F6 │ │  F7 ┃ Left┃ Down│ PgDn│ Mute│
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │Paste│PrScr│       │ Home│ PgUp│ App │
 *          └─────┴─────┴─────┘       └─────┴─────┴─Gui─┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │ Alt ┃ Caps┃Enter│ │ ... ┃ ... ┃ ... │
 *             └─────┺Shift┹──┬──┘ └──┬──┺━━┯━━┹─────┘
 *                      │ Calc│       │ [Fn]│
 *                      └─Sym─┘       └─────┘
 */

enum MantisLayers {
	LAYER_qwerty = 0,
	LAYER_colemak,
	LAYER_sym,
	LAYER_fn
};

#define OS_LALT OSM(MOD_LALT)
#define SH_BSPC LSFT_T(KC_BSPC)
#define SY_MINS LT(LAYER_sym,KC_MINS)
#define RG_APP  RGUI_T(KC_APP)
#define FN_TAB  LT(LAYER_fn,KC_TAB)
#define AGR_DEL RALT_T(KC_DEL)
#define AGR_GRV RALT_T(KC_GRV)
#define FN_DOT  LT(LAYER_fn,KC_DOT)
#define SH_CAPS RSFT_T(KC_CAPS)
#define SY_CALC LT(LAYER_sym,KC_CALC)
#define DF_QWER DF(LAYER_qwerty)
#define DF_COLM DF(LAYER_colemak)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_colemak] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_X,   KC_Q,   KC_W,   KC_F,   KC_P,           KC_L,   KC_U,   KC_Y,   KC_J,   KC_QUOT,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_A,   KC_R,   KC_S,   KC_T,   KC_G,   KC_M,   KC_N,   KC_E,   KC_I,   KC_O,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
 LCTL_T(KC_Z),  KC_V,   KC_C,   KC_D,   KC_B,           KC_K,   KC_H,   KC_COMM,KC_DOT, RCTL_T(KC_BSLS),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        KC_LGUI,OS_LALT,SH_BSPC,SY_MINS,KC_UNDS,        KC_ENT, FN_TAB, KC_SPC, AGR_DEL,RG_APP
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
    [LAYER_qwerty] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_Z,   KC_Q,   KC_W,   KC_E,   KC_R,           KC_U,   KC_I,   KC_O,   KC_P,   KC_QUOT,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_A,   KC_S,   KC_D,   KC_F,   KC_T,   KC_Y,   KC_J,   KC_K,   KC_L,   KC_M,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
 LCTL_T(KC_B),  KC_X,   KC_C,   KC_V,   KC_G,           KC_H,   KC_N,   KC_COMM,KC_DOT, RCTL_T(KC_BSLS),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        KC_LGUI,OS_LALT,SH_BSPC,SY_MINS,KC_UNDS,        KC_ENT, FN_TAB, KC_SPC, AGR_DEL,RG_APP
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
    [LAYER_sym] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_TILD,KC_EXLM,KC_LT,  KC_GT,  KC_DLR,         KC_AMPR,KC_LPRN,KC_RPRN,KC_PIPE,KC_COLN,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_1,   KC_2,   KC_3,   KC_4,   KC_PERC, KC_CIRC,KC_7,   KC_8,   KC_9,   KC_0,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
LCTL_T(KC_LBRC),KC_LCBR,KC_RCBR,KC_RBRC,KC_5,           KC_6,   KC_PLUS,KC_MINS,KC_ASTR,RCTL_T(KC_SLSH),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        _______,_______,_______,_______,_______,        KC_SCLN,FN_DOT, KC_EQL, AGR_GRV,_______
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
    [LAYER_fn] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,          KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_ESC, KC_INS, KC_BSPC,KC_DEL, KC_F6,   KC_F7,  KC_LEFT,KC_UP,  KC_RGHT,KC_END,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
LCTL_T(KC_UNDO),DF_QWER,DF_COLM,KC_PSTE,KC_PSCR,        KC_HOME,KC_PGUP,KC_DOWN,KC_PGDN,RCTL_T(KC_MUTE),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        _______,KC_LALT,SH_CAPS,SY_CALC,KC_ENT,         _______,_______,_______,_______,_______
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    )
};

/* Prefer tap on fingers, hold on thumbs */
static bool prefer_tap(keyrecord_t *record) {
    return record->event.key.row < 3;
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !prefer_tap(record);
}
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return prefer_tap(record);
}

/* Key overrides for @ and # on the base layer */
#define ko_make_basic_no_suppress(trig_mods, trig_key, repl_key) {	\
	.trigger_mods = (trig_mods),					\
	.layers = ~0,							\
	.suppressed_mods = 0,						\
	.options = ko_options_default,					\
	.negative_mod_mask = 0,						\
	.custom_action = NULL,						\
	.context = NULL,						\
	.trigger = (trig_key),						\
	.replacement = (repl_key),					\
	.enabled = NULL							\
}
const key_override_t   at_key_override = ko_make_basic_no_suppress(MOD_MASK_SHIFT, KC_COMM, KC_2);
const key_override_t hash_key_override = ko_make_basic_no_suppress(MOD_MASK_SHIFT, KC_DOT,  KC_3);
const key_override_t ques_key_override = ko_make_basic_no_suppress(MOD_MASK_SHIFT, RCTL_T(KC_BSLS),KC_SLSH);
const key_override_t **key_overrides = (const key_override_t *[]){
    &at_key_override,
    &hash_key_override,
    &ques_key_override,
    NULL
};

/* Alternative layer ideas
 *
 * Symbol Layer (num pad, .= duplicated):
 * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
 * │  ^  │  ~  │  @  │  #  │  $  │       │  7  │  8  │  9  │  :  │  `  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐ ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │  !  │  (  │  =  │  )  │  &  │ │  *  │  4  │  5  │  6  │  -  │
 * ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘ └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐
 * │  [  │  {  │  }  │  ]  │  |  │       │  +  │  1  │  2  │  3  │  \  │
 * └─Ctl─┴──┬──┴──┬──┴─────┴─────┘       └─────┴─────┴──┬──┴──┬──┴─Ctl─┘
 *          │ Gui ├─────┬─────┬─────┐ ┌─────┬─────┬─────┤ Gui │
 *          └─────┤ ... │ ... │ ... │ │  %  │  0  │  .  ├─────┘
 *                └─────┴──┬──┴──┬──┘ └──┬──┴──┬──┴AltGr┘
 *                         │ ... │       │  ;  │
 *                         └─────┘       └──Fn─┘
 */
