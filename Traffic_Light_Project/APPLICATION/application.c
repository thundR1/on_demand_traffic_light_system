#include "application.h"
/*
	App_init
	a) INPUT : void
	b) WORK FLOW :
		1) init Car LEDs
		2) init Pedestrian LEDs
		3) init BUTTON on PORTD pin 2
		4) init Timer0
		5) Enable interrupts
	c) RETURN : void
*/
void App_init(void)
{
	LED_init(GREEN_LED_CAR, CAR_LEDS_PORT);
	LED_init(YELLOW_LED_CAR, CAR_LEDS_PORT);
	LED_init(RED_LED_CAR, CAR_LEDS_PORT);
	
	LED_init(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_init(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_init(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	
	BUTTON_init(PIN_2, PORT_D);
	
	TIMER_init();
	
	sei();
	Rising_Edge();
	Enable_External_INTERRUPT();
}

/*
	App_Start
	1) Starts the APP in normal mode
*/
void App_Start(void)
{
	normal_mode();
}

/*
	normal_mode
	a) INPUT : void
	b) WORK FLOW :
		1) make sure all pedestrian LEDs are OFF
		2) SET GREEN_LED_CAR for 5 sec and then turn it off
		3) blink the YELLOW_LED_CAR for 5sec (0.5sec off and 0.5sec on)
		4) SET RED_LED_CAR for 5 sec and then turn it off
		5) blink the yellow again and keep repeating this process if the button is not pressed
	c) RETURN : void
*/
void normal_mode(void)
{
	lb : LED_on(GREEN_LED_CAR, CAR_LEDS_PORT);
	TIMER_ms_delay(5000);
	LED_off(GREEN_LED_CAR, CAR_LEDS_PORT);
	
	blink_car_yellow();
	
	LED_on(RED_LED_CAR, CAR_LEDS_PORT);
	TIMER_ms_delay(5000);
	LED_off(RED_LED_CAR, CAR_LEDS_PORT);
	
	blink_car_yellow();
	goto lb;
}

/*
	blink_car_yellow
	a) INPUT : void
	b) WORK FLOW :
		1) blink the YELLOW_LED_CAR for 5sec (0.5sec off and 0.5sec on)
	c) RETURN : void
*/
void blink_car_yellow(void)
{
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_on(YELLOW_LED_CAR, CAR_LEDS_PORT);
		TIMER_ms_delay(500);
		LED_off(YELLOW_LED_CAR, CAR_LEDS_PORT);
		TIMER_ms_delay(500);
	}
}

/*
	blink_pedestrian_yellow
	a) INPUT : void
	b) WORK FLOW :	
		1) blink the YELLOW_LED_PEDESTRIAN for 5sec (0.5sec off and 0.5sec on)
	c) RETURN : void
*/
void blink_pedestrian_yellow(void)
{
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_on(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
		TIMER_ms_delay(500);
		LED_off(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
		TIMER_ms_delay(500);
	}
}

/*
	blink_both_yellow
	a) INPUT : void
	b) WORK FLOW :	
		1) Both Yellow LEDs blinks together at the same time for 5sec (0.5sec off and 0.5sec on)
	c) RETURN : void
*/
void blink_both_yellow(void)
{
	for(uint8_t i = 0; i < 5; i++)
	{
		LED_on(YELLOW_LED_CAR, CAR_LEDS_PORT);
		LED_on(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);	
		TIMER_ms_delay(500);
		
		LED_off(YELLOW_LED_CAR, CAR_LEDS_PORT);
		LED_off(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
		TIMER_ms_delay(500);
	}
}
/*
	pedestrian_mode_CAR_IS_RED
	a) INPUT : void
	b) WORK FLOW :
		1) SET green pedestrian LED and then delay for 5sec [which indicates that pedestrians have 5sec to walk and cars are stopped]
		2) Turn off red car LED and , [pedestrian green is still on] , blink both yellow leds
		3) Turn off green pedestrian led , turn on red pedestrian led and green car led , delay 5sec , [which indicates that pedestrians can't walk now and cars can]
		4) Turn off all pedestrian leds [which indicates that the walk request has finished and the pedestrian has moved]
		5) re-Enable the interrupts and go back to normal mode
	c) RETURN : void
*/
void pedestrian_mode_CAR_IS_RED(void)
{
	LED_on(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	TIMER_ms_delay(5000);
	LED_off(RED_LED_CAR, CAR_LEDS_PORT);
	
	blink_both_yellow();
	
	LED_off(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_on(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_on(GREEN_LED_CAR, CAR_LEDS_PORT);
	TIMER_ms_delay(5000);
	
	LED_off(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT); LED_off(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT); LED_off(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);	
	
	sei();
	Rising_Edge();
	Enable_External_INTERRUPT();
	normal_mode();
}

/*
	pedestrian_mode [in order for it to be called then either GREEN_LED_CAR or YELLOW_LED_CAR was ON when the Button was pressed]
	a) INPUT : void
	b) WORK FLOW :
		1) SET RED_LED_PEDESTRIAN and blink both the yellow LEDs
		2) turn off RED_LED_PEDESTRIAN , SET GREEN_LED_PEDESTRIAN , turn off GREEN_LED_CAR , SET RED_LED_CAR
		3) delay for 5sec
		4) GREEN_LED_PEDESTRIAN stays ON , RED_LED_CAR goes off , and blink both yellow
		5) Turn off GREEN_LED_PEDESTRIAN , SET RED_LED_PEDESTRIAN , SET GREEN_LED_CAR [Which tells the pedestrian to stop moving AND the cars to move]
		6) delay 5sec
		7) Turn off all pedestrian leds [which indicates that the walk request has finished and the pedestrian has moved]
		8) re-Enable the interrupts and go back to normal mode
	c) RETURN : void
*/
void pedestrian_mode_CAR_NOT_RED(void)
{
	LED_on(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	blink_both_yellow();
	
	LED_off(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_on(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_off(GREEN_LED_CAR, CAR_LEDS_PORT);
	LED_on(RED_LED_CAR, CAR_LEDS_PORT);
	
	TIMER_ms_delay(5000);
	
	LED_off(RED_LED_CAR, CAR_LEDS_PORT);
	blink_both_yellow();
	
	LED_off(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_on(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	LED_on(GREEN_LED_CAR, CAR_LEDS_PORT);
	
	TIMER_ms_delay(5000);
	LED_off(RED_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT); LED_off(YELLOW_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT); LED_off(GREEN_LED_PEDESTRIAN, PEDESTRIAN_LEDS_PORT);
	
	sei();
	Rising_Edge();
	Enable_External_INTERRUPT();
	normal_mode();
}

/*
	ISR
	a) INPUT : interrupt0 vector (__vector_1)
	b) WORK FLOW :
		1) cli to disable the interrupt to avoid multiple button click actions
		2) read red LED state to decide whether it's ON or OFF
		3) if RED_LED_CAR is ON (state == 1) call pedestrian_mode_CAR_IS_RED() function
		4) if CAR_GREEN or CAR_YELLOW is ON then call pedestrian_mode_CAR_NOT_RED() function
		5) ENABLE all interrupts again after any of this two functions
*/
ISR(INT0_vec)
{
	cli();
	uint8_t state; DIO_read(RED_LED_CAR, CAR_LEDS_PORT, &state);
	if(state)
	{
		pedestrian_mode_CAR_IS_RED();
	}
	else
	{
		pedestrian_mode_CAR_NOT_RED();
	}
}
