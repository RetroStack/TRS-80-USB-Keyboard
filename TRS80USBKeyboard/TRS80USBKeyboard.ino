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
  trs80Keyboard.reset();
  echoKeyboard.checkEnabled();

  if (trs80Keyboard.anyKeyPressed()) {

    ByteArray currentState(STATE_BYTES);
    trs80Keyboard.readKeys(&currentState);

    if (!previousState.isEqual(currentState)) {
      triggerChangedKeys(previousState, currentState);

      // Uncomment if you want to see the full state in binary (during debugging)
      // currentState.println();

      previousState = currentState;
    }

  } else {
    if (!previousState.isZero()) {
      echoKeyboard.releaseAll();
    }
    previousState.clear();
  }
}

void triggerChangedKeys(const ByteArray& before, const ByteArray& after) {

  bool isShifted = (after.get(7) & 1) > 0;

  for (int i = 0; i < STATE_BYTES; i++) {
    byte beforeTemp = before.get(i);
    byte afterTemp = after.get(i);

    for (int j = 0; j < 8; j++) {
      bool beforePressed = (beforeTemp & 1) == 1;
      bool afterPressed = (afterTemp & 1) == 1;

      byte currentKey = isShifted ? keyboard_shifted_map[i * STATE_BYTES + j] : keyboard_map[i * STATE_BYTES + j];
      if (beforePressed && !afterPressed) {
        echoKeyboard.release(currentKey);
      } else if (!beforePressed && afterPressed) {
        echoKeyboard.press(currentKey);
      }

      beforeTemp >>= 1;
      afterTemp >>= 1;
    }
  }
}
