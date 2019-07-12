/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

#define SHIFT(key) ACTION(ACT_MODS, (MOD_LSFT << 8) | (key))
#define CTRL(key) ACTION(ACT_MODS, (MOD_LCTL << 8) | (key))
#define ALT(key) ACTION(ACT_MODS, (MOD_LALT << 8) | (key))
#define GUI(key) ACTION(ACT_MODS, (MOD_LGUI << 8) | (key))
#define RALT(key) ACTION(ACT_MODS, (MOD_RALT << 8) | (key))

//#define RSHFT(key) ACTION(ACT_MODS, (MOD_RSFT << 8) | (key))
//#define SRALT(key) ACTION(ACT_MODS, ((MOD_RALT | MOD_RSFT) << 8) | (key))

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

#define KEYMAP( \
	  k00, k01, k02, k03, k04, k05, k06, k07,   \
	  k08, k09, k0a, k0b, k0c, k0d, k0e, k0f,   \
	  k10, k11, k12, k13, k14, k15, k16, k17,   \
	  k18, k19, k1a, k1b, k1c, k1d, k1e, k1f,   \
	  k20, k21, k22, k23, k24, k25, k26, k27,   \
	  k28, k29, k2a, k2b, k2c, k2d, k2e, k2f,   \
	  k30, k31, k32, k33, k34, k35, k36, k37,   \
	  k38, k39, k3a, k3b, k3c, k3d, k3e, k3f    \
) \
{ \
	{ k07, k06, k05, k04, k03, k02, k01, k00 }, \
	{ k0f, k0e, k0d, k0c, k0b, k0a, k09, k08 }, \
	{ k17, k16, k15, k14, k13, k12, k11, k10 }, \
	{ k1f, k1e, k1d, k1c, k1b, k1a, k19, k18 }, \
	{ k20, k21, k22, k23, k24, k25, k26, k27 }, \
	{ k28, k29, k2a, k2b, k2c, k2d, k2e, k2f }, \
	{ k30, k31, k32, k33, k34, k35, k36, k37 }, \
	{ k38, k39, k3a, k3b, k3c, k3d, k3e, k3f }  \
}
 
/* 1: FN_ARROWS_LAYER On the left and right hands — arrows keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     PgUp    ¦     End     ¦   Empty(5)  ¦     Home    ¦     none    ¦    FN0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Tab      ¦   BackSpace ¦     PgDn    ¦     Left    ¦      Up     ¦     Right   ¦    Enter    ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Arrows   ¦    Normal   ¦     none    ¦    Delete   ¦     Down    ¦      Ins    ¦     none    ¦     none    ¦
        ¦      Lock    ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand 
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      FN1     ¦     none    ¦     Home    ¦   Empty(5)  ¦      End    ¦     PgUp    ¦     none    ¦     none    ¦
        ¦  RightArrows ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  Left Shift  ¦     Enter   ¦     Left    ¦      Up     ¦     Right   ¦     PgDn    ¦   NumEnter  ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦ Left Control ¦     none    ¦      Ins    ¦     Down    ¦     Delete  ¦     none    ¦    Normal   ¦    Arrows   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------                                                                                                
*/

//First four lines — the left hand, next four lines — the right hand
#define  FN_ARROWS_LAYER  KEYMAP( \
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI, \
         KC_NO,          KC_NO,      KC_PGUP,         KC_END,         KC_FN7,       KC_HOME,          KC_NO,      KC_FN0, \
        KC_TAB,        KC_BSPC,      KC_PGDN,        KC_LEFT,          KC_UP,       KC_RGHT,         KC_ENT,      KC_LSFT, \
       KC_FN11,        KC_FN10,        KC_NO,      KC_DELETE,        KC_DOWN,        KC_INS,          KC_NO,        KC_NO, \
                                                                                                                           \
         KC_NO,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO, \
        KC_FN1,          KC_NO,      KC_HOME,         KC_FN7,         KC_END,       KC_PGUP,          KC_NO,        KC_NO, \
       KC_LSFT,         KC_ENT,      KC_LEFT,          KC_UP,        KC_RGHT,       KC_PGDN,        KC_PENT,        KC_NO, \
       KC_LCTL,          KC_NO,       KC_INS,        KC_DOWN,      KC_DELETE,         KC_NO,        KC_FN10,      KC_FN11)

