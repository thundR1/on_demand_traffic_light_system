#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "../MCAL/timer_driver/timer.h"

EN_error BUTTON_init(uint8_t pinNumber, uint8_t portNumber); // initialize button as input device
EN_error BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value); // read button state


#endif