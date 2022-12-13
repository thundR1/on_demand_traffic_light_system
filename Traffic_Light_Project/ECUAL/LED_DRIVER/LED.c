#include "LED.h"

/*
	LED_init
	a) INPUT : unsigned char (ledPin, ledPort)
	b) WORK FLOW :	
		1) Input validation on LED pin and LED port
		2) Initialize LED as an output device using the DIO_init function
	c) RETURN : EN_error (either ok or error)
*/
EN_error LED_init(uint8_t ledPin, uint8_t ledPort)
{
	if((ledPin < 0 || ledPin > 7) || (ledPort < 'A' || ledPort > 'D')) return error; // Validate For PIN and PORT input
	DIO_init(ledPin, ledPort, OUT); // OUT = 1
	return ok;
}

/*
	LED_on
	a) INPUT : unsigned char (ledPin, ledPort)
	b) WORK FLOW :
		1) Input validation on LED pin and LED port
		2) Turns LED on by writing HIGH on the pin which the LED connected to using DIO_write function
	c) RETURN : EN_error (either ok or error)
*/
EN_error LED_on(uint8_t ledPin, uint8_t ledPort)
{
	if((ledPin < 0 || ledPin > 7) || (ledPort < 'A' || ledPort > 'D')) return error;
	DIO_write(ledPin, ledPort, HIGH); // HIGH = 1
	return ok;
}

/*
	LED_off
	a) INPUT : unsigned char (ledPin, ledPort)
	b) WORK FLOW :
		1) Input validation on LED pin and LED port
		2) Turns LED off by writing LOW on the pin which the LED connected to using DIO_write function
	c) RETURN : EN_error (either ok or error)
*/
EN_error LED_off(uint8_t ledPin, uint8_t ledPort)
{
	if((ledPin < 0 || ledPin > 7) || (ledPort < 'A' || ledPort > 'D')) return error;
	DIO_write(ledPin, ledPort, LOW); // LOW = 0
	return ok;
}

/*
	LED_toggle
	a) INPUT : unsigned char (ledPin, ledPort)
	b) WORK FLOW :
		1) Input validation on LED pin and LED port
		2) Toggles LED state (if 0 -> 1   ,   if 1 -> 0) using DIO_toggle function
	c) RETURN : EN_error (either ok or error)
*/
EN_error LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	if((ledPin < 0 || ledPin > 7) || (ledPort < 'A' || ledPort > 'D')) return error;
	DIO_toggle(ledPin, ledPort);
	return ok;
}