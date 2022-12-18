#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "../MCAL/timer_driver/timer.h"

// Car LEDs PIN Number
#define CAR_LEDS_PORT PORT_A
#define GREEN_LED_CAR  0
#define YELLOW_LED_CAR 1
#define RED_LED_CAR    2

// Car LEDs PIN Number
#define PEDESTRIAN_LEDS_PORT PORT_B
#define GREEN_LED_PEDESTRIAN   0
#define YELLOW_LED_PEDESTRIAN  1
#define RED_LED_PEDESTRIAN     2

EN_error LED_init(uint8_t ledPin, uint8_t ledPort);   /* Led initialization according to its pin and port as OUTPUT device */
EN_error LED_on(uint8_t ledPin, uint8_t ledPort);     /* Turns LED ON according to its pin and port by using the PORT Register to set it HIGH */
EN_error LED_off(uint8_t ledPin, uint8_t ledPort);    /* Turns LED OFF according to its pin and port by using the PORT Register to set it LOW */
EN_error LED_toggle(uint8_t ledPin, uint8_t ledPort); /* Toggles The LED state according to its pin and port */


#endif