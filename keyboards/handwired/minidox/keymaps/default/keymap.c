#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        MO(1), KC_SPC, KC_MS_L, KC_MS_R, KC_BSPC, MO(2)
    ),
    [1] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_ESC, KC_TAB, KC_CAPS, KC_TILD, KC_GRV, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RGUI,
        KC_TRNS, KC_SPC, KC_LGUI, KC_PGUP, KC_VOLU, KC_MS_U
    ),
    [2] = LAYOUT(
        KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  RGB_HUI, RGB_M_G, RGB_M_P, RGB_MOD, RGB_TOG,
        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, RGB_HUD, RGB_M_SW, RGB_M_R, RGB_SAD, RGB_SAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_MS_D, KC_VOLD, KC_PGDN, KC_RALT, KC_BSPC, KC_TRNS
    )
};
