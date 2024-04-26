#ifndef ECHO_KEYBOARD_H
#define ECHO_KEYBOARD_H

#include <Arduino.h>

class EchoKeyboard {
private:
  bool _enabled = false;

public:
  void init();

  void press(char code);
  void release(char code);

  void releaseAll();

  void checkEnabled();
};

#endif /* ECHO_KEYBOARD_H */
