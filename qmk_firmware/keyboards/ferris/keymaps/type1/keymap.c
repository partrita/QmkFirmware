#include QMK_KEYBOARD_H

enum ferris_layers {
    _QWERTY,
    _Mouse,
    _NUM,
    _FUNC,
    _LEFT,
    _RIGHT,
};


// home row mods - Base Layer
#define H_A LCTL_T(KC_A)
#define H_X LGUI_T(KC_X)
#define H_C LALT_T(KC_C)
#define H_V LSFT_T(KC_V)
#define H_M  LSFT_T(KC_M)
#define H_COM  LALT_T(KC_COMM)
#define H_DOT  LGUI_T(KC_DOT)
#define H_SCL  LCTL_T(KC_SCLN)

// layer keys
#define FUNC LT(_FUNC, KC_SPC)
#define MOUSE LT(_Mouse, KC_LALT)
#define NUMB MO(_NUM)

// combo key
enum combo_events {
  RIGHT_THUMB,
  LEFT_THUMB,
  KOR,
};

// combo key
const uint16_t PROGMEM right_thumb_combo[] = {KC_BSPC, NUMB, COMBO_END};
const uint16_t PROGMEM left_thumb_combo[] = {MOUSE, FUNC, COMBO_END};
const uint16_t PROGMEM kor[] = {FUNC, KC_BSPC, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [RIGHT_THUMB] = COMBO(right_thumb_combo, MO(_RIGHT)),
  [LEFT_THUMB] = COMBO(left_thumb_combo, MO(_LEFT)),
  [KOR] = COMBO(kor, KC_LNG1),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                 KC_Y, KC_U, KC_I, KC_O, KC_P,
        // ---------------------------------------------              ----------------------------------------------
        H_A, KC_S, KC_D, KC_F, KC_G,                                  KC_H, KC_J, KC_K, KC_L, H_SCL,
        // ---------------------------------------------              ----------------------------------------------
        KC_Z, H_X, H_C, H_V, KC_B,                                    KC_N, H_M, H_COM, H_DOT, KC_SLSH, 
        // ---------------------------------------------              ----------------------------------------------
                                          MOUSE, FUNC,                KC_BSPC, NUMB
        // ---------------------------------------------              ----------------------------------------------
        ),
    
    [_Mouse] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_TAB, KC_WH_U, KC_MS_U, KC_WH_D, KC_ESC,                    KC_DEL, KC_HOME, KC_BTN3, KC_END, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        H_A, KC_MS_L, KC_MS_D, KC_MS_R, KC_TAB,                       KC_ENT, KC_BTN1, KC_ACL2, KC_BTN2, H_SCL,
        // ---------------------------------------------              ----------------------------------------------
        KC_Z, H_X, H_C, H_V, KC_B,                                    KC_N, H_M, H_COM, H_DOT, KC_SLSH,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_NO, KC_LNG1,               KC_BSPC, KC_LNG1
        // ---------------------------------------------              ----------------------------------------------
        ),

    [_NUM] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                           KC_DEL, KC_HOME, KC_UP, KC_END, KC_PGUP,
        // ---------------------------------------------              ----------------------------------------------
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                            KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        // ---------------------------------------------              ----------------------------------------------
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                            KC_N, H_M, H_COM, H_DOT, KC_SLSH,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_0, KC_MINS,               KC_BSPC, KC_NO
        // ---------------------------------------------              ----------------------------------------------
        ),
    
    [_FUNC] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        A(KC_Q), A(KC_W), A(KC_E), A(KC_R), A(KC_T),                  A(KC_Y), A(KC_U), A(KC_I), A(KC_O), A(KC_P), 
        // ---------------------------------------------              ----------------------------------------------
        A(KC_A), A(KC_S), A(KC_D), A(KC_F), A(KC_G),                  A(KC_H), A(KC_J), A(KC_K), A(KC_L), KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        A(KC_Z), A(KC_X), A(KC_C), A(KC_V), A(KC_B),                  A(KC_N), A(KC_M), KC_NO, KC_NO, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_LCTL, KC_NO,                                               KC_LSFT, KC_LNG1
        // ---------------------------------------------              ----------------------------------------------
        ),
    [_LEFT] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                         QK_BOOT, DT_PRNT, DT_DOWN, DT_UP, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                         KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                         KC_INS, KC_NO, KC_NO, KC_NO, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_NO, FUNC,                                                  KC_BSPC, KC_LNG1
        // ---------------------------------------------              ----------------------------------------------
        ),
    [_RIGHT] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                         QK_BOOT, DT_PRNT, DT_DOWN, DT_UP, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                         KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                         KC_INS, KC_NO, KC_NO, KC_NO, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_NO, FUNC,                                                  KC_BSPC, KC_LNG1
        // ---------------------------------------------              ----------------------------------------------
        ),
        
};
