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

// enum ferris_tap_dances {
//   TD_Q_ESC
// };

// Left-hand home row mods - Base Layer
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)
#define HOME_J LALT_T(KC_J)
#define HOME_K LGUI_T(KC_K)
#define HOME_L LCTL_T(KC_L)
#define HOME_QU RSFT_T(KC_QUOT)

// layer keys
#define Lay_SPC LT(_Func,KC_SPC)
#define NAVI MO(_Navi)
#define NUMB MO(_Numb)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_Base] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    HOME_A, HOME_S,    HOME_D,    HOME_F,    KC_G,       KC_H,    HOME_J,  HOME_K,    HOME_L,      HOME_QU,
    KC_Z, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                    NAVI, Lay_SPC,  KC_BSPC,       NUMB
  ),

  [_Navi] = LAYOUT(
      KC_WH_L,    KC_WH_D,   KC_WH_U,        KC_WH_R,        KC_ESC,           KC_DEL,   KC_HOME,  KC_PGDN,   KC_PGUP,      KC_END,
      HOME_A,     HOME_S,    HOME_D,         KC_LSFT,        KC_TAB,           KC_ENT,    KC_RSFT,   HOME_K,    HOME_L,     HOME_QU,
      KC_MS_L,    KC_MS_D,   KC_MS_U,        KC_MS_R,       KC_BTN1,          KC_BTN2,   KC_LEFT,  KC_DOWN,     KC_UP,     KC_RGHT,    
                                    KC_NO,       Lay_SPC,                 KC_BSPC,       NUMB    
    ),
  [_Numb] = LAYOUT(
      KC_LBRC,        KC_7,     KC_8,          KC_9,        KC_RBRC,          KC_DEL,      KC_NO,     KC_NO,     KC_NO,       KC_NO,
      KC_SCLN,        KC_4,     KC_5,          KC_6,         KC_EQL,          KC_ENT,     KC_RSFT,    HOME_K,    HOME_L,     HOME_QU,
       KC_GRV,        KC_1,     KC_2,          KC_3,        KC_BSLS,           KC_NO,      KC_NO,     KC_NO,   KC_HAEN,       KC_NO,
                                     KC_0,        KC_MINS,              KC_BSPC,       KC_NO
      ),
  [_Func] = LAYOUT(
      KC_F12,     KC_F7,     KC_F8,           KC_F9,       KC_PSCR,            RESET,      KC_NO,     KC_NO,     KC_NO,     KC_NO,
      KC_F11,     KC_F4,     KC_F5,           KC_F6,       KC_SCRL,          KC_CAPS,     KC_RSFT,    HOME_K,    HOME_L,   HOME_QU,
      KC_F10,     KC_F1,     KC_F2,           KC_F3,       KC_PAUS,           KC_INS,      KC_NO,     KC_NO,   KC_HAEN,     KC_NO,
                                     KC_NO,       Lay_SPC,            KC_BSPC,      KC_NO
      )
};

// Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Q, twice for ESC
//     [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
// };


// modify `config.h` file
// by adding #define COMBO_COUNT 1 (replacing 1 with the number that you’re using).
// modify `rules.mk` file
// by adding # COMBO_ENABLE = yes 

enum combos {
  SFT_HAN,
  SAVE_COMBO,
};

const uint16_t PROGMEM sft_han_combo[] = {LSFT_T(KC_A), LT(_Func,KC_SPC), COMBO_END};
const uint16_t PROGMEM save_combo[] = {LCTL_T(KC_S), LGUI_T(KC_D), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SFT_HAN] = COMBO(sft_han_combo, KC_HAEN),
  [SAVE_COMBO] = COMBO_ACTION(save_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    // case EM_EMAIL:
    //   if (pressed) {
    //     SEND_STRING("john.doe@example.com");
    //   }
    //   break;
    case SAVE_COMBO:
      if (pressed) {
        tap_code16(C(KC_S));
      }
      break;
  }
}
