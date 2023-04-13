
// common
#define ____ KC_TRNS
#define XXXX KC_NO

// cmd_t
#define G_F LCMD_T(KC_F)
#define G_J RCMD_T(KC_J)

// shift_t
#define S_ES LSFT_T(KC_ESC)
#define S_MI LSFT_T(KC_MINS)

// layer
#define EX_1 LT(5,KC_SPC)
#define EX_2 LT(1,KC_SPC)
#define EX_3 LT(3,KC_BTN1)
#define EX_4 LT(4,KC_BSPC)
#define EX_5 LT(2,KC_ENT)

enum custom_mouse_keycodes {
  CK_EnJIS = KEYBALL_SAFE_RANGE,
  CK_EnUS,
  MY_SAFE_RANGE
};

#define __QWERTY_L1__ KC_Q, KC_W, KC_E, KC_R, KC_T
#define __QWERTY_L2__ KC_A, KC_S, KC_D, G_F, KC_G
#define __QWERTY_L3__ KC_Z, KC_X, KC_C, KC_V, KC_B

#define __QWERTY_R1__ KC_Y, KC_U, KC_I, KC_O, KC_P
#define __QWERTY_R2__ KC_H, G_J, KC_K, KC_L, KC_SCLN
#define __QWERTY_R3__ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define __QUERTY_L4__ S_ES, KC_LCTL, KC_LALT, EX_1, EX_2, EX_3
#define __QUERTY_R4__ EX_4, EX_5, XXXX, XXXX, XXXX, S_MI

#define __SYMBOL_L1__ KC_BSLS, KC_EXLM, KC_AMPR, KC_PIPE, ____
#define __SYMBOL_L2__ KC_HASH, KC_GRV, KC_DQT, KC_QUOT, KC_TILD
#define __SYMBOL_L3__ ____, ____, KC_LCBR, KC_LBRC, KC_LPRN

#define __SYMBOL_R1__ ____, KC_EQL, KC_PLUS, KC_ASTR, KC_PERC
#define __SYMBOL_R2__ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DLR
#define __SYMBOL_R3__ KC_RPRN, KC_RBRC, KC_RCBR, KC_AT, KC_CIRC

#define __SYMBOL_L4__ KC_LCTL, KC_LGUI, KC_LALT, ____, ____, ____
#define __SYMBOL_R4__ ____, ____, ____, ____, ____, ____

#define __NUM_L1__ ____, KC_F2, KC_F3, KC_F4, KC_F5
#define __NUM_L2__ KC_1, KC_2, KC_3, KC_4, KC_5
#define __NUM_L3__ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define __NUM_R1__ ____, KC_EQL, KC_PLUS, KC_ASTR, KC_PERC
#define __NUM_R2__ KC_6, KC_7, KC_8, KC_9, KC_0
#define __NUM_R3__ KC_F11, KC_F12, ____, ____, ____

#define __NUM_L4__ ____, ____, ____, ____, ____, ____
#define __NUM_R4__ ____, ____, ____, ____, ____, ____

#define __NUM2_L1__ KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS
#define __NUM2_L2__ KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS
#define __NUM2_L3__ KC_BSPC, KC_P1, KC_P2, KC_P3, KC_PENT

#define __NUM2_R1__ ____, ____, ____, ____, ____
#define __NUM2_R2__ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_0
#define __NUM2_R3__ ____, ____, ____, ____, ____

#define __NUM2_L4__ ____, KC_P0, KC_PDOT, ____, ____, ____
#define __NUM2_R4__ ____, ____, ____, ____, ____, ____

#define __SP_L1__ RGB_TOG, RGB_MOD, RGB_RMOD, ____, ____
#define __SP_L2__ SCRL_DVD, SCRL_DVI, CPI_D100, CPI_I100, ____
#define __SP_L3__ ____, ____, ____, ____, ____

#define __SP_R1__ RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN
#define __SP_R2__ RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_M_TW
#define __SP_R3__ ____, ____, ____, ____, ____

#define __SP_L4__ QK_BOOT, KBC_RST, EE_CLR, ____, ____, ____
#define __SP_R4__ ____, ____, ____, ____, KBC_RST, QK_BOOT

#define __MOUSE_L1__ ____, KC_F7, KC_F8, KC_F9, KC_F10
#define __MOUSE_L2__ ____, KC_F4, KC_F5, KC_F6, KC_F11
#define __MOUSE_L3__ ____, KC_F1, KC_F2, KC_F3, KC_F12

#define __MOUSE_R1__ ____, ____, ____, ____, ____
#define __MOUSE_R2__ ____, ____, ____, ____, ____
#define __MOUSE_R3__ ____, ____, ____, ____, ____

#define __MOUSE_L4__ XXXX, XXXX, XXXX, XXXX, XXXX, XXXX
#define __MOUSE_R4__ XXXX, XXXX, XXXX, XXXX, XXXX, XXXX


#define LAYOUT_wrapper(...) LAYOUT_no_ball(__VA_ARGS__)
