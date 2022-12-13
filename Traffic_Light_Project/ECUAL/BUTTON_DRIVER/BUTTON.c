#include "BUTTON.h"

/*
	BUTTON_init
	a) INPUT : unsigned char (pinNumber, portNumber)
	b) WORK FLOW :
		1) Input validation on the pin and port number
		2) Initialize the BUTTON as an input Device using DIO_init
	c) RETURN : EN_error (either ok or error)
*/
EN_error BUTTON_init(uint8_t pinNumber, uint8_t portNumber)
{
	if((pinNumber < 0 || pinNumber > 7) || (portNumber < 'A' || portNumber > 'D')) return error;
	DIO_init(pinNumber, portNumber, IN); // IN = 0
	return ok;
}

/*
	BUTTON_read
	a) INPUT : unsigned char (pinNumber, portNumber, *value)
	b) WORK FLOW :
		1) Input validation on the pin and port number
		2) Read BUTTON state (0 or 1) using DIO_read and the pointer variable points to this value so that it can be retrieved when needed
	c) RETURN : EN_error (either ok or error)
*/
EN_error BUTTON_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value)
{
	if((pinNumber < 0 || pinNumber > 7) || (portNumber < 'A' || portNumber > 'D')) return error;
	DIO_read(pinNumber, portNumber, value);
	return ok;
}