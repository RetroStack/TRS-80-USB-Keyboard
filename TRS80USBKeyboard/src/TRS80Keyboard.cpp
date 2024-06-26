#include "../config.h"

#include "./TRS80Keyboard.h"

void TRS80Keyboard::_writeRows(byte address) {
  #ifdef ACTIVE_KEYBOARD
    digitalWrite(R0_PIN, (address & 1) == 0 ? LOW : HIGH);
    digitalWrite(R1_PIN, (address & 2) == 0 ? LOW : HIGH);
    digitalWrite(R2_PIN, (address & 4) == 0 ? LOW : HIGH);
    digitalWrite(R3_PIN, (address & 8) == 0 ? LOW : HIGH);
    digitalWrite(R4_PIN, (address & 16) == 0 ? LOW : HIGH);
    digitalWrite(R5_PIN, (address & 32) == 0 ? LOW : HIGH);
    digitalWrite(R6_PIN, (address & 64) == 0 ? LOW : HIGH);
    digitalWrite(R7_PIN, (address & 128) == 0 ? LOW : HIGH);
  #else
    if ((address & 1) == 0) {
      pinMode(R0_PIN, INPUT);
    } else {
      pinMode(R0_PIN, OUTPUT);
      digitalWrite(R0_PIN, LOW);
    }
    if ((address & 2) == 0) {
      pinMode(R1_PIN, INPUT);
    } else {
      pinMode(R1_PIN, OUTPUT);
      digitalWrite(R1_PIN, LOW);
    }
    if ((address & 4) == 0) {
      pinMode(R2_PIN, INPUT);
    } else {
      pinMode(R2_PIN, OUTPUT);
      digitalWrite(R2_PIN, LOW);
    }
    if ((address & 8) == 0) {
      pinMode(R3_PIN, INPUT);
    } else {
      pinMode(R3_PIN, OUTPUT);
      digitalWrite(R3_PIN, LOW);
    }
    if ((address & 16) == 0) {
      pinMode(R4_PIN, INPUT);
    } else {
      pinMode(R4_PIN, OUTPUT);
      digitalWrite(R4_PIN, LOW);
    }
    if ((address & 32) == 0) {
      pinMode(R5_PIN, INPUT);
    } else {
      pinMode(R5_PIN, OUTPUT);
      digitalWrite(R5_PIN, LOW);
    }
    if ((address & 64) == 0) {
      pinMode(R6_PIN, INPUT);
    } else {
      pinMode(R6_PIN, OUTPUT);
      digitalWrite(R6_PIN, LOW);
    }
    if ((address & 128) == 0) {
      pinMode(R7_PIN, INPUT);
    } else {
      pinMode(R7_PIN, OUTPUT);
      digitalWrite(R7_PIN, LOW);
    }
  #endif
}

byte TRS80Keyboard::_readCols() {
  byte result;

  #ifdef ACTIVE_KEYBOARD
    result = (digitalRead(C7_PIN) << 7) | (digitalRead(C6_PIN) << 6) | (digitalRead(C5_PIN) << 5) | (digitalRead(C4_PIN) << 4) | (digitalRead(C3_PIN) << 3) | (digitalRead(C2_PIN) << 2) | (digitalRead(C1_PIN) << 1) | digitalRead(C0_PIN);
  #else
    result = (digitalRead(C7_PIN) << 7) | (digitalRead(C6_PIN) << 6) | (digitalRead(C5_PIN) << 5) | (digitalRead(C4_PIN) << 4) | (digitalRead(C3_PIN) << 3) | (digitalRead(C2_PIN) << 2) | (digitalRead(C1_PIN) << 1) | digitalRead(C0_PIN);
    result = ~result;
  #endif

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

  _setup();
}

void TRS80Keyboard::_setup() {
  #ifdef ACTIVE_KEYBOARD
    pinMode(R0_PIN, OUTPUT);
    pinMode(R1_PIN, OUTPUT);
    pinMode(R2_PIN, OUTPUT);
    pinMode(R3_PIN, OUTPUT);
    pinMode(R4_PIN, OUTPUT);
    pinMode(R5_PIN, OUTPUT);
    pinMode(R6_PIN, OUTPUT);
    pinMode(R7_PIN, OUTPUT);

    pinMode(C0_PIN, INPUT);
    pinMode(C1_PIN, INPUT);
    pinMode(C2_PIN, INPUT);
    pinMode(C3_PIN, INPUT);
    pinMode(C4_PIN, INPUT);
    pinMode(C5_PIN, INPUT);
    pinMode(C6_PIN, INPUT);
    pinMode(C7_PIN, INPUT);
  #else
    pinMode(R0_PIN, INPUT);
    pinMode(R1_PIN, INPUT);
    pinMode(R2_PIN, INPUT);
    pinMode(R3_PIN, INPUT);
    pinMode(R4_PIN, INPUT);
    pinMode(R5_PIN, INPUT);
    pinMode(R6_PIN, INPUT);
    pinMode(R7_PIN, INPUT);

    pinMode(C0_PIN, INPUT_PULLUP);
    pinMode(C1_PIN, INPUT_PULLUP);
    pinMode(C2_PIN, INPUT_PULLUP);
    pinMode(C3_PIN, INPUT_PULLUP);
    pinMode(C4_PIN, INPUT_PULLUP);
    pinMode(C5_PIN, INPUT_PULLUP);
    pinMode(C6_PIN, INPUT_PULLUP);
    pinMode(C7_PIN, INPUT_PULLUP);
  #endif
}

int TRS80Keyboard::anyKeyPressed() {
  byte address = 0xff;
  _writeRows(address);

  delay(DELAY_READ);

  byte cols;
  cols = _readCols();

  bool result = false;
  if (cols > 0) {
    setLED();
    result = true;
  }

  // Make sure there is no accidental sinking
  _setup();

  return result;
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
  }

  // Make sure there is no accidental sinking
  _setup();
}

void TRS80Keyboard::setLED() {
  if (KEYPRESS_LED_PIN != 0) {
   digitalWrite(KEYPRESS_LED_PIN, HIGH);
  }
}

void TRS80Keyboard::resetLED() {
  if (KEYPRESS_LED_PIN != 0) {
   digitalWrite(KEYPRESS_LED_PIN, LOW);
  }
}