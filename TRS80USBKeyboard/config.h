#ifndef CONFIG_H
#define CONFIG_H

// When active, uses Serial communication instead of sending data over USB
//#define DEBUG

// When active, uses USB communication for echoing keyboard input instead
// of Serial. When sent over serial, only the keypresses will be echo'd.
#define USB_KEYBOARD

// Activate one of the following lines to target the right keyboard
// Make sure to only activate one of these.
#define Model1
// #define Model3
//#define Model4

// Activate one of the following boards to target the right platform
// Make sure to only activate one of these.
// #define Adafruit_ItsyBitsy_5V
#define Sparkfun_ProMicro_ATMEGA32u4_5V
// #define Arduino_Leonardo
// #define Arduino_Zero
// #define Arduino_UnoR4
// #define Arduino_Due
// #define Arduino_Micro

// If none of the both work for you, use the one below and edit the config.
// #define Arduino_Custom

// Defines the baut rate of the serial communication when debugging
#define SERIAL_BAUD_RATE 9600

// Defines the delay in milliseconds between keypress sends when a key 
// stays pressed. Set to 0 to deactivate.
#define REPEAT_DELAY_MS 0 // 250 (common)

#endif /* CONFIG_H */

// ------------------------------------------------------------------

// Keyboard Type
#if defined(Model1)
#include "./src/models/model1Config.h"
#elif defined(Model3)
#include "./src/models/model3Config.h"
#elif defined(Model4)
#include "./src/models/model4Config.h"
#endif

// Keyboard Type
#if defined(Adafruit_ItsyBitsy_5V)
#include "./src/boards/adafruit_ItsyBitsy_5V_config.h"
#elif defined(Sparkfun_ProMicro_ATMEGA32u4_5V)
#include "./src/boards/sparkfun_pro_micro_atmega_32u4_5v_config.h"
#elif defined(Arduino_Leonardo)
#include "./src/boards/arduino_Leonardo_config.h"
#elif defined(Arduino_Micro)
#include "./src/boards/arduino_Micro_config.h"
#elif defined(Arduino_Due)
#include "./src/boards/arduino_Due_config.h"
#elif defined(Arduino_Zero)
#include "./src/boards/arduino_Zero_config.h"
#elif defined(Arduino_UnoR4)
#include "./src/boards/arduino_UnoR4_config.h"
#elif defined(Arduino_Custom)
#include "./arduino_custom_config.h"
#endif
