#ifndef TRS80_KEYBOARD_H
#define TRS80_KEYBOARD_H

#include <Arduino.h>
#include "./ByteArray.h"

class TRS80Keyboard {
private:
  void _writeRows(byte address);
  byte _readCols();

public:
  void init();

  int anyKeyPressed();
  void readKeys(ByteArray* data);

  void reset();
};

#endif /* TRS80_KEYBOARD_H */
