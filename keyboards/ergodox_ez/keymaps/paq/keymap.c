#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0  // default layer
#define SYMB 1  // symbols
#define MDIA 2  // media keys

#define JIS_MINS KC_MINS  // - and =
#define JIS_CIRC KC_EQL   // ^ and ~
#define JIS_JYEN KC_JYEN  // \ and |
#define JIS_ATMK KC_LBRC  // @ and `
#define JIS_LBRC KC_RBRC  // [ and {
#define JIS_SCLN KC_SCLN  // ; and +
#define JIS_COLN KC_QUOT  // : and *
#define JIS_RBRC KC_BSLS  // ] and }
#define JIS_COMM KC_COMM  // , and <
#define JIS_DOT KC_DOT    // . and >
#define JIS_SLSH KC_SLSH  // / and ?
#define JIS_BSLS 0x87     // \ and _

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

enum macros { T_EISU = 0, T_KANA };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | ESC    |   1  |   2  |   3  |   4  |   5  | Del  |           | Del  |   6  |   7  |   8  |   9  |   0  |   ¥|   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  | Enter|           | Bspc |   Y  |   U  |   I  |   O  |   P  |   @`   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |  -=    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |  [{  |           |  ]}  |   N  |   M  |  ,<  |  .>  |  /?  |  _     |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |LCtrl | LAlt | LGui | ZKHK |  L1  |                                       |  :*  |  ^~  | LGui | LAlt |RCtrl |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |LCtrl | LAlt |       | RAlt | RShift |
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      | MHEN |       | HENK |        |      |
     *                                 | Space|LShift|------|       |------|  L1    |Enter |
     *                                 |      |      | LGui |       |  L2  |        |      |
     *                                 `--------------------'       `----------------------'
     */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = KEYMAP(  // layer 0 : default
                      // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_ENT, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, JIS_LBRC, KC_LCTL, KC_LALT, KC_LGUI, KC_ZKHK, MO(SYMB), KC_LCTL, KC_LALT, M(T_EISU), KC_SPC, KC_LSFT, KC_LGUI,
        // right hand
        KC_DEL, KC_6, KC_7, KC_8, KC_9, KC_0, JIS_JYEN, KC_BSPC, KC_Y, KC_U, KC_I, KC_O, KC_P, JIS_ATMK, KC_H, KC_J, KC_K, KC_L, JIS_SCLN, JIS_MINS, JIS_RBRC, KC_N, KC_M, JIS_COMM, JIS_DOT, JIS_SLSH, S(JIS_BSLS), JIS_COLN, JIS_CIRC, KC_RGUI, KC_RALT, KC_RCTL, KC_RALT, KC_RSFT, M(T_KANA), MO(MDIA), MO(SYMB), KC_ENT),
    /* Keymap 1: Symbol Layer
     *
     * ,---------------------------------------------------.           ,--------------------------------------------------.
     * | RESET   |  F1  |  F2  |  F3  |  F4  |  F5  | App  |           | PSCR |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
     * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |         |      |  Up  |  ,<  |  .>  |  /?  |      |           | Left |      | Home |      |End   |      |   F12  |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         | Left | Down | Right|  :*  |  ^~  |------|           |------| Left | Down |  Up  |Right |      |        |
     * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |         |      |      |      |      |      |      |           |      |      | PgDn | PgUp |      |      |        |
     * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |       |      |      |      |      |                                       |      |      |      |      |        |
     *   `-----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    // SYMBOLS
    [SYMB] = KEYMAP(
        // left hand
        RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_APP, _______, _______, KC_UP, JIS_COMM, JIS_DOT, JIS_SLSH, XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, JIS_COLN, JIS_CIRC, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // right hand
        KC_PSCR, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_LEFT, XXXXXXX, KC_HOME, XXXXXXX, KC_END, XXXXXXX, KC_F12, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* Keymap 2: Media and mouse keys
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      | Lclk | Rclk |      |      |  Play  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |       |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    // MEDIA AND MOUSE
    [MDIA] = KEYMAP(_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    // right hand
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MPLY, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______),
};

void type_code(uint8_t keycode) {
    register_code(keycode);
    unregister_code(keycode);
};

void set_eisu(void) {
    type_code(KC_MHEN);
    type_code(KC_LANG2);
};

void set_kana(void) {
    type_code(KC_HENK);
    type_code(KC_LANG1);
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch (id) {
        case T_EISU:
            if (record->event.pressed) {
                set_eisu();
            }
            break;
        case T_KANA:
            if (record->event.pressed) {
                set_kana();
            }
            break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
#endif
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void){

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#else
#    ifdef RGBLIGHT_ENABLE
            rgblight_init();
#    endif
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        default:
            break;
    }

    return state;
};
