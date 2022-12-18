#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED_DRIVER/LED.h" // DIO is included in LED.h
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "../UTILITIES/interrupt.h"

void App_init(void);            // Initialize the application
void App_Start(void);           // Starts the application

/* Helper Functions */
void normal_mode(void);                 // Builds the normal mode logic
void blink_car_yellow(void);            // blinks the CAR yellow LED
void blink_pedestrian_yellow(void);     // blinks the PEDESTRIANS yellow LED
void blink_both_yellow(void);           // blinks both yellow LEDs at the same time
void pedestrian_mode_CAR_IS_RED(void);  // Builds pedestrian mode logic if button was clicked with car red led is ON
void pedestrian_mode_CAR_NOT_RED(void); // Builds the pedestrian mode logic if button was clicked with car led is OFF

#endif