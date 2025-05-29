#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUM 1
#define _SYM 2
#define _FK 3


/* the modifiers argument to the One Shot Modifier (OSM) must be prefixed with MOD_ instead of KC_  */
/* OSM means you can tap the modifier once and it will be held until the next keystroke */


#define my_CTRL OSM(MOD_LCTL | MOD_RCTL)
#define my_SFT OSM(MOD_LSFT | MOD_RSFT)
#define my_ALT OSM(MOD_LALT | MOD_RALT)


/* #define hrm_GUI LGUI_T(KC_QUOT) */

/* LT stands for Layer tapping. So LT_QUOTE is used as a layer on hold and as a quote
 character on tap.
I get some false when using this key. For example when fast typing the word "don't",
it will trigger the Layer _WM and make my screen change to another pane.*/


#define LT_NUM_ENT LT(_NUM, KC_ENT)
#define LT_SYM_SP LT(_SYM, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
     [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.           ,-----------------------------------------------------------.
     KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PGUP,         KC_CAPS,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     KC_TAB ,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGDN,          KC_T,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     my_SFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  my_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+-----|
                                        KC_LGUI, my_CTRL,  LT_SYM_SP,              LT_NUM_ENT, my_ALT, MO(_FK)
                                      //`--------------------------'             `--------------------------'

  ), 

    [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,-------------------------------------------------------------.
       KC_TAB,XXXXXXX,XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,            KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
       KC_LCTL, KC_1,   KC_2,   KC_3,    KC_4,      KC_5,   XXXXXXX,            KC_T,    XXXXXXX,  KC_6,    KC_7,    KC_8,   KC_9,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, KC_0,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,           KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'          `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,------------------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, KC_PIPE,  KC_BSLS, XXXXXXX,   XXXXXXX,        KC_T,     KC_AMPR, KC_CIRC, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_EXLM, KC_AT, KC_HASH, KC_DLR, XXXXXXX,   XXXXXXX,            KC_T,     KC_MINS,  KC_UNDS, KC_LCBR, KC_RCBR, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TILD, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,           KC_ENT, _______, KC_RALT
                                      //`--------------------------'          `--------------------------'
  ),
    
    /* https://docs.qmk.fm/feature_advanced_keycodes */

    [_FK] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,------------------------------------------------------------.
       KC_TAB, KC_F1,  KC_F2,   KC_F3 ,  KC_F4, XXXXXXX,   XXXXXXX,        KC_T,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_F5,  KC_F6,  KC_F7 ,   KC_F8, XXXXXXX,   XXXXXXX,        KC_T,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F9,  KC_F10, KC_F11,   KC_F12, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,           KC_ENT, _______, KC_RALT
                                      //`--------------------------'          `--------------------------'
  )
};


/*
  Gui acts as gui on hold and as one shot layer KC_tap
  FirKC I've tried
  #define my_GUI MT(MOD_LGUI, OSL(_NUM))
  But this doesn't work as MT needs a KC as the tapping key
  and OSL isn't a valid key code for the MT function

  The above functionality can be achieved by a simple function
  recommended at the official qmk discord server by user sigprof. 
 */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case OSL(_WM):  // Override hold behavior for OSL(_NUM) */
/*             if (!record->tap.count) {  // If it's a hold action */
/*                 if (record->event.pressed) { */
/*                     register_code(KC_LGUI);  // Hold = GUI */
/*                 } else { */
/*                     unregister_code(KC_LGUI); */
/*                 } */
/*                 return false;  // Prevent QMK from running its default OSL code */
/*             } */
/*             return true;  // Tap = Normal OSL behavior */
/*     } */
/*     return true;  // Let other keys behave normally */
/* } */

