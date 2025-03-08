#include QMK_KEYBOARD_H

#define _MAIN 0
#define _EXT 1
#define _FN 2
#define _TODO 3

#define my_CTRL OSM(MOD_LCTL | MOD_RCTL)
#define my_SHFT OSM(MOD_LSFT | MOD_RSFT)
#define my_ALT OSM(MOD_LALT | MOD_RALT)
#define my_GUI OSM(MOD_LGUI | MOD_RGUI)
#define my_CA OSM(MOD_LCTL | MOD_LALT)
#define my_SPC LT(_EXT,KC_SPC)
#define my_ENT LT(_EXT,KC_ENT)

enum
{
    TD_ESC_CAPS,
};

tap_dance_action_t tap_dance_actions[] =
{
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};
     

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
     [0] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.           ,-----------------------------------------------------------.
     KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_T,           KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_T,           KC_T,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+-----|
                                          my_ALT, my_CTRL,  my_SPC,              my_ENT, my_CTRL, my_ALT
                                      //`--------------------------'             `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,-------------------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_T,            KC_T,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_T,            KC_T,      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,           KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'          `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,------------------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,   KC_T,            KC_T,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_T,            KC_T,     KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,           KC_ENT, _______, KC_RALT
                                      //`--------------------------'          `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,------------------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,   KC_T,            KC_T,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_T,            KC_T,     KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,           KC_ENT, _______, KC_RALT
                                      //`--------------------------'          `--------------------------'
  )
};

