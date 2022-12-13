#ifndef DIO_H_
#define DIO_H_

#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/bits_func.h"

// Driver Macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Pins Defines
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

// Direction Defines
#define IN 0
#define OUT 1

// Values Defines
#define LOW 0
#define HIGH 1

EN_error DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // initialize DIO direction
EN_error DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // Write data to PIN
EN_error DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // Toggle PIN state
EN_error DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value); // Read PIN state

#endif