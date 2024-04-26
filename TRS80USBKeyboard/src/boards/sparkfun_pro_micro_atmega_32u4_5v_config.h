#ifndef SPARKFUN_PRO_MICRO_ATMEGA_32U4_5V_CONFIG_H
#define SPARKFUN_PRO_MICRO_ATMEGA_32U4_5V_CONFIG_H

// This is the configuration for the Sparkfun Pro Micro Atmega32u4 (5V)
// development board. There are also lots of cheap clones out there.

// This pin deactivates the sending of keyboard commands over Serial or USB. 
// By default, it will be pulled high, resulting in an automatic activation. 
// If you want to deactivate this pin, connect it to GND and all USB
// communication will stop. If you don't want to use it, simply set it to zero.
//
// NOTE: You might need to deactivate it if you want to program the system in
//       cases were there is always a keypress recognized (for example when
//       there are bugs).
#define ECHO_ENABLED_PIN 0

// This pin flashes shortly for each keypress. If you don't want it,
// simply set it to zero.
#define KEYPRESS_LED_PIN 0

// This pin activates and deactivates the column output. If you don't want to use
// it, simply set it to zero.
//
// NOTE: This is seldom used and should be most of the time 0. The cable
//       should be bound to GND to always enable it.
#define KEYBOARD_ENABLED_PIN 0

// Row/Address pins
// The following pins are all row (address) pins. Make sure to set these
// correctly in sequence, otherwise it would recognize the wrong keys.
#define R0_PIN A3
#define R1_PIN A2
#define R2_PIN A1
#define R3_PIN A0
#define R4_PIN 15
#define R5_PIN 14
#define R6_PIN 16
#define R7_PIN 10

// Column/Data pins
// The following pins are all column (data) pins. Make sure to set these
// correctly in sequence, otherwise it would recognize the wrong keys.
#define C0_PIN 2
#define C1_PIN 3
#define C2_PIN 4
#define C3_PIN 5
#define C4_PIN 6
#define C5_PIN 7
#define C6_PIN 8
#define C7_PIN 9

#endif /* SPARKFUN_PRO_MICRO_ATMEGA_32U4_5V_CONFIG_H */
