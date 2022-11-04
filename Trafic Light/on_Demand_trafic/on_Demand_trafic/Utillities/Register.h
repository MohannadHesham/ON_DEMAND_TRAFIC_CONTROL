/*
 * Register.h
 *
 * Created: 10/11/2022 1:23:28 PM
 *  Author: HP
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#include "TypesDef.h"
/*DIO*/
//PORTA

#define PORTA *((volatile uint8_t*)0x3B) //8-bit register
#define DDRA  *((volatile uint8_t*)0x3A) //8-bit register
#define PINA  *((volatile uint8_t*)0x39) //8-bit register

//PORTB

#define PORTB *((volatile uint8_t*)0x38) //8-bit register
#define DDRB  *((volatile uint8_t*)0x37) //8-bit register
#define PINB  *((volatile uint8_t*)0x36) //8-bit register

//PORTC

#define PORTC *((volatile uint8_t*)0x35) //8-bit register
#define DDRC  *((volatile uint8_t*)0x34) //8-bit register
#define PINC  *((volatile uint8_t*)0x33) //8-bit register

//PORTD

#define PORTD *((volatile uint8_t*)0x32) //8-bit register
#define DDRD  *((volatile uint8_t*)0x31) //8-bit register
#define PIND  *((volatile uint8_t*)0x30) //8-bit register

/*Timer*/
// Timer0 Register

#define TCCR0  *((volatile uint8_t*)0x53) // 8-bit register
#define TCNT0  *((volatile uint8_t*)0x52) //8-bit register
#define TIFR   *((volatile uint8_t*)0x58)

/* Interrupts */
#define GICR *((volatile uint8_t*)0x5B)
#define MCUCR *((volatile uint8_t*)0x55)
#define SREG *((volatile uint8_t*)0x5F)

#endif /* REGISTER_H_ */