# The 34 keymap for ferris keyboards

This layout is made almost entirely from [miryoku](https://github.com/manna-harbour/miryoku). However, I used fewer layers and reduced 36 keys to 34.

> As little as possible, as simple as possible, as easy as possible to memorize

Replaced the Ctrl, GUI, Alt, and Shift keys with home mod row. A combo function was added by removing some RGB animations of the bm40's keyboard to free up memory. If animation is not removed, it is because there is not enough memory to compile. Added code that uses RGB matrix animation so that you can see at a glance which layer is being used, and you can move faster by increasing the speed of the mouse key. 

And because I'm Korean, a combo for Korean and English keyboard conversion has been added, but if you don't need it, you can delete it.


- Flash:

  `qmk flash -kb ferris -km 34keys`

# Layout

Press and hold to activate the keys in parentheses.

## _BASE(QWERTY)

| Q | W | E | R | T | | | Y | U | I | O | P | 
|---|---|---|---|---|---|---|---|---|---|---|---|
| A(Shift) | S(Ctrl) | D(Win) | F(Alt) |  G | |  | H | J(Alt) | K(Win)  | L(Ctrl) | '(Shift) |
| Z | X| C| V| B| | | N | M | , | . | /|
| | | | NaviLayer| Space(_Func) | | | Backspace | NumberLayer | | | |  

## _Navi

| Mousewheel left | Mousewheel down | Mousewheel up | Mousewheel right | ESC | | | DEL | HOME | PageDown | PageUP | END | 
|---|---|---|---|---|---|---|---|---|---|---|---|
| A(Shift) | S(Ctrl) | D(Win) | F(Alt) |  TAB | |  | ENTER | J(Alt) | K(Win)  | L(Ctrl) | '(Shift) |
| Mouse left | Mouse down | Mouse up| Mouse right | left click | | | left click | Left | Down | Up | Right |
| | | |  | Space | | | Backspace | NumberLayer | | | |  

## _Numb

| [ | 7 | 8 | 9 | ] | | | DEL |  |  |  |  | 
|---|---|---|---|---|---|---|---|---|---|---|---|
| ; | 4 | 5 | 6 | = | |  | ENTER | J(Alt) | K(Win)  | L(Ctrl) | '(Shift) |
| ` |  1 | 2 | 3 | \ | | |  |  |  |  | |
| | | | 0|  - | | | Backspace | | | | |  

## _Func

| F12 | F7 | F8 | F9 | PrintScreen | | | RESET |  |  |  |  | 
|---|---|---|---|---|---|---|---|---|---|---|---|
| F11 | F4 | F5 | F6 | ScrollLock | |  | CapsLock | J(Alt) | K(Win)  | L(Ctrl) | '(Shift) |
| F10 |  F1 | F2 | F3 | PauseBreak | | | Insert |  |  |  | |
| | | | NaviLayer | Space | | | Backspace | NumberLayer | | | |  
