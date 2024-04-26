#ifndef MODEL3_CONFIG_H
#define MODEL3_CONFIG_H

// This is the configuration for the Model 3 Keyboard.

// Defines the delay in ms when the column pins can be read after the
// row pins were set.
#define DELAY_READ 1

// Defines if the row values need to be inverted.
#define INVERTED_ROWS true

// Defines if the column values need to be inverted.
#define INVERTED_COLS true

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

// Unshifted keymap from row 1 to 8 (top to bottom) and
// columns 1 to 8 (left to right)
#define KEYBOARD_MAP \
  { \
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', \
      'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', \
      'p', 'q', 'r', 's', 't', 'u', 'v', 'w', \
      'x', 'y', 'z', '{', 0, '}', 0, 0, \
      '0', '1', '2', '3', '4', '5', '6', '7', \
      '8', '9', ':', ';', ',', '-', '.', '/', \
      KEY_ENTER, KEY_CLEAR, KEY_BREAK, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, ' ', \
      KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT, 0, 0, KEY_CONTROL, 0, 0, 0 \
  }

// Shifted keymap from row 1 to 8 (top to bottom) and
// columns 1 to 8 (left to right)
#define KEYBOARD_SHIFTED_MAP \
  { \
    '`', 'A', 'B', 'C', 'D', 'E', 'F', 'G', \
      'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', \
      'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', \
      'X', 'Y', 'Z', '[', 0, ']', 0, 0, \
      0, '!', '"', '#', '$', '%', '&', '\'', \
      '(', ')', '*', '+', '<', '=', '>', '?', \
      KEY_ENTER, KEY_CLEAR, KEY_BREAK, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, ' ', \
      KEY_LEFT_SHIFT, KEY_RIGHT_SHIFT, 0, 0, KEY_CONTROL, 0, 0, 0 \
  }

#endif /* MODEL3_CONFIG_H */
