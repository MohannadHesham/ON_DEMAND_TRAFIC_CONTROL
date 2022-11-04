/*
 * DIO.h
 *
 * Created: 10/11/2022 1:28:59 PM
 *  Author: HP
 */ 


#ifndef DIO_H_
#define DIO_H_



//Driver Macros
#include "../../Utillities/Register.h"
#include "../../Utillities/TypesDef.h"
#include "../INTERUPTS/INTERUPTS.h"
//Define port
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// define direction
#define IN 0
#define OUT 1

// define value
#define LOW 0
#define HIGH 1

//define PIN
typedef enum EN_pin_t
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} EN_pin_t;



void DIO_init(uint8_t pinNumber, uint8_t portNumber , uint8_t direction); // Initialize dio direction

void DIO_write(uint8_t pinNumber, uint8_t portNumber , uint8_t value);


void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);

void DIO_read(uint8_t pinNumber, uint8_t portNumber , uint8_t *value);




#endif /* DIO_H_ */