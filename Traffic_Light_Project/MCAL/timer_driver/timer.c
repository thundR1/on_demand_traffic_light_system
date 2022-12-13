#include "timer.h"
#include "../../UTILITIES/bits_func.h"
#include <math.h>

/*
	TIMER_init
	a) INPUT : void
	b) WORK FLOW :
		1) Initialize the timer in normal mode by clearing bit number 3 & 6 in TCCR0 register using CLEAR_BIT MACROS
	c) RETURN : EN_error
*/
EN_error TIMER_init(void)
{
	CLEAR_BIT(TCCR0, 3); CLEAR_BIT(TCCR0, 6); /* Using normal mode */
	return ok;
}

/*
	TIMER_ms_delay
	a) INPUT : double ms (Requested delay Time in millisecond)
	b) WORK FLOW :
		1) Input validation on the given milliseconds (ms)
		2) variables declarations
		3) Calculate needed values for timer usage (T_tick, T_maxDelay, T_init_value, num_of_overflows)
		4) Checking if input delay is < or = or > than the max possible delay (T_maxDelay)
		5) deciding number_of_overflows needed in each case
		6) Use the timer
		7) Stop the timer
	c) RETURN : EN_error (either ok or error)
*/
EN_error TIMER_ms_delay(double ms)
{
	if(ms < 0) return error;
	double T_maxDelay, T_tick;	// max time delay , Time of 1 tick
	uint32_t Timer_init_value, num_of_overflows, count_of_overflows = 0;
	T_tick = 1.0 / 1000000.0; // No Prescaler , T_tick = 0.000001 = 1 micro sec
	T_maxDelay = (1 << 8) * T_tick; // = 0.000256 = 256 micro sec
	if((ms / 1000.0) < T_maxDelay) // dividing by 1000 to convert milli sec to sec
	{
		Timer_init_value = (uint32_t)(T_maxDelay - (ms / 1000.0)) / T_tick;
		num_of_overflows = 1; // We only need 1 overflow in case of ms < T_maxDelay
		
	}
	else if((ms / 1000.0) == T_maxDelay)
	{
		Timer_init_value = 0; // Timer start counting from 0
		num_of_overflows = 1; // Only need 1 overflow in case of ms == T_maxDelay
	}
	else
	{
		num_of_overflows = (uint32_t)ceil((ms  / 1000.0) / T_maxDelay);
		Timer_init_value = (1 << 8) - ((ms / 1000.0) / T_tick) / num_of_overflows;
	}
	TCNT0 = Timer_init_value;
	TCCR0 |= (1 << 0); // Set No Prescaler
	while(count_of_overflows < num_of_overflows){
		while(READ_BIT(TIFR, 0) == 0); // Busy wait
		SET_BIT(TIFR, 0); // Clr overflow flag
		count_of_overflows++;
	}
	TCCR0 = 0x00; // stopping timer
	return ok;
}