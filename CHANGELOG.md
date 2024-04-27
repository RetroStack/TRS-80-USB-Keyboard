# TRS-80 - USB Keyboard

## 25th April 2024 - V1.0

Initial release

Supported Models:
- Model 1
- Model 3 (Untested)
- Model 4 (Untested)

Supported Boards (Confirmed):
- Adafruit ItsyBitsy (5V)
- Arduino Due
- Arduino Leonardo
- Arduino Micro
- Arduino Uno R4
- Arduino Zero
- Sparkfun Pro Micro (Atmega 32u4; 5V)

## 27th April 2024 - V1.1
- Add support for second SHIFT key (for Model 3 & 4)
- Improved debug output: add hex
- Confirmed Model 4 (and Model 3 with the same pinout)
- Improved Model 3 & 4 scanning by emulating open collect buffer implementation
- Removed skip-out for row (not useful)
