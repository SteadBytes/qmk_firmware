/*
Copyright 2022 Ben Steadman <@SteadBytes>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

This is the personal keymap of Ben Steadman (@SteadBytes) for the Keyboardio
Atreus.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,   // QWERTY
    _NUM,  // Number + symbol
    _NAV,  // Navigation
    // TODO: Adjust layer
};

enum custom_keycodes {
    TMUX_LEAD = SAFE_RANGE,
};

// TODO: better ctrl position(s)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  q        w          e    r    t                ||            y    u      i  o  p
   *  a        s          d    f    g                ||            h    j      k  l  ;
   *  z        x          c    v    b     TMUX_LEAD  ||  \         n    m      ,  .  /
   *  shift/(  ctrl/esc  alt  gui  space  tab/L1     ||  enter/L2  bsp  altgr  -  '  shift/)
   */
  [_QW] = LAYOUT(
    KC_Q,    KC_W,           KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,     KC_I,    KC_O,    KC_P   ,
    KC_A,    KC_S,           KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,           KC_C,    KC_V,    KC_B,      TMUX_LEAD,            KC_BSLS,       KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,
    KC_LSPO, LCTL_T(KC_ESC), KC_LALT, KC_LGUI, KC_SPACE,  LT(_NUM, KC_TAB),    LT(_NAV, KC_ENT), KC_BSPC, KC_RALT , KC_MINS, KC_QUOT, KC_RSPC
  ),

  /*
   *  !        @         #    $    #              ||            ^    &      *  -  +
   *  1        2         3    4    5              ||            6    7      8  9  0
   *  =        ~         ~    [    {      `       ||  \         }    ]      ,  .  /
   *  shift/(  ctrl/esc  alt  gui  space  tab/L1  ||  enter/L2  bsp  altgr  -  '  shift/)
   */
  [_NUM] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINUS, KC_PLUS,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    KC_EQL,  KC_PIPE, KC_TILD, KC_LBRC, KC_LCBR, KC_GRV,    KC_BSLS, KC_RCBR, KC_RBRC, KC_COMM, KC_DOT,   KC_SLSH,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,
  ),

  // TODO: browser back/forward macros (command + L/R arrow)
  /*
   * F1       F2        F3      F4   F5             ||            F6       F7       F8       F9       F10
   * cut      copy      insert  home pgup           ||             left     down     up       right    F11
   * caps     paste     del     end  pgdn   undo    ||  again      mouse_l  mouse_d  mouse_u  mouse_r  prtscr
   * shift/(  ctrl/esc  alt     gui  space  tab/L1  ||  enter/L2  bsp      altgr    -        '        shift/)
   */
  [_NAV] = LAYOUT(
    KC_F1,   KC_F2,    KC_F3,  KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
    KC_CUT,  KC_COPY,  KC_INS, KC_HOME, KC_PGUP,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_F11,
    KC_CAPS, KC_PASTE, KC_DEL, KC_END,  KC_PGDN, KC_UNDO,    KC_AGIN, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_PSCR,
    _______, _______,  _______, _______, _______, _______,   _______, _______, _______, _______, _______,
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMUX_LEAD:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)));
    }
    break;
  }
  return true;
}