#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTILITIES/registers.h"

EN_error TIMER_init(void); // Timer0
EN_error TIMER_ms_delay(double ms); // Delay in ms

#endif