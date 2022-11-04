/*
 * DIO.c
 *
 * Created: 10/11/2022 1:28:47 PM
 *  Author: HP
 */ 

#include "DIO.h"

void DIO_init(uint8_t pinNumber, uint8_t portNumber , uint8_t direction) // Initialize dio direction
{
	switch(portNumber)
	{
		
		
		case PORT_A :
		if (direction == IN)

		{

			DDRA &= ~(1<<pinNumber);
		}
		
		else if (direction == OUT)
		{
			DDRA |= (1<<pinNumber);
		}
		
		else
		{
			//error handling return
		}
		break;
		
		case PORT_B :

		if (direction == IN)

		{

			DDRB &= ~(1<<pinNumber);
		}
		
		else if (direction == OUT)
		{
			DDRB |= (1<<pinNumber);
		}
		else
		{
			//error handling return
		}
		break;
		
		case PORT_C :

		if (direction == IN)

		{

			DDRC &= ~(1<<pinNumber);
		}
		
		else if (direction == OUT)
		{
			DDRC |= (1<<pinNumber);
		}
		else
		{
			//error handling return
		}
		break;
		
		case PORT_D :

		if (direction == IN)

		{

			DDRD &= ~(1<<pinNumber);
		}
		
		else if (direction == OUT)
		{
			DDRD |= (1<<pinNumber);
		}
		else
		{
			//error handling return
		}
		break;
		
	}
	
	
}




void DIO_write(uint8_t pinNumber, uint8_t portNumber , uint8_t value)
{
	switch(portNumber)
	{
		
		
		case PORT_A :
		if (value == LOW)

		{

			PORTA &= ~(1<<pinNumber); // write 0
		}
		
		else if (value == HIGH)
		{
			PORTA |= (1<<pinNumber); // write 1
		}
		
		else
		{
			//error handiling return
		}
		break;
		
		case PORT_B :

		if (value == LOW)

		{

			PORTB &= ~(1<<pinNumber);  //write 0
		}
		
		else if (value == HIGH)
		{
			PORTB |= (1<<pinNumber);  //write 1
		}
		else
		{
			//error handiling return
		}
		break;
		
				case PORT_C :

		if (value == LOW)

		{

			PORTC &= ~(1<<pinNumber);  //write 0
		}
		
		else if (value == HIGH)
		{
			PORTC |= (1<<pinNumber);  //write 1
		}
		else
		{
			//error handiling return
		}
		break;
		
				case PORT_D :

		if (value == LOW)

		{

			PORTD &= ~(1<<pinNumber);  //write 0
		}
		
		else if (value == HIGH)
		{
			PORTD |= (1<<pinNumber);  //write 1
		}
		else
		{
			//error handiling return
		}
		break;
		
		
		
	}//switch

	
	
}


void DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
		switch(portNumber)
	{
		
		
		case PORT_A :
		
			PORTA ^= (1<<pinNumber); // write 1
		
		break;
		
		case PORT_B :

		
			PORTB ^= (1<<pinNumber);  //write 1
		
		break;
		
		case PORT_C :

		PORTC ^= (1<<pinNumber);  //write 1
	
		break;
		
		case PORT_D :

			PORTD ^= (1<<pinNumber);  //write 1
	
		break;
	}
}

void DIO_read(uint8_t pinNumber, uint8_t portNumber , uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = (PORTA & (1<<pinNumber))>>pinNumber; // get state -> read bit
		
		case PORT_B:
		*value = (PORTB & (1<<pinNumber))>>pinNumber; // get state -> read bit

		case PORT_C:
		*value = (PORTC & (1<<pinNumber))>>pinNumber; // get state -> read bit
		
		case PORT_D:
		*value = (PORTD & (1<<pinNumber))>>pinNumber; // get state -> read bit
		break;
	}
	
}