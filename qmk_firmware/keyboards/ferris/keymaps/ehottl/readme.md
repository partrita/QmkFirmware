# The keyboard

This layout is made almost entirely from [miryoku](https://github.com/manna-harbour/miryoku). However, I used fewer layers and reduced 36 keys to 34.

> As little as possible, as simple as possible, as easy as possible to memorize

Replaced the Ctrl, GUI, Alt, and Shift keys with home mod row. A combo function was added by removing some RGB animations of the bm40's keyboard to free up memory. If animation is not removed, it is because there is not enough memory to compile. Added code that uses RGB matrix animation so that you can see at a glance which layer is being used, and you can move faster by increasing the speed of the mouse key. 

And because I'm Korean, a combo for Korean and English keyboard conversion has been added, but if you don't need it, you can delete it.


- Flash:

  `qmk flash -kb ferris/sweep -km ehottl`

# Layout

![](https://raw.githubusercontent.com/partrita/myKeyboard/main/qmk_firmware/keyboards/ferris/keymaps/mysweep.png)


```
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [Base] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_Q, KC_W, KC_E, KC_R, KC_T,                                 KC_Y, KC_U, KC_I, KC_O, KC_P,
        // ---------------------------------------------              ----------------------------------------------
        KC_A, KC_S, KC_D, KC_F, KC_G,                                 KC_H, KC_J, KC_K, KC_L, KC_QUOT,
        // ---------------------------------------------              ----------------------------------------------
        H_Z, H_X, TD(DANCE_02), H_V, KC_B,                            KC_N, H_M, H_COM, H_DOT, H_SLS, 
        // ---------------------------------------------              ----------------------------------------------
                                          NAVI, FUNC,                 KC_BSPC, NUMB
        // ---------------------------------------------              ----------------------------------------------
        ),
    
    [Navi] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_ESC,                   KC_DEL, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        // ---------------------------------------------              ----------------------------------------------
        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TAB,                   KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        // ---------------------------------------------              ----------------------------------------------
        H_Z, H_X, H_C, H_V, KC_BTN1,                                  KC_BTN2, H_M, H_COM, H_DOT, H_SLS,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_NO, FUNC,                 KC_BSPC, KC_HAEN
        // ---------------------------------------------              ----------------------------------------------
        ),

    [Numb] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                           KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                            KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO,
        // ---------------------------------------------              ----------------------------------------------
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                            KC_NO, H_M, H_COM, H_DOT, H_SLS,
        // ---------------------------------------------              ----------------------------------------------
                                         KC_0, KC_MINS,               KC_BSPC, KC_NO
        // ---------------------------------------------              ----------------------------------------------
        ),
    
    [Func] = LAYOUT(
        // ---------------------------------------------              ----------------------------------------------
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                         RESET, DT_PRNT, DT_DOWN, DT_UP, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,                         KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, 
        // ---------------------------------------------              ----------------------------------------------
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                         KC_INS, H_M, H_COM, H_DOT, H_SLS, 
        // ---------------------------------------------              ----------------------------------------------
                                         KC_NO, FUNC,                 KC_BSPC, KC_HAEN
        // ---------------------------------------------              ----------------------------------------------
        ),
};
```