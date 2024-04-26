#include "../config.h"

#include "./TRS80Keyboard.h"

void TRS80Keyboard::_writeRows(byte address) {
  if (INVERTED_ROWS) address = ~address;

  digitalWrite(R0_PIN, (address & 1) == 0 ? LOW : HIGH);
  digitalWrite(R1_PIN, (address & 2) == 0 ? LOW : HIGH);
  digitalWrite(R2_PIN, (address & 4) == 0 ? LOW : HIGH);
  digitalWrite(R3_PIN, (address & 8) == 0 ? LOW : HIGH);
  digitalWrite(R4_PIN, (address & 16) == 0 ? LOW : HIGH);
  digitalWrite(R5_PIN, (address & 32) == 0 ? LOW : HIGH);
  digitalWrite(R6_PIN, (address & 64) == 0 ? LOW : HIGH);
  digitalWrite(R7_PIN, (address & 128) == 0 ? LOW : HIGH);
}

byte TRS80Keyboard::_readCols() {
  byte result = (digitalRead(C7_PIN) << 7) | (digitalRead(C6_PIN) << 6) | (digitalRead(C5_PIN) << 5) | (digitalRead(C4_PIN) << 4) | (digitalRead(C3_PIN) << 3) | (digitalRead(C2_PIN) << 2) | (digitalRead(C1_PIN) << 1) | digitalRead(C0_PIN);

  if (INVERTED_COLS) result = ~result;

  return result;
}

void TRS80Keyboard::init() {
  if (KEYPRESS_LED_PIN != 0) {
    pinMode(KEYPRESS_LED_PIN, OUTPUT);
  }

  if (KEYBOARD_ENABLED_PIN != 0) {
    pinMode(KEYBOARD_ENABLED_PIN, OUTPUT);
    digitalWrite(KEYBOARD_ENABLED_PIN, LOW);
  }

  pinMode(R0_PIN, OUTPUT);
  pinMode(R1_PIN, OUTPUT);
  pinMode(R2_PIN, OUTPUT);
  pinMode(R3_PIN, OUTPUT);
  pinMode(R4_PIN, OUTPUT);
  pinMode(R5_PIN, OUTPUT);
  pinMode(R6_PIN, OUTPUT);
  pinMode(R7_PIN, OUTPUT);

  pinMode(C0_PIN, INPUT_PULLUP);
  pinMode(C1_PIN, INPUT_PULLUP);
  pinMode(C2_PIN, INPUT_PULLUP);
  pinMode(C3_PIN, INPUT_PULLUP);
  pinMode(C4_PIN, INPUT_PULLUP);
  pinMode(C5_PIN, INPUT_PULLUP);
  pinMode(C6_PIN, INPUT_PULLUP);
  pinMode(C7_PIN, INPUT_PULLUP);
}

int TRS80Keyboard::anyKeyPressed() {
  byte address = 0xff;
  _writeRows(address);

  delay(DELAY_READ);

  byte result;
  result = _readCols();

  if (result > 0) {
    if (KEYPRESS_LED_PIN != 0) {
      digitalWrite(KEYPRESS_LED_PIN, HIGH);
    }
    return true;
  }
  return false;
}

void TRS80Keyboard::readKeys(ByteArray* data) {
  byte address = 128;  // Read control keys (e.g. shift) first

  for (int i = 7; i >= 0; i--) {
    _writeRows(address);

    delay(DELAY_READ);

    byte keys = _readCols();
    (*data)[i] = keys;

    // Next row
    address = address >> 1;

    // If something is pressed, skip out except if it is control keys (e.g. shift)
    if (keys > 0 && i != 7) return;
  }
}

void TRS80Keyboard::reset() {
  if (KEYPRESS_LED_PIN != 0) {
   digitalWrite(KEYPRESS_LED_PIN, LOW);
  }
}