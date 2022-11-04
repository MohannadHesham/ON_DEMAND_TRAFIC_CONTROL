/*
 * LED.c
 *
 * Created: 10/11/2022 1:35:02 PM
 *  Author: HP
 */ 
#include "LED.h"
#include "../../Utillities/TypesDef.h"

void LED_init(uint8_t ledPort ,uint8_t ledPin)
{
	DIO_init(ledPin, ledPort, OUT); //set LED as output
}
void LED_on(uint8_t ledPort ,uint8_t ledPin)
{
	DIO_write(ledPin,ledPort,HIGH);  //write 1 on led
}
void LED_off(uint8_t ledPort ,uint8_t ledPin)
{
	DIO_write(ledPin,ledPort,LOW);  //Write 0 on led
}

void LED_toggle(uint8_t ledPort ,uint8_t ledPin)
{
	DIO_toggle(ledPin,ledPort);
}
void toggle_LED_5s(uint8_t ledPort, uint8_t ledPin)
{
	/*
		Description:
		make a delay for 5 seconds, and blink one LED during this duration
	*/
	uint32_t overflowCounter = 0;

	TCCR0 |= (1 << 2); // set pin2, 256 pre-scalar
	// Repeated number of overflow times
	while (overflowCounter < 77)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0)
		;
		// Clear the overflow flag
		TIFR |= (1 << 0);
		if (overflowCounter % 6 == 0)
		{
			LED_toggle(ledPort, ledPin);
		}
		overflowCounter++;
	}
} 

void toggle_2_LEDs_5s(uint8_t ledPort1, uint8_t ledPin1, uint8_t ledPort2, uint8_t ledPin2)
{
	/*
		Description:
		make a delay for 5 seconds, and blink two LEDs during this duration
	*/
	uint32_t overflowCounter = 0;

	TCCR0 |= (1 << 2); // set pin2, 256 pre-scalar
	// Repeated number of overflow times
	while (overflowCounter < 77)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0)
			;
		// Clear the overflow flag
		TIFR |= (1 << 0);
		if (overflowCounter % 6 == 0)
		{
			LED_toggle(ledPort1, ledPin1);
			LED_toggle(ledPort2, ledPin2);
		}
		overflowCounter++;
	}
}
