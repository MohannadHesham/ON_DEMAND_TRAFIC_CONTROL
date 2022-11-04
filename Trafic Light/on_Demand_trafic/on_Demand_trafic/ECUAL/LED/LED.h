/*
 * LED.h
 *
 * Created: 10/11/2022 1:34:34 PM
 *  Author: HP
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
/************************************************************************/
/*             Traffic light for cars                                   */
/************************************************************************/
// define led1 port and pin
#define LED_RED_PORT PORT_A
#define LED_RED_PIN PIN0
// define led2 port and pin
#define LED_YELLOW_PORT PORT_A
#define LED_YELLOW_PIN PIN1
// define led3 port and pin
#define LED_GREEN_PORT PORT_A
#define LED_GREEN_PIN PIN2



/************************************************************************/
/*             Traffic light for pedestrians                                   */
/************************************************************************/
// define led1 port and pin
#define LED_P_RED_PORT PORT_B
#define LED_P_RED_PIN PIN0
// define led2 port and pin
#define LED_P_YELLOW_PORT PORT_B
#define LED_P_YELLOW_PIN PIN1
// define led3 port and pin
#define LED_P_GREEN_PORT PORT_B
#define LED_P_GREEN_PIN PIN2

void LED_init(uint8_t ledPort ,uint8_t ledPin);
void LED_on(uint8_t ledPort ,uint8_t ledPin);
void LED_off(uint8_t ledPort ,uint8_t ledPin);
void LED_toggle(uint8_t ledPort ,uint8_t ledPin);
void toggle_LED_5s(uint8_t ledPort, uint8_t ledPin);
void toggle_2_LEDs_5s(uint8_t ledPort1, uint8_t ledPin1, uint8_t ledPort2, uint8_t ledPin2);



#endif /* LED_H_ */