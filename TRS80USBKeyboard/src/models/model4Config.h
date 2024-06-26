#ifndef MODEL4_CONFIG_H
#define MODEL4_CONFIG_H

// This is the configuration for the Model 4 Keyboard.

// Defines the delay in ms when the column pins can be read after the
// row pins were set.
#define DELAY_READ 1

// Defines if there are active components on the keyboard.
//
// When active:   will send HIGH/LOW to the rows, and reads the 
//                columns as is.
// When inactive: will send only LOW to rows and float when suppose
//                to be high to emulate an open-collect buffer, and
//                reads the columns as inverse since column input
//                will be pull-up.
//#define ACTIVE_KEYBOARD

// Definition of special keys
#define KEY_ENTER 0xB0
#define KEY_CLEAR 0xB2
#define KEY_BREAK 0xB1
#define KEY_UP 0xDA
#define KEY_DOWN 0xD9
#define KEY_LEFT 0xD8
#define KEY_RIGHT 0xD7
#define KEY_LEFT_SHIFT 0x81
#define KEY_RIGHT_SHIFT 0x85
#define KEY_CONTROL 0x80
#define KEY_CAPS_LOCK 0xC1
#define KEY_F1 0xC2
#define KEY_F2 0xC3
#define KEY_F3 0xC4

// Defines where to find shift keys
#define SHIFT1_ROW 7
#define SHIFT1_VALUE 1

#define SHIFT2_ROW 7
#define SHIFT2_VALUE 2

// Unshifted keymap from row 1 to 8 (top to bottom) and
// columns 1 to 8 (left to right)
#define KEYBOARD_MAP \
  { \
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', \
      'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', \
      'p', 'q', 'r', 's', 't', 'u', 'v', 'w', \
      'x', 'y', 'z', '{', '|', '}', '~', '+', \
      '0', '1', '2', '3', '4', '5', '6', '7', \
      '8', '9', ':', ';', ',', '-', '.', '/', \
      KEY_ENTER, KEY_CLEAR, KEY_BREAK, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, ' ', \
      KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT, KEY_CONTROL, KEY_CAPS_LOCK, KEY_F1, KEY_F2, KEY_F3, 0 \
  }

// Shifted keymap from row 1 to 8 (top to bottom) and
// columns 1 to 8 (left to right)
#define KEYBOARD_SHIFTED_MAP \
  { \
    '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', \
      'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', \
      'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', \
      'X', 'Y', 'Z', '[', '\\', ']', '^', '-', \
      0, '!', '"', '#', '$', '%', '&', '\'', \
      '(', ')', '*', '+', '<', '=', '>', '?', \
      KEY_ENTER, KEY_CLEAR, KEY_BREAK, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, ' ', \
      KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT, KEY_CONTROL, KEY_CAPS_LOCK, KEY_F1, KEY_F2, KEY_F3, 0 \
  }

#endif /* MODEL4_CONFIG_H */
