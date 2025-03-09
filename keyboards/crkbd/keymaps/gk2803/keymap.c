#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUM 1
#define _SYM 2
#define _WM 3


/* the modifiers argument to the One Shot Modifier (OSM) must be prefixed with MOD_ instead of KC_  */
/* OSM means you can tap the modifier once and it will be held until the next keystroke */
#define my_CTRL OSM(MOD_LCTL | MOD_RCTL)
#define my_SFT OSM(MOD_LSFT | MOD_RSFT)
#define my_ALT OSM(MOD_LALT | MOD_RALT)

/*
  Layer Tap (LT): LT(layer, KC), layer on hold, KC on tap
https://docs.qmk.fm/feature_layers
*/
#define my_SPC LT(_SYM, KC_SPC)
#define my_ENT LT(_NUM, KC_ENT)



     

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
     [_BASE] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.           ,-----------------------------------------------------------.
     KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_T,           KC_PGUP,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     KC_TAB ,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_T,           KC_PGDN,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     my_SFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  my_SFT,
  //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+-----|
                                          my_ALT, my_CTRL,  my_SPC,              my_ENT, OSL(_WM), my_ALT
                                      //`--------------------------'             `--------------------------'

  ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,-------------------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_T,            KC_T,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
       KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_T,            KC_T,     XXXXXXX, XXXXXXX, KC_UP,  XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,           KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'          `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
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

    [_WM] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------.            ,------------------------------------------------------------.
      KC_TAB, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3),  LGUI(KC_4), LGUI(KC_5),  KC_T,            KC_T,     LGUI(KC_6), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
    LGUI(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_T,            KC_T,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,           KC_ENT, _______, KC_RALT
                                      //`--------------------------'          `--------------------------'
  )
};


/*
  Gui acts as gui on hold and as one shot layer on tap
  First I've tried
  #define my_GUI MT(MOD_LGUI, OSL(_NUM))
  But this doesn't work as MT needs a KC as the tapping key
  and OSL isn't a valid key code for the MT function

  The above functionality can be achieved by a simple function
  recommended at the official qmk discord server by user sigprof. 
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSL(_WM):  // Override hold behavior for OSL(_NUM)
            if (!record->tap.count) {  // If it's a hold action
                if (record->event.pressed) {
                    register_code(KC_LGUI);  // Hold = GUI
                } else {
                    unregister_code(KC_LGUI);
                }
                return false;  // Prevent QMK from running its default OSL code
            }
            return true;  // Tap = Normal OSL behavior
    }
    return true;  // Let other keys behave normally
}   
