#include QMK_KEYBOARD_H
#define TAPPING_TERM 200

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NAV,
    _NUMS,
    _SHIFTED_NUMS,
    _LOWER,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *       ┌───┬───┬───┐                   ┌───┬───┬───┐
     *       │   │   │GUI├───┐           ┌───┤Alt│   │   │
     *       └───┴───┴───┤Lwr├───┐   ┌───┤Rse├───┴───┴───┘
     *                   └───┤Spc│   │Ent├───┘
     *                       └───┘   └───┘
     */
    [_BASE] = LAYOUT_split_3x6_5(
        KC_ESC,   KC_Q,         KC_W,         KC_E,         KC_R,          KC_T,                     KC_Y,     KC_U,          KC_I,         KC_O,         KC_P,            KC_BSPC,
        KC_TAB,  LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D),  LGUI_T(KC_F),  KC_G,                     KC_H,     RGUI_T(KC_J),  RALT_T(KC_K), RSFT_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
        KC_CAPS,  KC_Z,         KC_X,         KC_C,         KC_V,          KC_B,                     KC_N,     KC_M,          KC_COMM,      KC_DOT,       KC_SLSH,         KC_BSLS,
                  OSM(MOD_LSFT),      MO(_NUMS),      MO(_SHIFTED_NUMS),   KC_SPC,        KC_LGUI,                  KC_RGUI,  KC_ENT,        MO(_NAV),   KC_RCTL,      OSM(MOD_LSFT)
    ),

    [_NAV] = LAYOUT_split_3x6_5(
        KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_HASH,    KC_DLR,   KC_PERC,                  KC_CIRC,    KC_HOME,     KC_END,       KC_TRNS,  KC_PSCR,  KC_BSPC,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_LEFT,    KC_DOWN,     KC_UP,     KC_RIGHT, KC_TRNS,  KC_DELETE,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_AT,    KC_EXLM,  KC_TRNS,                  KC_TRNS,    KC_PGDN,     KC_PGUP,     KC_TRNS,  KC_TRNS,  KC_TRNS,
                    KC_TRNS,  KC_TRNS,  MO(_NUMS), KC_TRNS,   KC_TRNS,                 QK_BOOT,    KC_TRNS,     MO(_NAV),  KC_TRNS, KC_TRNS
    ),

    [_NUMS] = LAYOUT_split_3x6_5(
        KC_GRV,  KC_0,             KC_9,         KC_8,         KC_7,         KC_TRNS,                   KC_PLUS,    KC_LPRN,          KC_RPRN,          KC_SCLN,         KC_COLN,          KC_SLSH,
        KC_TRNS, LCTL_T(KC_TRNS),  LSFT_T(KC_6), LALT_T(KC_5), LGUI_T(KC_4), KC_TRNS,                   KC_MINS,    RGUI_T(KC_LBRC),  RALT_T(KC_RBRC),  RSFT_T(KC_EQL),  RCTL_T(KC_QUOT),  KC_DQT,
        KC_TRNS, KC_TRNS,          KC_3,         KC_2,         KC_1,         KC_TRNS,                   KC_UNDS,    KC_LCBR,          KC_RCBR,          KC_LT,           KC_GT,            KC_TRNS,
                 KC_TRNS,          MO(_NUMS),      KC_TRNS,    KC_TRNS,      QK_BOOT,                   KC_TRNS,    KC_TRNS,          MO(_NAV),         KC_TRNS,         KC_TRNS
    ),

    [_SHIFTED_NUMS] = LAYOUT_split_3x6_5(
        KC_TILD,  KC_RPRN,  KC_LPRN,  KC_ASTR,            KC_AMPR,        KC_TRNS,                   KC_PLUS,  KC_LPRN,          KC_RPRN,          KC_SCLN,         KC_COLN,          KC_SLSH,
        KC_TRNS,  KC_TRNS,  KC_CIRC,  KC_PERC,            KC_DLR,         KC_TRNS,                   KC_MINS,  RGUI_T(KC_LBRC),  RALT_T(KC_RBRC),  RSFT_T(KC_EQL),  RCTL_T(KC_QUOT),  KC_DQT,
        KC_TRNS,  KC_TRNS,  KC_HASH,  KC_AT,              KC_EXLM,        KC_TRNS,                   KC_UNDS,  KC_LCBR,          KC_RCBR,          KC_LT,           KC_GT,            KC_TRNS,
                  KC_TRNS,  KC_TRNS,  MO(_SHIFTED_NUMS),  KC_TRNS,        QK_BOOT,                   KC_TRNS,  KC_TRNS,          MO(_NAV),         KC_TRNS,         KC_TRNS
    ),

    [_ADJUST] = LAYOUT_split_3x6_5(
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_7,     KC_8,       KC_9,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_4,     KC_5,       KC_6,  KC_F11,  KC_F12,
        KC_TRNS,    KC_F1,      KC_F2,    KC_F3,    KC_F4,      KC_F5,                  KC_F7,      KC_F6,    KC_F7,     KC_F8,   KC_F9,   KC_F10,
                    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                    KC_TRNS,      KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUMS, _NAV, _ADJUST);
    state = update_tri_layer_state(state, _SHIFTED_NUMS, _NAV, _ADJUST);
    return state;
}

/*
 * ROTARY ENCODER
 */

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),             ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [_NUMS] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_NAV] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif