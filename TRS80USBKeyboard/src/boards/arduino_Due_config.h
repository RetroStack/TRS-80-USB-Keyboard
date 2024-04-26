#ifndef ARDUINO_DUE_CONFIG_H
#define ARDUINO_DUE_CONFIG_H

// This is the configuration for the Arduino DUE development board.

// This pin deactivates the sending of keyboard commands over Serial or USB. 
// By default, it will be pulled high, resulting in an automatic activation. 
// If you want to deactivate this pin, connect it to GND and all USB
// communication will stop. If you don't want to use it, simply set it to zero.
//
// NOTE: You might need to deactivate it if you want to program the system in
//       cases were there is always a keypress recognized (for example when
//       there are bugs).
#define ECHO_ENABLED_PIN 53

// This pin flashes shortly for each keypress. If you don't want it,
// simply set it to zero.
#define KEYPRESS_LED_PIN 13

// This pin activates and deactivates the column output. If you don't want to use
// it, simply set it to zero.
//
// NOTE: This is seldom used and should be most of the time 0. The cable
//       should be bound to GND to always enable it.
#define KEYBOARD_ENABLED_PIN 0

// Row/Address pins
// The following pins are all row (address) pins. Make sure to set these
// correctly in sequence, otherwise it would recognize the wrong keys.
#define R0_PIN 22
#define R1_PIN 24
#define R2_PIN 26
#define R3_PIN 28
#define R4_PIN 30
#define R5_PIN 32
#define R6_PIN 34
#define R7_PIN 36

// Column/Data pins
// The following pins are all column (data) pins. Make sure to set these
// correctly in sequence, otherwise it would recognize the wrong keys.
#define C0_PIN 38
#define C1_PIN 40
#define C2_PIN 42
#define C3_PIN 44
#define C4_PIN 46
#define C5_PIN 48
#define C6_PIN 50
#define C7_PIN 52

#endif /* ARDUINO_DUE_CONFIG_H */
