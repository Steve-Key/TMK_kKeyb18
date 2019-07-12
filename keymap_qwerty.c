#include "keymap_common.h"

 /*       Left Hand                                   Right Hand
      --+-+-+-+-+--                                  --+-+-+-+-+--
      |~|1|2|3|4|5| <-------                 ------> |<|7|8|9|0|-|
    --+-+-+-+-+-+-+        ¦                ¦        +-+-+-+-+-+-+--
    |e|@|Q|W|E|R|T| <----- ¦                ¦ -----> |Y|U|I|O|P|[|p|
    +-+-+-+-+-+-+-+      ¦ ¦                ¦ ¦      +-+-+-+-+-+-+-+
    |t|<|A|S|D|F|G| <--- ¦ ¦                ¦ ¦ ---> |H|J|K|L|;|e|p|
    --+-+-+-+-+-+-+    ¦ ¦ ¦                ¦ ¦ ¦    +-+-+-+-+-+-+--
      |l|Z|X|C|V|B| <- ¦ ¦ ¦                ¦ ¦ ¦ -> |N|M|,|.|/|r|
     ^--+-+-+-+-+-+- ¦ ¦ ¦ ¦                ¦ ¦ ¦ ¦ -+-+-+-+-+-+--^
     -------------|m|¦ ¦ ¦ ¦                ¦ ¦ ¦ ¦|s|-------------
                  --+- ¦ ¦ ¦                ¦ ¦ ¦ -+--
                    |c|¦ ¦ ¦                ¦ ¦ ¦¦a|
                    --+- ¦ ¦                ¦ ¦ -+--
                      |s|¦ ¦                ¦ ¦| |
                      --+- ¦                ¦ -+--
                        |f|¦                ¦|f|
                        --+--              --+--
                          |w|              |f|
                          ---              ---                       */


    /* Macro definition */
    enum macro_id {
        ONCAPS,
        OFFCAPS,
	ONNUM,
	NUMOFFP5ON,
	FN0M,
    };

    const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
    {
        keyevent_t event = record->event;
        //uint8_t tap_count = record->tap_count;

        switch (id) {
		case ONCAPS:
			return (event.pressed ?
				MACRO( D(LCAP), END ) :
				MACRO( END ) );
		case OFFCAPS:
			return (event.pressed ?
				MACRO( U(LCAP), END ) :
				MACRO( END ) );
		case ONNUM:
			return (event.pressed ?
				MACRO( D(LNUM), END ) :
				MACRO( END ) );
		case NUMOFFP5ON:
			return (event.pressed ?
				MACRO( U(LNUM), W(10), T(P5), W(10), D(LNUM), END ) :
				MACRO( END ) );
//		case FN0M:
//			return (!event.pressed ?
//				MACRO( U(FN0), U(FN1), END ) :
//				event.pressed ?
//				MACRO( D(FN0), END ) :
//				MACRO( END ) );

        }
        return MACRO_NONE;
    }

/* The default kKeyb layout. First layer is normal keys and punctuation,
   second and third (momentary fn layer) is numbers, and arrows.
   The fourth layer - «pure» function keys and in a combination with Shift 
   The fifth layer — special characters
*/

