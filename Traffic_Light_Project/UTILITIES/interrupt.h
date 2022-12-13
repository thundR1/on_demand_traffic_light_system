#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "registers.h"

// interrupt0 vector
#define INT0_vec __vector_1

// global interrupt enable, disable
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

// interrupt sense as rising edge
#define Rising_Edge() MCUCR |= (1 << 0) | (1 << 1)

// Enable external interrupt 0
#define Enable_External_INTERRUPT() GICR |= (1 << 6)

// the ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#endif