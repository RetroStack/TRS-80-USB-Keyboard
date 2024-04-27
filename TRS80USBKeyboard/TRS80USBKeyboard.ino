#include "./config.h"

#include "./src/ByteArray.h"

#include "./src/TRS80Keyboard.h"
#include "./src/EchoKeyboard.h"

constexpr int STATE_BYTES = 8;

ByteArray previousState(STATE_BYTES);
TRS80Keyboard trs80Keyboard;
EchoKeyboard echoKeyboard;

constexpr char keyboard_map[64] = KEYBOARD_MAP;
constexpr char keyboard_shifted_map[64] = KEYBOARD_SHIFTED_MAP;

void setup() {
  trs80Keyboard.init();
  echoKeyboard.init();
}

void loop() {
  trs80Keyboard.resetLED();
  echoKeyboard.checkEnabled();

  if (trs80Keyboard.anyKeyPressed()) {

    ByteArray currentState(STATE_BYTES);
    trs80Keyboard.readKeys(&currentState);
    triggerChangedKeys(previousState, currentState);

    // Uncomment if you want to see the full state in binary (during debugging)
//    if (!previousState.isEqual(currentState)) {
//       currentState.println();
//    }

    previousState = currentState;

  } else {
    if (!previousState.isZero()) {
      echoKeyboard.releaseAll();
    }
    previousState.clear();
  }
}

// Keeps track of when a button was pressed last time
// NOTE: There is no need to be 0 here since it will be set when a button is
//       pressed. But, for sake of completeness and consistency, I set it to 0.
unsigned long lastPressTime = 0; 

void triggerChangedKeys(const ByteArray& before, const ByteArray& after) {

  bool isShifted = (SHIFT1_ROW != 0 && SHIFT1_VALUE != 0 && ((after.get(SHIFT1_ROW) & SHIFT1_VALUE) > 0)) ||
    (SHIFT2_ROW != 0 && SHIFT2_VALUE != 0 && ((after.get(SHIFT2_ROW) & SHIFT2_VALUE) > 0));

  for (int i = 0; i < STATE_BYTES; i++) {
    byte beforeTemp = before.get(i);
    byte afterTemp = after.get(i);

    for (int j = 0; j < 8; j++) {
      bool beforePressed = (beforeTemp & 1) == 1;
      bool afterPressed = (afterTemp & 1) == 1;

      byte currentKey = isShifted ? keyboard_shifted_map[i * STATE_BYTES + j] : keyboard_map[i * STATE_BYTES + j];

      // Was something pressed before and now it isn't? Then, release.
      if (beforePressed && !afterPressed) {
        echoKeyboard.release(currentKey);

      // Was something not pressed before, but not it is? Then, press.
      } else if (!beforePressed && afterPressed) {
        echoKeyboard.press(currentKey);

        // There is no need to reset this (ever) since it only will be used 
        // when a button has been pressed first.
        lastPressTime = millis();

      // Was something pressed before and still is AND the delay is not 
      // set to 0? Then, release and press.
      } else if (beforePressed && afterPressed && (REPEAT_DELAY_MS != 0)) {
        unsigned long currentPressTime = millis() - lastPressTime;

        // Checks if delay has happened, or if there was an overflow
        // If so, we trigger regardless as this is most likely not noticable.
        if (currentPressTime > REPEAT_DELAY_MS || currentPressTime < 0) {
          trs80Keyboard.setLED();
          echoKeyboard.release(currentKey);
          echoKeyboard.press(currentKey);
          lastPressTime = millis();
        }
      }

      beforeTemp >>= 1;
      afterTemp >>= 1;
    }
  }
}
