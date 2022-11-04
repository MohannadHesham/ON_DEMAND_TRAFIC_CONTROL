/*
 * on_Demand_trafic.c
 *
 * Created: 10/11/2022 1:21:17 PM
 * Author : HP
 */ 
#include "APP/APP.h"
#include <avr/io.h>
#define F_CPU 1000000UL

int main(void)
{
	
	
	
    while (1) 
    {
	App_init();
	App_start();
	
}
}