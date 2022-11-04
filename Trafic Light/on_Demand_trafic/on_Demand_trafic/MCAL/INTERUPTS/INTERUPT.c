/*
 * INTERUPT.c
 *
 * Created: 10/17/2022 7:31:47 PM
 *  Author: Mohannad Hesham
 */ 

#include "INTERUPTS.h"

void interupts_init()
{
	sei();

	//Choosing the external interrupt sense (sense on the rising edge)
	MCUCR |= (1<<0) | (1<<1);
	//Enable External interrupt 0(INT0)
	GICR |= (1<<6);

	SREG |= (1<<7);	





}