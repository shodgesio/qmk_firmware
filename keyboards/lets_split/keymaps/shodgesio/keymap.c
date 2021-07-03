#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _QWERTY = 0,
  _COLEMAK = 1,
  _DVORAK = 2,
  _LOWER = 3,
  _RAISE = 4,
  _ADJUST = 16
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear

// keys in multiple locations:
//  - parenteses in both raise and lower
//  - asterix in raise and twice on lower (normal and numpad)
//  - minus/plus twice on lower (normal and numpad)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------   ------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------   -------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |   |Space |Raise |  GUI | Alt  | Pl/Ps| Next |
 * `------------------------------------------   ------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12 ( \
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,  \
  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_ENT,   \
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT , \
  ADJUST,   KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,   KC_SPC,  KC_SPC,  RAISE,  KC_RGUI,  KC_RALT,  KC_MPLY,  KC_MNXT   \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| PrtSc| GUI  | Alt  |Lower | Tab  |Space |Raise | VolDn| VolUp| Pl/Ps| Next |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_LCTL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_PSCR, KC_LGUI, KC_LALT, LOWER,   KC_TAB,  KC_SPC,  RAISE,   KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT  \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| PrtSc| GUI  | Alt  |Lower | Tab  |Space |Raise | VolDn| VolUp| Pl/Ps| Next |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_PSCR, KC_LGUI, KC_LALT, LOWER,   KC_TAB,  KC_SPC,  RAISE,   KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT  \
),

/* Lower
 * ,------------------------------------------   ------------------------------------------.
 * |   `  |   1  |   2  |   3  |  4   |   5  |   |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * | Del  |   _  |   +  |      |      |      |   |      |   (  |   )  |      |   -  |  '   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |   -  |   =  |      |      |      |   |  =   |   {  |   }  |      |   +  |  `   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |      |      | GUI  |      |      |   |      |   [  |   ]  |   .  | Enter|      |
 * `------------------------------------------   ------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRAVE,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,  \
  KC_DEL,    KC_UNDS,  KC_PLUS,  _______,  _______,  _______,  _______,  KC_LPRN,  KC_RPRN,  _______,  KC_MINS,  KC_QUOT,  \
  KC_NLCK,   KC_MINS,  KC_EQL,   _______,  _______,  _______,  KC_EQL,   KC_LCBR,  KC_RCBR,  _______,  KC_PLUS,  KC_GRV,   \
  _______,   _______,  _______,  KC_LGUI,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_DOT,   KC_ENT,   _______   \
),

/* Raise: featuring vim-style hjkl arrow keys
 * ,------------------------------------------   ------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------   -------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |   | Left | Down |  Up  |Right |      |  |   |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |   | Home | PgDn | PgUp | End  |      |Enter |
 * |------+------+------+------+------+------+   +------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |   |      |      |      |      |      |      |
 * `------------------------------------------   ------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILD,  KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,   \
  KC_DEL,   KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  KC_PIPE,  \
  _______,  KC_F6,    KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,  \
  _______,  KC_F11,   KC_F12,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______   \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |QWERTY|Colemk|Dvorak|      | Prev | Pl/Ps| Next |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Mute | VolDn| VolUp|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______,  RESET,    _______,  QWERTY,   COLEMAK,  DVORAK,   _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,  KC_DEL,   \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______   \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
