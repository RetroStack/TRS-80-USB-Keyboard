#include "../config.h"

#if defined(USB_KEYBOARD) && !defined(DEBUG)
#include <Keyboard.h>
#endif

#include "./EchoKeyboard.h"

void EchoKeyboard::init() {
#if defined(DEBUG) || !defined(USB_KEYBOARD)
  Serial.begin(SERIAL_BAUD_RATE);
#endif

  if (ECHO_ENABLED_PIN != 0) {
    pinMode(ECHO_ENABLED_PIN, INPUT_PULLUP);
  }

  checkEnabled();
}

void EchoKeyboard::press(byte code) {
#if defined(DEBUG)
  Serial.print("Press: ");
  Serial.print((char)code);
  Serial.print(" (");
  Serial.print(code);
  Serial.print(") - 0x");
  Serial.print(code, 16);
  Serial.print(" - b");
  Serial.println(code, 2);
#elif defined(USB_KEYBOARD)
  if (_enabled) Keyboard.press(code);
#else
  if (_enabled) Serial.print(code);
#endif
}

void EchoKeyboard::release(byte code) {
#if defined(DEBUG)
  Serial.print("Release: ");
  Serial.print((char)code);
  Serial.print(" (");
  Serial.print(code);
  Serial.print(") - 0x");
  Serial.print(code, 16);
  Serial.print(" - b");
  Serial.println(code, 2);
#elif defined(USB_KEYBOARD)
  if (_enabled) Keyboard.release(code);
#endif
}

void EchoKeyboard::releaseAll() {
#ifdef DEBUG
  Serial.println("Release all");
#elif defined(USB_KEYBOARD)
  if (_enabled) Keyboard.releaseAll();
#endif
}

void EchoKeyboard::checkEnabled() {
  if (ECHO_ENABLED_PIN != 0) {
    _enabled = digitalRead(ECHO_ENABLED_PIN);
  } else {
    _enabled = true;
  }
}