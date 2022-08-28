/*
  Copyright (c) 2020 Fred Silberberg

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#include QMK_KEYBOARD_H

// layer declarations
enum custom_layers {
    _MATT = 0,
    _SYMBOL = 1,
  _NUMBER = 2,
};

// define song
#ifdef AUDIO_ENABLE
float tone_zelda[][2] = SONG(ZELDA_TREASURE);
#endif

enum custom_keycodes {
  INV_1P = SAFE_RANGE,
};

// define keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case INV_1P:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_X) SS_UP(X_LCTL) SS_UP(X_LSFT) SS_DELAY(500) "secret" SS_DELAY(100) SS_TAP(X_ENT));
      }
      return false;
    default:
      return true;
  }
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MATT] = LAYOUT_5x6_5(
    KC_ESC,      KC_1,   KC_2,     KC_3,      KC_4,     KC_5,                                   KC_6,    KC_7,    KC_8,         KC_9,      KC_0,      KC_PSCR,
    KC_TAB,      KC_Q,   KC_W,     KC_E,      KC_R,     KC_T,                                   KC_Y,    KC_U,    KC_I,         KC_O,      KC_P,      KC_UNDS,
    KC_CAPS,     KC_A,   KC_S,     KC_D,      KC_F,     KC_G,                                   KC_H,    KC_J,    KC_K,         KC_L,      KC_SCLN,   KC_QUOT,
    KC_LSFT,     KC_Z,   KC_X,     KC_C,      KC_V,     KC_B,                                   KC_N,    KC_M,    KC_COMM,      KC_DOT,    KC_SLSH,   KC_RSFT,
                         KC_LWIN,  KC_LALT,   KC_SPC,   KC_BSPC,     KC_LCTL,      KC_RCTL,     KC_DEL,  KC_ENT,  KC_RALT,      KC_RWIN,
                                                        TT(_SYMBOL), TT(_NUMBER),  TT(_NUMBER), TT(_SYMBOL)
  ),

  [_SYMBOL] = LAYOUT_5x6_5(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,                     KC_F7,    KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,                   KC_CIRC,  KC_AMPR,    KC_ASTR,    KC_SLSH,    KC_BSLS,    KC_PIPE,
    KC_NO,   KC_LT,   KC_LBRC, KC_LCBR,  KC_LPRN, KC_NO,                     KC_NO,    KC_RPRN,    KC_RCBR,    KC_RBRC,    KC_GT,      KC_NO,
    KC_LSFT, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                     KC_PLUS,  KC_MINS,    KC_EQL,     KC_TILD,    KC_QUES,    KC_NO,
                      KC_NO,   KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NUMBER] = LAYOUT_5x6_5(
    KC_NO,    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,   KC_PSLS,   KC_PAST,   KC_PMNS,  KC_NO,
    KC_NO,    KC_NO,  KC_NO,    KC_UP,    KC_NO,    KC_PGUP,                      KC_NO,    KC_P7,   KC_P8,     KC_P9,     KC_PPLS,  KC_NO,
    KC_NO,    KC_NO,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,                      KC_PDOT,  KC_P4,   KC_P5,     KC_P6,     KC_PCMM,  KC_NO,
    KC_TRNS,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_P0,    KC_P1,   KC_P2,     KC_P3,     KC_PEQL,  KC_NO,
                      KC_NO,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_ENT,   KC_P0,   KC_TRNS,   KC_NO,
                                                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

};

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_WHITE}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 20, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _MATT));
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUMBER));
    return state;
}