#include QMK_KEYBOARD_H
#include "features/select_word.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
enum custom_keycodes {
    SELWORD = SAFE_RANGE,
};
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case SELWORD:
            if (!process_select_word(keycode, record, SELWORD)) {
                return false;
            }
    }
    return true;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_1   , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  ,                         KC_7  , KC_8  , KC_9  , KC_0  , KC_MINS  ,KC_EQL,
        KC_GRV , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
        KC_BSLS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_RBRC,
        SELWORD, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_QUOT,KC_SLSH,
                         KC_UP,KC_DOWN,                                                       KC_LEFT, KC_RGHT,
                                         LSFT_T(KC_CAPS), KC_SPC,                   KC_BSPC, KC_ENT,
                                         TT(1), KC_TAB,                             KC_LCTL, KC_LALT,
                                         KC_LGUI, KC_DEL,                           DM_REC1, KC_ESC
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                           	KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC,                    KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PAST, KC_PMNS,
       KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LPRN,                     KC_RPRN, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PCMM, 
        _______,_______,_______,_______,_______,_______,                        KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PEQL,
									KC_BTN1, KC_BTN2,            					KC_WH_U, KC_WH_D,
                                                _______,_______,            _______,_______,
                                                TT(0),_______,            _______,_______,
                                                _______,KC_INS,            DM_PLY1 ,_______

    ),

    [_RAISE] = LAYOUT_5x6(
          KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
          _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,KC_MUTE,
          _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
          _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                                  _______,_______,            KC_EQL ,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    )
};