/* 2: FN_NUMBERS_LAYER On the left and right hands — digits */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦      1      ¦      2      ¦      3      ¦     none    ¦      FN0    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦  LeftArrows ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Tab      ¦  BackSpace  ¦     none    ¦      4      ¦      5      ¦      6      ¦     Enter   ¦      0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Normal   ¦      ,      ¦      7      ¦      8      ¦      9      ¦      .      ¦     Num     ¦
        ¦              ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      FN2     ¦  BackSpace  ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦Function Keys ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      FN1     ¦     none    ¦      7      ¦      8      ¦      9      ¦     none    ¦     none    ¦     none    ¦
        ¦ RightArrows  ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      0       ¦     Enter   ¦      4      ¦      5      ¦      6      ¦     none    ¦   NumEnter  ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Num      ¦      .      ¦      1      ¦      2      ¦      3      ¦      ,      ¦    Normal   ¦     none    ¦
        ¦     Lock     ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
#define FN_NUMBERS_LAYER  KEYMAP( \
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI, \
         KC_NO,          KC_NO,        KC_NO,          KC_P1,          KC_P2,         KC_P3,          KC_NO,      KC_FN0, \
        KC_TAB,        KC_BSPC,        KC_NO,          KC_P4,          KC_P5,         KC_P6,         KC_ENT,        KC_P0, \
	 KC_NO,        KC_FN10,      KC_SLSH,          KC_P7,          KC_P8,         KC_P9, SHIFT(KC_SLSH),      KC_FN12, \
                                                                                                                           \
        KC_FN2,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO, \
	KC_FN1,          KC_NO,        KC_P7,          KC_P8,          KC_P9,         KC_NO,          KC_NO,        KC_NO, \
         KC_P0,         KC_ENT,        KC_P4,          KC_P5,          KC_P6,         KC_NO,        KC_PENT,        KC_NO, \
       KC_FN12, SHIFT(KC_SLSH),        KC_P1,          KC_P2,          KC_P3,       KC_SLSH,        KC_FN10,        KC_NO)

/* 3: FN_LARROW_LAYER On the left hand — arrows keys, on the right hand — digits */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦     none    ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     PgUp    ¦     End     ¦    Empty    ¦     Home    ¦     none    ¦    FN0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   Alt+Tab    ¦   BackSpace ¦     PgDn    ¦     Left    ¦      Up     ¦     Right   ¦    Enter    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Arrows   ¦    Normal   ¦     none    ¦    Delete   ¦     Down    ¦      Ins    ¦     none    ¦     Num     ¦
        ¦      Lock    ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  Ctrl+Shift  ¦     none    ¦      7      ¦      8      ¦      9      ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      0       ¦     none    ¦      4      ¦      5      ¦      6      ¦     none    ¦   NumEnter  ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦      .      ¦      1      ¦      2      ¦      3      ¦      ,      ¦    Normal   ¦   LeftCtrl  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
#define  FN_LARROW_LAYER  KEYMAP( \
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,        KC_NO, \
         KC_NO,          KC_NO,      KC_PGUP,         KC_END,         KC_FN7,       KC_HOME,          KC_NO,      KC_FN0, \
   ALT(KC_TAB),        KC_BSPC,      KC_PGDN,        KC_LEFT,          KC_UP,       KC_RGHT,         KC_ENT,        KC_NO, \
       KC_FN11,        KC_FN10,        KC_NO,      KC_DELETE,        KC_DOWN,        KC_INS,          KC_NO,      KC_FN12, \
                                                                                                                           \
         KC_NO,        KC_BSPC,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO, \
SHIFT(KC_LCTL),          KC_NO,        KC_P7,          KC_P8,          KC_P9,         KC_NO,          KC_NO,        KC_NO, \
         KC_P0,          KC_NO,        KC_P4,          KC_P5,          KC_P6,         KC_NO,        KC_PENT,        KC_NO, \
       KC_RSFT, SHIFT(KC_SLSH),        KC_P1,          KC_P2,          KC_P3,       KC_SLSH,        KC_FN10,      KC_LCTL)

