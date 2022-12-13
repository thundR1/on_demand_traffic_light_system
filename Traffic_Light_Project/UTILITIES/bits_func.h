#ifndef BITS_FUNC_H_
#define BITS_FUNC_H_

// MACROS for register and BIT operations
#define SET_BIT(_register, pin)    _register |= (1 << pin)				// example: PORTA |= (1 << 2) -> setting pin 2 in PORTA
#define CLEAR_BIT(_register, pin)  _register &= ~(1 << pin)				// example: DDRD &= ~(1 << 4) -> setting the data direction of port D pin 4 to be input
#define TOGGLE_BIT(_register, pin) _register ^= (1 << pin)				// example:	PORTC ^= (1 << 0) -> Toggling the state of pin 0 PORTC
#define READ_BIT(_register, pin)   ((_register & (1 << pin)) >> pin)	// example: ((PINB & (1 << 3)) >> 3) -> reading the state (0 or 1) of pin 3 port B

#endif