/* Matrix: Left Hand
                       +-------------+-------------+-------------+-------------+-------------+-------------+------------- 
              none     ¦      ;      ¦      (      ¦       "     ¦      «      ¦      !      ¦      +      ¦    Win      ¦
                       ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     ESC      ¦      @      ¦      J      ¦       C     ¦      U      ¦      K      ¦      Y      ¦    FN0      ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦ LeftArrows  ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     TAB      ¦  BackSpace  ¦      Q      ¦       E     ¦      V      ¦      A      ¦      P      ¦  LeftShift  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   FN3, APP   ¦     FN5     ¦      F      ¦      <      ¦      S      ¦      M      ¦      I      ¦ LeftControl ¦
        ¦Special Chars ¦     LAT     ¦             ¦             ¦             ¦             ¦             ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
 
   Matrix: Right Hand                                                                                                
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     FN2      ¦  BackSpace  ¦      -      ¦      »      ¦      :      ¦      )      ¦      /      ¦     none
        ¦Function Keys ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦     FN1      ¦      N      ¦      G      ¦      W      ¦      H      ¦      Z      ¦     #       ¦ PrintScreen ¦
        ¦ RightArrows  ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦   Space      ¦      R      ¦      O      ¦      L      ¦      D      ¦      \      ¦   Enter     ¦   Pause     ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦             ¦             ¦
        +--------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+
        ¦  RightShift  ¦      T      ¦      X      ¦      B      ¦      >      ¦      ,      ¦     FN4     ¦   Left Alt  ¦
        ¦              ¦             ¦             ¦             ¦             ¦             ¦     RUS     ¦             ¦
         --------------+-------------+-------------+-------------+-------------+-------------+-------------+------------- 
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
//First four lines — the left hand, next four lines — the right hand
KEYMAP(  KC_NO,         KC_GRV,         KC_1,           KC_2,           KC_3,          KC_4,           KC_5,      KC_LGUI,
        KC_ESC,        KC_QUOT,         KC_J,           KC_C,           KC_U,          KC_K,           KC_Y,      KC_FN0,
        KC_TAB,        KC_BSPC,         KC_Q,           KC_E,           KC_V,          KC_A,           KC_P,      KC_LSFT,
        KC_FN3,         KC_FN5,         KC_F,        KC_COMM,           KC_S,          KC_M,           KC_I,      KC_LCTL,

        KC_FN2,        KC_BSPC,         KC_7,           KC_8,           KC_9,          KC_0,        KC_MINS,        KC_NO,
        KC_FN1,           KC_N,         KC_G,           KC_W,           KC_H,          KC_Z,        KC_LBRC,      KC_PSCR,
        KC_SPC,           KC_R,         KC_O,           KC_L,           KC_D,       KC_SCLN,         KC_ENT,      KC_PAUS,
       KC_RSFT,           KC_T,         KC_X,           KC_B,         KC_DOT,       KC_SLSH,         KC_FN4,     KC_LALT),

  /* 1: On the two hand — arrows keys */
  FN_ARROWS_LAYER,
  /* 2: On the two hand — digits */
  FN_NUMBERS_LAYER,
  /* 3: On the left hand — arrow keys, on the right hand — digits */
  FN_LARROW_LAYER,
  /* 4: On the right hand — arrow keys, on the left hand — digits */
  FN_RARROW_LAYER,
  /* 5: «Pure» and with Shift Fx keys */
  FN_PURESHIFTFUNC_LAYER,
  /* 6: Fx keys with Alt and Ctrl */
  FN_ALTCTRLFUNC_LAYER,
  /* 7: Special Characters */
  FN_SPECIALCHARS_LAYER,


};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(3), // to LFn overlay
//  [0] = ACTION_LAYER_ON_OFF(3), // to LFn overlay
  [1] = ACTION_LAYER_MOMENTARY(4), // to RFn overlay
//  [1] = ACTION_LAYER_ON_OFF(4), // to RFn overlay
  [2] = ACTION_LAYER_MOMENTARY(5), // to CFx overlay - «Pure» and with Shift Fx keys
//  [2] = ACTION_LAYER_ON_OFF(5), // to CFx overlay - «Pure» and with Shift Fx keys
  [3] = ACTION_LAYER_TAP_KEY(7, KC_APP), // to special symbols width APP key
  [4] = ACTION_MACRO(ONCAPS),      //vkluchaem CapsLock — tam u nas russkie bukvy
  [5] = ACTION_MACRO(OFFCAPS),     //otkluchaem CapsLock — perehodim na latinicu
  [6] = ACTION_MACRO(ONNUM),       //vkluchaet NumLock, chtoby cyfry vvodit
  [7] = ACTION_MACRO(NUMOFFP5ON),  //otkluchaet NumLock, vvodit 5 na cyfrovoj klave, vkluchaet Num — dlq FARa
  [8] = ACTION_MODS_KEY(MOD_LCTL|MOD_LSFT, KC_ESC), // TaskManager (Control,Shift+Esc)
  [9] = ACTION_LAYER_MOMENTARY(6), // to CACFx overlay - Fx keys with Alt and Ctrl
  [10] = ACTION_DEFAULT_LAYER_SET(0),    // switch to layer Default Letters
  [11] = ACTION_DEFAULT_LAYER_SET(1),    // switch to layer Arrows
  [12] = ACTION_DEFAULT_LAYER_SET(2),    // switch to layer Numbers
  [13] = ACTION_MACRO(FN0M),  
  [14] = ACTION_MOUSEKEY(KC_WH_U), // wheel Up
  [15] = ACTION_MOUSEKEY(KC_WH_D), // wheel Down
  [16] = ACTION_MOUSEKEY(KC_WH_L), // wheel Left
  [17] = ACTION_MOUSEKEY(KC_WH_R), // wheel Right
};

