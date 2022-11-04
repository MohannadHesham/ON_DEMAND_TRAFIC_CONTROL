/*
 * TImer.c
 *
 * Created: 10/11/2022 1:31:14 PM
 *  Author: Mohannad Hesham
 */ 

#include "Timer.h"
uint32_t overflowCounter = 0;
void Timer0_init_normal()
{
	TCCR0 = 0x00; //Normal mode
	TCNT0 = 0x00; //set timer 0
}


void TIMER0_start(uint32_t preScalar,uint32_t number_of_overflow)
{
    uint32_t overflowCounter = 0;
	
    switch (preScalar)
    {
	    case 1:
	    TCCR0 |= (1 << 0); // set pin0
	    break;
	    case 8:
	    TCCR0 |= (1 << 1); // set pin1
	    break;
	    case 64:
	    TCCR0 |= 3; // set pin0 and pin1
	    break;
	    case 256:
	    TCCR0 |= (1 << 2); // set pin2
	    break;
	    case 1024:
	    TCCR0 |= 5; // set pin0 and pin2
	    break;
	    default:
	    // Error handling
	    break;
    }
    // Repeated number of overflow times
    while (overflowCounter < number_of_overflow)
    {
	    // wait the overflow flat to be set
	    while ((TIFR & (1 << 0)) == 0);
	    // Clear the overflow flag
	    TIFR |= (1 << 0);
	    overflowCounter++;
    }
	
}

void Timer_stop()
{
	TCCR0 = 0x00;
}

	

/*void Timer_delay(uint16_t delay)
{
		TIMER0_start(1024); //set prescaler 1024
		uint32_t T_tick=  1024 / F_cpu;
		uint32_t T_max_delay = 256* T_tick;
		uint32_t number_of_overflow = delay / T_max_delay;
		uint32_t Timer_initial = 256 -((delay/T_tick)/number_of_overflow);
		uint8_t overflow = 0;
		uint32_t overflowCounter = 0;
		
		
		
		
		
	// Repeated number of overflow times
	while (overflow < number_of_overflow)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0);
		// Clear the overflow flag
		TIFR |= (1 << 0);
		overflowCounter++;
	}
	overflowCounter = 0;
	Timer_stop();
}*/

void delay_5s(void)
{
	TIMER0_start(256, 77);
	Timer_stop();
}