/* 4: FN_RARROW_LAYER On the left hand — digits, on the right hand — arrows keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦      +      ¦       -     ¦      *      ¦      /      ¦     none    ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦      1      ¦      2      ¦      3      ¦     none    ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦     none    ¦      4      ¦      5      ¦      6      ¦     none    ¦      0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Normal   ¦      ,      ¦      7      ¦      8      ¦      9      ¦      .      ¦ LeftControl ¦
        ¦              ¦     Lock    ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦      /      ¦      *      ¦      -      ¦      +      ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      FN1     ¦     none    ¦     Home    ¦   Empty(5)  ¦      End    ¦     PgUp    ¦     none    ¦     none    ¦
        ¦  RightArrows ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     Enter   ¦     Left    ¦      Up     ¦     Right   ¦     PgDn    ¦   NumEnter  ¦   Alt+Tab   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Num      ¦     none    ¦      Ins    ¦     Down    ¦     Delete  ¦     none    ¦    Normal   ¦    Arrows   ¦
        ¦     Lock     ¦             ¦             ¦             ¦             ¦             ¦     Lock    ¦     Lock    ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
#define FN_RARROW_LAYER  KEYMAP( \
         KC_NO,          KC_NO,      KC_PPLS,        KC_PMNS,        KC_PAST,       KC_PSLS,          KC_NO,      KC_LGUI, \
         KC_NO,          KC_NO,        KC_NO,          KC_P1,          KC_P2,         KC_P3,          KC_NO,      KC_LSFT, \
         KC_NO,        KC_BSPC,        KC_NO,          KC_P4,          KC_P5,         KC_P6,          KC_NO,        KC_P0, \
         KC_NO,        KC_FN10,      KC_SLSH,          KC_P7,          KC_P8,         KC_P9, SHIFT(KC_SLSH),      KC_LCTL, \
                                                                                                                           \
         KC_NO,          KC_NO,      KC_PSLS,        KC_PAST,        KC_PMNS,       KC_PPLS,          KC_NO,        KC_NO, \
        KC_FN1,          KC_NO,      KC_HOME,         KC_FN7,         KC_END,       KC_PGUP,          KC_NO,        KC_NO, \
         KC_NO,         KC_ENT,      KC_LEFT,          KC_UP,        KC_RGHT,       KC_PGDN,        KC_PENT,  ALT(KC_TAB), \
       KC_FN12,          KC_NO,       KC_INS,        KC_DOWN,      KC_DELETE,         KC_NO,        KC_FN10,      KC_FN11)

/* 5: FN_PURESHIFTFUNC_LAYER «Pure» and with Shift Fx keys */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦     none    ¦     F11     ¦     F12     ¦     none    ¦     none    ¦    FN9      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦     F1      ¦     F2      ¦     F3      ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦     F4      ¦     F5      ¦     F6      ¦     none    ¦     F10     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   LeftAlt    ¦     none    ¦     none    ¦     F7      ¦     F8      ¦     F9      ¦     none    ¦ LeftControl ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      FN2     ¦     none    ¦     none    ¦   SHIFT+F11 ¦   SHIFT+F12 ¦     none    ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦   SHIFT+F7  ¦   SHIFT+F8  ¦   SHIFT+F9  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   SHIFT+F10  ¦     none    ¦   SHIFT+F4  ¦   SHIFT+F5  ¦   SHIFT+F6  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦   SHIFT+F1  ¦   SHIFT+F2  ¦   SHIFT+F3  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
#define FN_PURESHIFTFUNC_LAYER   KEYMAP( \
         KC_NO,          KC_NO,        KC_NO,         KC_F11,         KC_F12,         KC_NO,          KC_NO,       KC_FN9, \
         KC_NO,          KC_NO,        KC_NO,          KC_F1,          KC_F2,         KC_F3,          KC_NO,        KC_NO, \
         KC_NO,          KC_NO,        KC_NO,          KC_F4,          KC_F5,         KC_F6,          KC_NO,       KC_F10, \
       KC_LALT,          KC_NO,        KC_NO,          KC_F7,          KC_F8,         KC_F9,          KC_NO,      KC_LCTL, \
                                                                                                                           \
        KC_FN2,          KC_NO,        KC_NO,  SHIFT(KC_F11),  SHIFT(KC_F12),         KC_NO,          KC_NO,        KC_NO, \
         KC_NO,          KC_NO, SHIFT(KC_F7),   SHIFT(KC_F8),   SHIFT(KC_F9),         KC_NO,          KC_NO,        KC_NO, \
 SHIFT(KC_F10),          KC_NO, SHIFT(KC_F4),   SHIFT(KC_F5),   SHIFT(KC_F6),         KC_NO,          KC_NO,        KC_NO, \
       KC_RSFT,          KC_NO, SHIFT(KC_F1),   SHIFT(KC_F2),   SHIFT(KC_F3),         KC_NO,          KC_NO,      KC_RSFT)

