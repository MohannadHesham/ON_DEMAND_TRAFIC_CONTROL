/*
 * Button.c
 *
 * Created: 10/11/2022 1:33:41 PM
 *  Author: HP
 */ 
#include "Button.h"


//initialize
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPin,buttonPort,IN);
}

//button rad
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPin, buttonPort, value);
}