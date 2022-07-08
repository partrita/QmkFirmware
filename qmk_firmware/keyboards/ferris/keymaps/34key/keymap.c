
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
    _Base,
    _Navi,
    _Numb,
    _Func,
};

enum ferris_tap_dances {
    TD_C,
    TD_V,
    TD_X,
    TD_Z,
};

// Left-hand home row mods - Base Layer
#define H_Z LGUI_T(KC_Z)
#define H_X LALT_T(KC_X)
#define H_C LCTL_T(KC_C)
#define H_V LSFT_T(KC_V)
#define H_M RSFT_T(KC_M)
#define H_COM LCTL_T(KC_COMM)
#define H_DOT LALT_T(KC_DOT)
#define H_SLS LGUI_T(KC_SLSH)

// layer keys
#define Lay_SPC LT(_Func, KC_SPC)
#define NAVI MO(_Navi)
#define NUMB MO(_Numb)

// for tap dance
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define UNDO LCTL(KC_Z)

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, COPY),
    [TD_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, PASTE),
    [TD_X] = ACTION_TAP_DANCE_DOUBLE(KC_X, CUT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_Base] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,
    H_Z, H_X, H_C, H_V, KC_B, KC_N, H_M, H_COM, H_DOT, H_SLS,
    NAVI, Lay_SPC, KC_BSPC, NUMB),
  
  [_Navi] = LAYOUT(
    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ESC, KC_DEL, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TAB, KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
    KC_Z, TD(TD_X), TD(TD_C), TD(TD_V), KC_BTN1, KC_BTN2, H_M, H_COM, H_DOT, H_SLS,
    KC_NO, Lay_SPC, KC_BSPC, NUMB),
  
  [_Numb] = LAYOUT(
    KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_NO, H_M, H_COM, KC_HAEN, H_SLS,
    KC_0, KC_MINS, KC_BSPC, KC_NO),
                                                              
  [_Func] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, RESET, DT_PRNT, DT_DOWN, DT_UP, KC_NO,
    KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, KC_INS, H_M, H_COM, KC_HAEN, H_SLS,
    KC_NO, Lay_SPC, KC_BSPC, KC_NO),
  };

// modify `config.h` file
// by adding #define COMBO_COUNT 1 (replacing 1 with the number that you’re using).
// modify `rules.mk` file
// by adding # COMBO_ENABLE = yes

enum combos {
    KOR,
};

const uint16_t PROGMEM kor[] = {KC_BSPC, LT(_Func, KC_SPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [KOR] = COMBO(kor, KC_HAEN),
};