//ACTION_LAYER_CLEAR(ON_RELEASE)

/* Akcii rabotaut!!!
  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
*/

/*	Primery akcij iz drugih klaviatur
    [3] = ACTION_DEFAULT_LAYER_SET(0)
    [3] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_APP),
    [0] = ACTION_LAYER_MODS(1, MOD_LSFT),
    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
    [1] = ACTION_LAYER_TAP_TOGGLE(1),                 // HHKB layer(toggle with 5 taps)
    [2] = ACTION_LAYER_TAP_KEY(2, KC_SLASH),          // Cursor layer with Slash*
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),           // Mousekey layer with Semicolon*
    [4] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),      // RControl with tap Enter*
    [5] = ACTION_MODS_ONESHOT(MOD_LSFT),              // Oneshot Shift*
    [6] = ACTION_LAYER_TAP_KEY(5, KC_SPC),            // Mousekey layer with Space
    [7] = ACTION_LAYER_TOGGLE(3),                     // Mousekey layer(toggle)
    [8] = ACTION_MODS_KEY(MOD_LCTL, KC_W),            // Close Tab
    [9] = ACTION_MODS_KEY(MOD_LSFT, KC_4),            // Shift stuck test

  [8] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),       // LControl with tap Backspace
  [9] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),        // LControl with tap Esc
  [11] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),         // Function: LShift with tap '('
  [12] = ACTION_FUNCTION_TAP(RSHIFT_RPAREN),         // Function: RShift with tap ')'
  [13] = ACTION_MACRO_TAP(LSHIFT_PAREN),             // Macro: LShift with tap '('
  [14] = ACTION_MACRO_TAP(RSHIFT_PAREN),             // Macro: RShift with tap ')'
  [15] = ACTION_MACRO(HELLO),                        // Macro: say hello
  [9] = ACTION_MACRO(VOLUP),                         // Macro: media key
  [3] = ACTION_FUNCTION(BOOTLOADER), // ToDo — BootLoader
  [4] = ACTION_LAYER_TAP_KEY(4, KC_VOLU), // perekluchenie na russkij
  [5] = ACTION_LAYER_TAP_KEY(0, KC_VOLD) // perekluchenie na anglijskij
  [6] = ACTION_MODS_KEY(MOD_RCTL|MOD_RSFT, KC_ESC), // Task(RControl,RShift+Esc)
  [7] = ACTION_LAYER_TAP_KEY(0, ALT(KC_P0), ALT(KC_P1), ALT(KC_P7), ALT(KC_P1)) // Task(RAlt+0171)
  
  MACRO( D(LALT), T(H), T(D), U(LALT), END ) eto budet zazhatie levogo alta, nazhatie H zatem nazhatie D i otpuskanie alta


  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER), // reset for uploading new code
  [4] = ACTION_LAYER_ON(3, 1),  // switch to layer 2
  [5] = ACTION_LAYER_OFF(3, 1),  // switch back to layer 0

  [6] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
  [7] = ACTION_MOUSEKEY(KC_MS_D),
  [8] = ACTION_MOUSEKEY(KC_MS_L),
  [9] = ACTION_MOUSEKEY(KC_MS_R),
  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_WH_D),
  [12] = ACTION_MOUSEKEY(KC_WH_L),
  [13] = ACTION_MOUSEKEY(KC_WH_R),
  [14] = ACTION_MOUSEKEY(KC_BTN1), // clicks
  [15] = ACTION_MOUSEKEY(KC_BTN2),
  [16] = ACTION_MOUSEKEY(KC_BTN3),
  [17] = ACTION_MOUSEKEY(KC_BTN4),
  [18] = ACTION_MOUSEKEY(KC_BTN5),
  [19] = ACTION_MOUSEKEY(KC_ACL0), // acceleration settings
  [20] = ACTION_MOUSEKEY(KC_ACL1),
  [21] = ACTION_MOUSEKEY(KC_ACL2),
*/

/*void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}*/
