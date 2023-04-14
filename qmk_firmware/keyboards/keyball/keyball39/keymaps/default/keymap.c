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

#include "keymaps/common/keymap.h"
#include "keymaps/common/config.h"
#include "keymaps/common/twpair_on_jis.h"
#include "keymaps/common/auto_mouse.h"
#include "keymaps/common/common.h"

enum layer_number {
    _QWERTY = 0,
    _NUMBER,
    _SYMBOL,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    __QWERTY_L1__, __QWERTY_R1__,
    __QWERTY_L2__, __QWERTY_R2__,
    __QWERTY_L3__, __QWERTY_R3__,
    __QUERTY_L4__, __QUERTY_R4__
  ),

  [_NUMBER] = LAYOUT_wrapper(
    __NUM2_L1__, __NUM2_R1__,
    __NUM2_L2__, __NUM2_R2__,
    __NUM2_L3__, __NUM2_R3__,
    __NUM2_L4__, __NUM2_R4__
  ),

  [_SYMBOL] = LAYOUT_wrapper(
    __SYMBOL_L1__, __SYMBOL_R1__,
    __SYMBOL_L2__, __SYMBOL_R2__,
    __SYMBOL_L3__, __SYMBOL_R3__,
    __SYMBOL_L4__, __SYMBOL_R4__
  ),

  [3] = LAYOUT_universal(
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, CK_EnJIS, ____, ____, CK_EnUS, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____
  ),

  [4] = LAYOUT_wrapper(
    __SP_L1__, __SP_R1__,
    __SP_L2__, __SP_R2__,
    __SP_L3__, __SP_R3__,
    __SP_L4__, __SP_R4__
  ),

  [5] = LAYOUT_wrapper(
    __MOUSE_L1__, __MOUSE_R1__,
    __MOUSE_L2__, __MOUSE_R2__,
    __MOUSE_L3__, __MOUSE_R3__,
    __MOUSE_L4__, __MOUSE_R4__
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーとLEDを連動させる
  uint8_t layer = biton32(state);
  switch (layer)
  {
  case 1:
    rgblight_sethsv(HSV_BLUE);
    break;
  case 2:
    rgblight_sethsv(HSV_MAGENTA);
    break;
  case 5:
    rgblight_sethsv(HSV_RED);
    break;

  default:
    rgblight_sethsv(HSV_OFF);
  }

    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();

  oled_write_P(PSTR("Layer:"), false);
  oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);
  oledkit_render_auto_mouse();
  oled_write_P(PSTR(" Mode:"), false);
  if (user_config.jis){
    oled_write_ln("JIS", false);
  } else {
    oled_write_ln(" US", false);
  }
}
#endif

#define TAPPING_LAYER_TERM 230
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case G_F:
      return 320;
    case G_J:
      return 320;
    default:
      return TAPPING_TERM;
  }
}

enum combos {
  LNG_EN,
  LNG_JP,
  CAP_WORD,
  SK_BS,
  SK_DEL,
  SK_TAB,
  BRACKET,
  S_BRACKET,
  PAREN,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM fg_combo[] = {G_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, G_J, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM bracket_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM a_bracket_combo[] = {LSFT_T(KC_COMM), LSFT_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM paren_combo[] = {KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
  [LNG_EN] = COMBO(fg_combo, KC_LNG2),
  [LNG_JP] = COMBO(hj_combo, KC_LNG1),
  [CAP_WORD] = COMBO(yu_combo, CW_TOGG),
  [SK_BS] = COMBO(op_combo, KC_BSPC),
  [SK_DEL] = COMBO(dotslsh_combo, KC_DEL),
  [SK_TAB] = COMBO(as_combo, KC_TAB),
  [BRACKET] = COMBO_ACTION(bracket_combo),
  [S_BRACKET] = COMBO_ACTION(a_bracket_combo),
  [PAREN] = COMBO_ACTION(paren_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case BRACKET:
      if (pressed) {
        SEND_STRING("[]");
      }
      break;
    case S_BRACKET:
      if (pressed) {
        SEND_STRING("{}");
      }
      break;
    case PAREN:
      if (pressed) {
        SEND_STRING("()");
      }
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool ret = true;
  switch (keycode) {
    case NUMBER:
      control_tap_hold(keycode, _NUMBER, 0, KC_SPC, 300, record);
      ret = false;
      break;

    case SYMBOL:
      control_tap_hold(keycode, _SYMBOL, 0, KC_ENT, 300, record);
      ret = false;
      break;

    case CK_EnJIS:
      set_keyboard_lang_to_jis(true);
      ret = false;
      break;

    case CK_EnUS:
      set_keyboard_lang_to_jis(false);
      ret = false;
      break;

    default:
      if (user_config.jis){
        ret = twpair_on_jis(keycode, record);
      }
      break;
  }

  if (ret) {
    ret = auto_mouse_process_record_user(keycode, record);
  }

  return ret;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  return auto_mouse_pointing_device_task_user(mouse_report);
}