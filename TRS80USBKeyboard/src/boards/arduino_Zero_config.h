#ifndef ARDUINO_ZERO_CONFIG_H
#define ARDUINO_ZERO_CONFIG_H

// This is the configuration for the Arduino Zero development board.

// This pin deactivates the sending of keyboard commands over Serial or USB. 
// By default, it will be pulled high, resulting in an automatic activation. 
// If you want to deactivate this pin, connect it to GND and all USB
// communication will stop. If you don't want to use it, simply set it to zero.
//
// NOTE: You might need to deactivate it if you want to program the system in
//       cases were there is always a keypress recognized (for example when
//       there are bugs).
#define ECHO_ENABLED_PIN 12

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
#define R0_PIN A0
#define R1_PIN A1
#define R2_PIN A2
#define R3_PIN A3
#define R4_PIN A4
#define R5_PIN A5
#define R6_PIN 2
#define R7_PIN 3

// Column/Data pins
// The following pins are all column (data) pins. Make sure to set these
// correctly in sequence, otherwise it would recognize the wrong keys.
#define C0_PIN 4
#define C1_PIN 5
#define C2_PIN 6
#define C3_PIN 7
#define C4_PIN 8
#define C5_PIN 9
#define C6_PIN 10
#define C7_PIN 11

#endif /* ARDUINO_ZERO_CONFIG_H */
