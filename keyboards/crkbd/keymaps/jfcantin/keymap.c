/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum layers {
    DEFAULT,
    NAV,
    SYM,
    NUM,
    MOUSE,
    FUN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.                 ,-----------------------------------------------------.
      KC_Q, LCTL_T(KC_W), RALT_T(KC_F), LGUI_T(KC_P),   KC_B, KC_MINUS,     XXXXXXX,    KC_J,  RGUI_T(KC_L),    RALT_T(KC_U),   RCTL_T(KC_Y),   KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|
      KC_A, KC_R,         KC_S,         KC_T,           KC_G, KC_GRAVE,     XXXXXXX,    KC_M,  KC_N,            KC_E,           KC_I,           KC_O,
  //|--------+--------+--------+--------+--------+--------'                 |--------+--------+--------+--------+--------+--------|
      KC_Z, KC_X,         KC_C,         KC_D,           KC_V,                           KC_K,  KC_H,            KC_COMM,        KC_DOT,         KC_SLSH,
  //|--------+--------+--------+--------+--------+--------                  ---------+--------+--------+--------+--------+--------+--------|
                            KC_LSFT,    LT(2,KC_ENTER),  LT(4,KC_TAB),       LT(2,KC_BSPC), KC_SPACE,   KC_RSFT
                              //`-------------------------'                 `--------------------------'

  ),

       //_______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,

    [NAV] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, LGUI(KC_TAB), _______, _______, KC_VOLU, _______,                _______,  KC_INS,  KC_HOME,  KC_UP,  KC_END, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, KC_VOLD, _______,                      _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, KC_MPLY,                                        KC_PGDN, KC_TAB, KC_TAB, XXXXXXX, XXXXXXX,
      //_______, _______, _______, _______, KC_MPLY,                                        KC_PGDN, C(S(KC_TAB)), C(KC_TAB), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, _______,  _______,     _______,   LGUI(KC_SPACE), _______
                                      //`--------------------------'  `--------------------------'
  ),

    [SYM] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_MINUS,                     KC_EQL, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_UNDS,                    KC_PLUS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TILD, KC_GRAVE, KC_LBRC, KC_LCBR,                                       KC_RCBR, KC_RBRC, KC_PIPE, KC_BSLS, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x5_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
