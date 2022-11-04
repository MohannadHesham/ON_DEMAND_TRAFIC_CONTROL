/*
 * Button.h
 *
 * Created: 10/11/2022 1:34:00 PM
 *  Author: HP
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
//#include "../../Utilities/TypesDef.h"
#include"../../MCAL/DIO/DIO.h"

#define BUTTON_PORT  PORT_D
#define BUTTON_PIN  PIN2

// button state macros
#define LOW 0
#define HIGH 1

//button direction
#define IN 0
#define OUT 1 

//initialize
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

//button rad
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);




#endif /* BUTTON_H_ */