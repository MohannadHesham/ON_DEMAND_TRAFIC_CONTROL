/*
 * INTERUPTS.h
 *
 * Created: 10/17/2022 7:32:08 PM
 *  Author: HP
 */ 


#ifndef INTERUPTS_H_
#define INTERUPTS_H_
#include "../DIO/dio.h"
// External interrupt request 0
#define EXT_INT_0 __vector_1
// External interrupt request 1
#define EXT_INT_1 __vector_2
// External interrupt request 2
#define EXT_INT_2 __vector_3

#define  sei() __asm__ __volatile__ ("sei" ::: "memory")

#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR definition

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

void interupts_init();

#endif /* INTERUPTS_H_ */