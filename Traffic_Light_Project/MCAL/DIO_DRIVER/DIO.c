#include "DIO.h"

/*
	DIO_init
	a) INPUT : unsigned char (pinNumber, portNumber, direction)
	b) WORK FLOW :
		1) Input Validation on the direction
		2) Switch on every possible portNumber
		3) Decide whether SETTING or CLEARING the bit 'pinNumber' in the DDRx (x = portNumber) register according to the direction using the CLEAR_BIT and SET_BIT MACROS
	c) RETURN : EN_error (either ok or error)
*/
EN_error DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	if((direction != IN) && (direction != OUT)) return error;
	if((pinNumber < 0 || pinNumber > 7) || (portNumber < 'A' || portNumber > 'D')) return error;
	switch(portNumber)
	{
		case PORT_A:
			if(direction == IN) CLEAR_BIT(DDRA, pinNumber);
			else if(direction == OUT) SET_BIT(DDRA, pinNumber);
		break;
		case PORT_B:
			if(direction == IN) CLEAR_BIT(DDRB, pinNumber);
			else if(direction == OUT) SET_BIT(DDRB, pinNumber);
		break;
		case PORT_C:
			if(direction == IN) CLEAR_BIT(DDRC, pinNumber);
			else if(direction == OUT) SET_BIT(DDRC, pinNumber);
		break;
		case PORT_D:
			if(direction == IN) CLEAR_BIT(DDRD, pinNumber);
			else if(direction == OUT) SET_BIT(DDRD, pinNumber);
		break;
		default:
		break;
	}
	return ok;
}

/*
	DIO_write
	a) INPUT : unsigned char (pinNumber, portNumber, value)
	b) WORK FLOW :
		1) Input Validation (LOW , HIGH ) value
		2) Switch on every Possible portNumber
		3) decide whether SETTING or CLEARING the bit 'pinNumber' in Register PORTx (x = portNumber) according to the 'value' (LOW or HIGH) using the CLEAR_BIT and SET_BIT MACROS
	c) RETURN : EN_error (either ok or error)
*/
EN_error DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	if(value != LOW && value != HIGH) return error;
	if((pinNumber < 0 || pinNumber > 7) || (portNumber < 'A' || portNumber > 'D')) return error;
	switch(portNumber)
	{
		case PORT_A:
			if(value == LOW) CLEAR_BIT(PORTA, pinNumber);
			else if(value == HIGH) SET_BIT(PORTA, pinNumber);
		break;
		case PORT_B:
			if(value == LOW) CLEAR_BIT(PORTB, pinNumber);
			else if(value == HIGH) SET_BIT(PORTB, pinNumber);
		break;
		case PORT_C:
			if(value == LOW) CLEAR_BIT(PORTC, pinNumber);
			else if(value == HIGH) SET_BIT(PORTC, pinNumber);
		break;
		case PORT_D:
			if(value == LOW) CLEAR_BIT(PORTD, pinNumber);
			else if(value == HIGH) SET_BIT(PORTD, pinNumber);
		break;
		default:
		break;
	}
	return ok;
}

/*
	DIO_toggle
	a) INPUT : unsigned char (pinNumber, portNumber)
	b) WORK FLOW :
		1) Input Validation on the pin and port numbers
		2) Switch on every Possible portNumber
		3) Toggle the bit 'pinNumber' in register PORTx (x = portNumber) depending on the portNumber using the TOGGLE_BIT MACRO
	c) RETURN : EN_error (either ok or error)
*/
EN_error DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	if((pinNumber < 0 || pinNumber > 7) || (portNumber < 'A' || portNumber > 'D')) return error;
	switch(portNumber)
	{
		case PORT_A:
			TOGGLE_BIT(PORTA, pinNumber);
		break;
		case PORT_B:
			TOGGLE_BIT(PORTB, pinNumber);
		break;
		case PORT_C:
			TOGGLE_BIT(PORTC, pinNumber);
		break;
		case PORT_D:
			TOGGLE_BIT(PORTD, pinNumber);
		break;
		default:
		break;
	}
	return ok;
}

/*
	DIO_read
	a) INPUT : unsigned char (pinNumber, portNumber, *value)
	b) WORK FLOW :	
		1) Input Validation on pin and port numbers
		2) Switch on every Possible portNumber
		3) Store the STATE (0 or 1) of the bit 'pinNumber' in the *value (derefrenecing the given address) using the register PINx (x = portNumber) to read those states
	c) RETURN : EN_error (either ok or error)
*/
EN_error DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value)
{
	if((pinNumber < 0 || pinNumber > 7) || (portNumber < 'A' || portNumber > 'D')) return error;
	switch(portNumber)
	{
		case PORT_A:
			*value = READ_BIT(PINA, pinNumber);
		break;
		case PORT_B:
			*value = READ_BIT(PINB, pinNumber);
		break;
		case PORT_C:
			*value = READ_BIT(PINC, pinNumber);
		break;
		case PORT_D:
			*value = READ_BIT(PIND, pinNumber);
		break;
		default:
		break;
	}
	return ok;
}