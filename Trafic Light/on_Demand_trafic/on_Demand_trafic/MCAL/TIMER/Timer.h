/*
 * Timer.h
 *
 * Created: 10/11/2022 1:30:56 PM
 *  Author: HP
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utillities/Register.h"
#include "../../Utillities/TypesDef.h"
#define F_cpu 1000000



void Timer0_init();								// Initialize timer0
void TIMER0_start(uint32_t preScalar, uint32_t number_of_overflow);			// Start timer0 with no prescalar
void Timer_stop();
void delay_5s(void);
void Timer_delay(uint32_t delay);

#endif /* TIMER_H_ */