/* 6: FN_ALTCTRLFUNC_LAYER Fx keys with Alt and Ctrl */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦     none    ¦     none    ¦   ALT+F11   ¦   ALT+F12   ¦     none    ¦     none    ¦     Win     ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦   ALT+F1    ¦   ALT+F2    ¦   ALT+F3    ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦   ALT+F4    ¦   ALT+F5    ¦   ALT+F6    ¦     none    ¦   ALT+F10   ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   LeftAlt    ¦     none    ¦     none    ¦   ALT+F7    ¦   ALT+F8    ¦   ALT+F9    ¦     none    ¦ LeftControl ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦      FN2     ¦     none    ¦     none    ¦    CTRL+F11 ¦    CTRL+F12 ¦     none    ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦    CTRL+F7  ¦    CTRL+F8  ¦    CTRL+F9  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦    CTRL+F10  ¦     none    ¦    CTRL+F4  ¦    CTRL+F5  ¦    CTRL+F6  ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦    CTRL+F1  ¦    CTRL+F2  ¦    CTRL+F3  ¦     none    ¦     none    ¦   Left Alt  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
#define FN_ALTCTRLFUNC_LAYER   KEYMAP( \
         KC_NO,          KC_NO,        KC_NO,    ALT(KC_F11),    ALT(KC_F12),         KC_NO,          KC_NO,       KC_FN9, \
         KC_NO,          KC_NO,        KC_NO,     ALT(KC_F1),     ALT(KC_F2),    ALT(KC_F3),          KC_NO,        KC_NO, \
         KC_NO,          KC_NO,        KC_NO,     ALT(KC_F4),     ALT(KC_F5),    ALT(KC_F6),          KC_NO,  ALT(KC_F10), \
       KC_LALT,          KC_NO,        KC_NO,     ALT(KC_F7),     ALT(KC_F8),    ALT(KC_F9),          KC_NO,      KC_LCTL, \
                                                                                                                           \
        KC_FN2,          KC_NO,        KC_NO,   CTRL(KC_F11),   CTRL(KC_F12),         KC_NO,          KC_NO,        KC_NO, \
         KC_NO,          KC_NO,  CTRL(KC_F7),    CTRL(KC_F8),    CTRL(KC_F9),         KC_NO,          KC_NO,        KC_NO, \
  CTRL(KC_F10),          KC_NO,  CTRL(KC_F4),    CTRL(KC_F5),    CTRL(KC_F6),         KC_NO,          KC_NO,        KC_NO, \
       KC_RSFT,          KC_NO,  CTRL(KC_F1),    CTRL(KC_F2),    CTRL(KC_F3),         KC_NO,          KC_NO,      KC_LALT)

/* 7: FN_SPECIALCHARS_LAYER Special Characters */
/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦      `      ¦      ~      ¦       '     ¦     none    ¦     none    ¦      ±      ¦    none     ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦Ctrl+Shift+Esc¦     none    ¦     none    ¦       1     ¦       2     ¦       3     ¦     none    ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦  BackSpace  ¦       .     ¦       4     ¦       5     ¦       6     ¦     Enter   ¦    none     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   FN3, APP   ¦     none    ¦       ,     ¦       7     ¦       8     ¦       9     ¦       0     ¦    none     ¦
        ¦Special Chars ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦    Accent   ¦      –      ¦      —      ¦ Multiplicat ¦   Division  ¦     none    ¦     none
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     none     ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     Space    ¦     none    ¦ Scroll_Left ¦  Scroll_Up  ¦ Scroll_Down ¦ Scroll_Right¦     none    ¦     none    ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦     none    ¦     none    ¦     none    ¦     none    ¦      …      ¦     none    ¦  NumLock On ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

//First four lines — the left hand, next four lines — the right hand
#define FN_SPECIALCHARS_LAYER   KEYMAP( \
         KC_NO,   SHIFT(KC_6),         KC_EQL,           KC_6,          KC_NO,          KC_NO,       KC_RBRC,        KC_NO, \
        KC_FN8,         KC_NO,          KC_NO,          KC_P1,          KC_P2,          KC_P3,         KC_NO,        KC_NO, \
         KC_NO,       KC_BSPC, SHIFT(KC_SLSH),          KC_P4,          KC_P5,          KC_P6,        KC_ENT,        KC_NO, \
        KC_FN3,      KC_LCTRL,        KC_SLSH,          KC_P7,          KC_P8,          KC_P9,         KC_P0,        KC_NO, \
                                                                                                                            \
         KC_NO, SHIFT(KC_EQL),        KC_NUBS, SHIFT(KC_NUBS),        KC_BSLS, SHIFT(KC_BSLS),         KC_NO,        KC_NO, \
         KC_NO,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,         KC_NO,        KC_NO, \
        KC_SPC,         KC_NO,        KC_FN16,        KC_FN14,        KC_FN15,        KC_FN17,         KC_NO,        KC_NO, \
       KC_RSFT,         KC_NO,          KC_NO,          KC_NO,          KC_NO, SHIFT(KC_RBRC), ALT(KC_DELETE),      KC_FN6)
 
/*enum function_id {
  BOOTLOADER,
};

void bootloader(void);
*/

#endif
