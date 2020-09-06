#include "ergoboda.h"


enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
};

enum combo_events {
  SD_COMBO,
  DF_COMBO,
  FJ_COMBO,
  JK_COMBO,
  KL_COMBO,
  MCOMMA_COMBO,
  COMMADOT_COMBO,
};

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM mco_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM codo_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SD_COMBO] = COMBO_ACTION(sd_combo),
  [DF_COMBO] = COMBO(df_combo, KC_TAB),
  [FJ_COMBO] = COMBO_ACTION(fj_combo),
  [JK_COMBO] = COMBO(jk_combo, KC_ESC),
  [KL_COMBO] = COMBO_ACTION(kl_combo),
  [MCOMMA_COMBO] = COMBO(mco_combo, KC_WWW_BACK),
  [COMMADOT_COMBO] = COMBO(codo_combo, KC_WWW_FORWARD),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SD_COMBO:
      if (pressed) {
        tap_code16(LCTL(KC_LEFT));
      }
      break;
    case FJ_COMBO:
      if (pressed) {
        tap_code16(LCTL(KC_BSPACE));
      }
      break;
    case KL_COMBO:
      if (pressed) {
        tap_code16(LCTL(KC_LEFT));
      }
      break;
  }
}

#define _QW 0
#define _RS 1
#define _NF 2
#define _NV 3
#define _SY 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_eb_4x6(  // QWERTY base layer
    OSM(MOD_LGUI),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           OSM(MOD_LALT),
    OSM(MOD_LCTL),  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                           KC_H,           KC_J,           KC_K,           KC_L,           KC_COLN,        OSM(MOD_RCTL),
    KC_CAPSLOCK,    KC_Z,           HYPR_T(KC_X),   KC_C,           KC_V,           KC_B,                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TO(_RS),
                                    TT(_NV),        OSL(_SY),       KC_ENTER,       OSM(MOD_LSFT),                  KC_BSPACE,      KC_SPACE,       OSL(_SY),       TT(_NF)
  ),
  [_RS] = LAYOUT_eb_4x6(  // RSTHD layout
    _______,        KC_J,           KC_C,           KC_Y,           KC_F,           KC_K,                           KC_Z,           KC_L,           KC_COMMA,       KC_U,           KC_Q,           _______,
    _______,        KC_R,           KC_S,           KC_T,           KC_H,           KC_P,                           KC_W,           KC_N,           KC_A,           KC_I,           KC_O,           _______,
    _______,        KC_ENTER,       KC_V,           KC_G,           KC_D,           KC_B,                           KC_X,           KC_M,           KC_DOT,         KC_QUOTE,       KC_QUES,        TO(_QW),
                                    _______,        _______,        KC_E,           _______,                        _______,        _______,        _______,        _______
  ),
  [_NF] = LAYOUT_eb_4x6(  // Numpad & Function keys
    KC_F11,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                          KC_RPRN,        KC_7,           KC_8,           KC_9,           KC_COMMA,       _______,
    _______,        KC_BSLASH,      KC_E,           KC_MINUS,       KC_PLUS,        KC_ASTR,                        KC_TAB,         KC_4,           KC_5,           KC_6,           KC_DOT,         KC_BSPACE,
    KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,                         KC_LPRN,        KC_1,           KC_2,           KC_3,           KC_ENTER,       _______,
                                    _______,        _______,        _______,        _______,                        KC_0,           _______,        _______,        _______
  ),
  [_NV] = LAYOUT_eb_4x6(  // Navigation
    RESET,          KC_MEDIA_PLAY_PAUSE,KC_SYSTEM_SLEEP,KC_INSERT,  KC_PSCREEN,     MAGIC_TOGGLE_NKRO,              _______,        KC_HOME,        KC_END,         KC_TAB,         KC_ESC,         _______,
    _______,        LCTL(KC_Z),     ST_MACRO_5,     LCTL(KC_INSERT),LSFT(KC_INSERT),KC_AUDIO_MUTE,                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_DELETE,      _______,
    _______,        KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,_______,              _______,        KC_PGDOWN,      KC_PGUP,        ST_MACRO_0,     ST_MACRO_2,     _______,
                                    _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______
  ),
  [_SY] = LAYOUT_eb_4x6(  // Symbols
    _______,        KC_GRAVE,       KC_ASTR,        KC_LBRACKET,    KC_RBRACKET,    KC_PERC,                        KC_PIPE,        KC_QUES,        KC_EXLM,        KC_HASH,        KC_CIRC,        _______,
    _______,        KC_SLASH,       KC_EQUAL,       KC_LPRN,        KC_RPRN,        KC_UNDS,                        KC_BSLASH,      KC_QUOTE,       KC_DQUO,        KC_MINUS,       KC_COLN,        _______,
    _______,        KC_PLUS,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_DLR,                         KC_TILD,        KC_AMPR,        KC_COMMA,       KC_DOT,         KC_SCOLON,      _______,
                                    _______,        _______,        _______,        _______,                        _______,        _______,        _______,        _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(50) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50) SS_TAP(X_W)  SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(50) SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(50) SS_TAP(X_Q)  SS_DELAY(50) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_0) SS_DELAY(50) SS_TAP(X_X));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_0) SS_DELAY(50) SS_TAP(X_B));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_E) SS_DELAY(50) SS_TAP(X_MINUS));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_INSERT)) SS_DELAY(50) SS_TAP(X_DELETE));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(50) SS_TAP(X_QUOTE) SS_DELAY(50) SS_TAP(X_QUOTE));

    }
    break;
  }
  return true;
}

#define _RLED F5
#define _GLED F6
#define _BLED B5

void keyboard_pre_init_user(void) {
	setPinOutput(_RLED);
	setPinOutput(_GLED);
	setPinOutput(_BLED);
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  // Set all LED states to OFF
  writePinLow(_RLED);
  writePinLow(_GLED);
  writePinLow(_BLED);
  switch (layer) {
    case 1:
      writePinHigh(_RLED);
      break;
    case 2:
      writePinHigh(_GLED);
      break;
    case 3:
      writePinHigh(_BLED);
      break;
    case 4:
      writePinHigh(_RLED);
      writePinHigh(_GLED);
      break;
    case 5:
      writePinHigh(_RLED);
      writePinHigh(_BLED);
      break;
    case 6:
      writePinHigh(_GLED);
      writePinHigh(_BLED);
      break;
    case 7:
      writePinHigh(_RLED);
      writePinHigh(_GLED);
      writePinHigh(_BLED);
      break;
    default:
      break;
  }
  return state;
};
