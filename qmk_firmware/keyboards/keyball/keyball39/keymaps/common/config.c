#include QMK_KEYBOARD_H
#include "config.h"

user_config_t user_config = {};

void load_persistent(void) {
  user_config.raw = eeconfig_read_user();
}

void save_persistent(void) {
  eeconfig_update_user(user_config.raw);
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.to_clickable_movement = 20;
    eeconfig_update_user(user_config.raw);
}

void c_init_user(void) {
  save_persistent();
}

void keyboard_post_init_user(void) {
  if (is_keyboard_master()) {
    load_persistent();
  }
}