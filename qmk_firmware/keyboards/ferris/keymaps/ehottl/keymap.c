#include QMK_KEYBOARD_H

enum ferris_layers {
    Base,
    Navi,
    Numb,
    Func,
};

enum tap_dance_codes {
  DANCE_01,
  DANCE_02,
};

// home row mods - Base Layer
#define H_Z LSFT_T(KC_Z)
#define H_X LCTL_T(KC_X)
#define H_C LGUI_T(KC_C)
#define H_V LALT_T(KC_V)
#define H_M  LALT_T(KC_M)
#define H_COM  LGUI_T(KC_COMM)
#define H_DOT  LCTL_T(KC_DOT)
#define H_SLS  LSFT_T(KC_SLSH)

// layer keys
#define FUNC LT(Func, KC_SPC)
#define NAVI MO(Navi)
#define NUMB MO(Numb)

// for tap dance
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define UNDO LCTL(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [Base] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                 KC_Y, KC_U, KC_I, KC_O, KC_P,
        // ---------------------------------------------              ----------------------------------------------
        KC_A, KC_S, KC_D, KC_F, KC_G,                                 KC_H, KC_J, KC_K, KC_L, KC_QUOT,
        // ---------------------------------------------              ----------------------------------------------
        H_Z, H_X, H_C, H_V, KC_B,                                     KC_N, H_M, H_COM, H_DOT, H_SLS, 
        // ---------------------------------------------              ----------------------------------------------
                                          NAVI, FUNC,                 KC_BSPC, NUMB
        // ---------------------------------------------              ----------------------------------------------
        ),
    
    [Navi] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_TAB, KC_WH_U, KC_MS_U, KC_WH_D, KC_ESC,                    KC_DEL, KC_HOME, KC_BTN3, KC_END, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_TAB,                   KC_ENT, KC_BTN1, KC_ACL2, KC_BTN2, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_LSFT, KC_CUT, KC_COPY, KC_PSTE, KC_NO,                     KC_NO, KC_RALT, KC_LGUI, KC_LCTL, KC_LSFT,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_NO, FUNC,                 KC_BSPC, KC_LNG1
        // ---------------------------------------------              ----------------------------------------------
        ),

    [Numb] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                           KC_DEL, KC_HOME, KC_UP, KC_END, KC_PGUP,
        // ---------------------------------------------              ----------------------------------------------
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                            KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        // ---------------------------------------------              ----------------------------------------------
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                            KC_NO, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_0, KC_MINS,               KC_BSPC, KC_NO
        // ---------------------------------------------              ----------------------------------------------
        ),
    
    [Func] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                         QK_BOOT, DT_PRNT, DT_DOWN, DT_UP, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                         KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                         KC_INS, KC_NO, KC_NO, KC_NO, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_NO, FUNC,                 KC_BSPC, KC_LNG1
        // ---------------------------------------------              ----------------------------------------------
        ),
};

// modify `config.h` file
// by adding #define COMBO_COUNT 1 (replacing 1 with the number that you’re using).
// modify `rules.mk` file
// by adding # COMBO_ENABLE = yes

enum combos {
    KOR,
};

const uint16_t PROGMEM kor[] = {KC_BSPC, LT(Func, KC_SPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [KOR] = COMBO(kor, KC_LNG1),
};


// Tapdance
extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

static tap dance_state = {
  .is_press_action = true,
  .step = 0
};

// DANCE_01
void on_dance_01(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_01_dance_step(qk_tap_dance_state_t *state);
void dance_01_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_01_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_01(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_X);
    tap_code16(KC_X);
    tap_code16(KC_X);
  }
  if(state->count > 3) {
    tap_code16(KC_X);
  }
}

uint8_t dance_01_dance_step(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
  if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}

void dance_01_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state.step = dance_01_dance_step(state);
  switch (dance_state.step) {
    case SINGLE_TAP: register_code16(KC_X); break;
    case SINGLE_HOLD: register_code16(KC_LALT); break;
    case DOUBLE_TAP: register_code16(CUT); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_X);
  }
}

void dance_01_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state.step) {
    case SINGLE_TAP: unregister_code16(KC_X); break;
    case SINGLE_HOLD: unregister_code16(KC_LALT); break;
    case DOUBLE_TAP: unregister_code16(CUT); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
  }
  dance_state.step = 0;
}

// DANCE_02
void on_dance_02(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_02_dance_step(qk_tap_dance_state_t *state);
void dance_02_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_02_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_02(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 3) {
    tap_code16(KC_C);
    tap_code16(KC_C);
    tap_code16(KC_C);
  }
  if(state->count > 3) {
    tap_code16(KC_C);
  }
}

uint8_t dance_02_dance_step(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}

void dance_02_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state.step = dance_02_dance_step(state);
  switch (dance_state.step) {
    case SINGLE_TAP: register_code16(KC_C); break;
    case SINGLE_HOLD: register_code16(KC_LCTL); break;
    case DOUBLE_TAP: register_code16(COPY); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_C);
  }
}

void dance_02_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state.step) {
    case SINGLE_TAP: unregister_code16(KC_C); break;
    case SINGLE_HOLD: unregister_code16(KC_LCTL); break;
    case DOUBLE_TAP: unregister_code16(COPY); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
  }
  dance_state.step = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [DANCE_01] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_01, dance_01_finished, dance_01_reset),
  [DANCE_02] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_02, dance_02_finished, dance_02_reset),
};

