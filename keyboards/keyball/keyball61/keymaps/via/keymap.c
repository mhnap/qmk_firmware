/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_GRV, KC_1 , KC_2 , KC_3 , KC_4 , KC_5               ,                                              KC_6                , KC_7 , KC_8   , KC_9  , KC_0   , KC_MINS             ,
    KC_ESC, KC_Q , KC_W , KC_E , KC_R , KC_T               ,                                              KC_Y                , KC_U , KC_I   , KC_O  , KC_P   , KC_EQL              ,
    KC_TAB, KC_A , KC_S , KC_D , KC_F , KC_G               ,                                              KC_H                , KC_J , KC_K   , KC_L  , KC_SCLN, MT(MOD_LALT,KC_QUOT),
    KC_NO , KC_Z , KC_X , KC_C , KC_V , KC_B               , KC_LBRC            ,    KC_RBRC            , KC_N                , KC_M , KC_COMM, KC_DOT, KC_SLSH, MT(MOD_LGUI,KC_BSLS),
    KC_NO , MO(2), KC_NO, KC_NO, KC_NO, MT(MOD_LSFT,KC_SPC), MT(MOD_LCTL,KC_DEL),    MT(MOD_RCTL,KC_ENT), MT(MOD_RSFT,KC_BSPC), MO(1), KC_NO  , KC_NO , KC_NO  , KC_NO
  ),

  [1] = LAYOUT_universal(
    KC_F12 , KC_F1, KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10, KC_F11 ,
    KC_TRNS, KC_NO, KC_PGUP, KC_UP  , KC_PGDN, KC_NO  ,                      KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO  ,
    KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  ,                      KC_NO  , KC_BTN1, KC_BTN3, KC_BTN2, KC_NO , KC_TRNS,
    KC_NO  , KC_NO, KC_HOME, KC_NO  , KC_END , KC_NO  , KC_NO  ,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_TRNS,
    KC_NO  , KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_NO , KC_NO
  ),

  [2] = LAYOUT_universal(
    KBC_SAVE, CPI_I100, CPI_D100, CPI_I1K, CPI_D1K, SCRL_TO,                     SCRL_MO, SCRL_DVI, SCRL_DVD, AML_TO , AML_I50  , AML_D50 ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO   , KC_NO   , KC_NO  , KC_NO    , SSNP_VRT,
    KC_NO   , KC_NO   , KC_NO   , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO   , KC_NO   , KC_NO  , KC_NO    , SSNP_HOR,
    KC_NO   , KC_NO   , KC_NO   , KC_NO  , KC_NO  , KC_NO  , QK_BOOT,    EE_CLR, KC_NO  , KC_NO   , KC_NO   , KC_NO  , KC_NO    , SSNP_FRE,
    KC_NO   , KC_NO   , KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,    KC_NO , KC_NO  , KC_NO   , KC_NO   , KC_NO  , QK_REBOOT, KBC_RST
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    bool scroll_enabled = layer_state_cmp(state, 0);
    keyball_set_scroll_mode(scroll_enabled);
    return state;
}

// Leave a quick tap for `TT`s keys.
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case TT(1):
      case TT(2):
      case TT(3):
          return TAPPING_TERM;
      default:
          return QUICK_TAP_TERM;
  }
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
