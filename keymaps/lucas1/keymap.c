#include QMK_KEYBOARD_H
#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Helpful defines

enum nyquist_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum nyquist_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

 //Tap Dance Declarations
 enum {
   TD_QUOT_ENT = 0
 };
 
 //Tap Dance Definitions
 qk_tap_dance_action_t tap_dance_actions[] = {
   [TD_QUOT_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_ENT)
 // Other declarations would go here, separated by commas, if you have them
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT_ortho_5x12 (KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_RGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, TD(TD_QUOT_ENT), KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_LCTL, KC_LGUI, SCMD_T(KC_LALT), LGUI_T(KC_MUTE), LT(1, KC_ENT), RSFT_T(KC_SPC), RSFT_T(KC_SPC), LT(2, KC_ENT), KC_DOWN, KC_UP, KC_LEFT, KC_RGHT),
	[_LOWER] = LAYOUT_ortho_5x12 (KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MI_ON, MI_OFF, KC_NO, KC_GRV, KC_MINS, KC_EQL, KC_CAPS, KC_NO, CK_TOGG, CK_UP, CK_DOWN, CK_RST, KC_NO, KC_NO, KC_UP, KC_LBRC, KC_RBRC, KC_BSLS, KC_LSFT, KC_NO, MU_ON, MU_MOD, MU_OFF, MU_TOG, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_PGDN, KC_PGUP, KC_VOLD, KC_VOLU),
	[_RAISE] = LAYOUT_ortho_5x12 (KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_CAPS, KC_NO, KC_SYSTEM_SLEEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_P0, KC_ENT),
	[_ADJUST] = LAYOUT_ortho_5x12 (KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
