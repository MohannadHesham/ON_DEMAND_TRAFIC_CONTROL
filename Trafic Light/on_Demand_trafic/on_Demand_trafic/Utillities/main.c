/*
 * on_Demand_trafic.c
 *
 * Created: 10/11/2022 1:21:17 PM
 * Author : HP
 */ 
#include "DIO.h"
#include <avr/io.h>
#define F_CPU 1000000UL

int main(void)
{
	
	DIO_init(PORT_A,PIN0,OUT);
	
    while (1) 
    {
		//App_init();
		//App_start();
	
		DIO_write(PORT_A,PIN0,HIGH);
	
    }
}

