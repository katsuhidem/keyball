#include QMK_KEYBOARD_H

#include "quantum.h"

void control_tap_hold(uint16_t keycode, uint16_t l_code, uint16_t h_code, uint16_t t_code, uint16_t l_time, keyrecord_t *record) {
  static uint16_t mem_keycode;
  static uint16_t pressed_time = 0;
  uint16_t prev_keycode = mem_keycode;
  bool is_tapped = ((!record->event.pressed) && (keycode == prev_keycode));
  mem_keycode = keycode;

  if (record->event.pressed) {
    pressed_time = record->event.time;
    if (l_code != 0) {
      layer_on(l_code);
    } else if (h_code != 0) {
      register_code(h_code);
    }
  } else {
    if (l_code != 0) {
      layer_off(l_code);
    } else if (h_code != 0) {
      unregister_code(h_code);
    }
    if (is_tapped && (l_time == 0 || (TIMER_DIFF_16(record->event.time, pressed_time) < l_time))) {
      tap_code(t_code);
    }
  }
}