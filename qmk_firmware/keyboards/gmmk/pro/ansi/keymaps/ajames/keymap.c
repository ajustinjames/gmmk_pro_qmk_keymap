/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_MAIL, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG, KC_PSCR,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______,          KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            RGB_SAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          RGB_SAD,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_VAI, KC_HOME,
        _______, _______, _______,                            _______,                            KC_APP, _______, _______, RGB_RMOD, RGB_VAD, RGB_MOD
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};


bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch(biton32(layer_state)){
        case 1:
            if (clockwise){
                tap_code16(KC_MS_WH_RIGHT);
            } else{
                tap_code16(KC_MS_WH_LEFT);
            }
            break;
        default:
            if (clockwise) {
                tap_code16(KC_PGDOWN);
            } else {
                tap_code16(KC_PGUP);
            }
            break;
        }
    }
    return true;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(3, 255, 255, 255); //capslock key

        //Left side rgb
        RGB_MATRIX_INDICATOR_SET_COLOR(67, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(70, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(73, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(76, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(80, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(83, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(87, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(91, 255, 255, 255);

        //Right side rgb
        RGB_MATRIX_INDICATOR_SET_COLOR(68, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(71, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(74, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(77, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(81, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(84, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(88, 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(92, 255, 255, 255);
    }
}
