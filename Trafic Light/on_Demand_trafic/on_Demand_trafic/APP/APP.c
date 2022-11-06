/*
 * APP.c
 *
 * Created: 10/11/2022 7:20:38 PM
 *  Author: HP
 */ 


#include "APP.h"
volatile uint8_t flag_R = 0;
volatile uint8_t flag_G = 0;
volatile uint8_t flag_Y = 0;


void App_init(void)
{
	//cars led
		LED_init(LED_RED_PORT, LED_RED_PIN);
		LED_init(LED_YELLOW_PORT, LED_YELLOW_PIN);
		LED_init(LED_GREEN_PORT, LED_GREEN_PIN);
		
	//pedestrian led
			LED_init(LED_P_RED_PORT, LED_P_RED_PIN);
			LED_init(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_init(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
			
	//button init
			BUTTON_init(BUTTON_PORT,BUTTON_PIN);
			
			interupts_init();
			Timer0_init_normal();
			
}
EN_mode_t mode = NORMAL;

void App_start(void)
{
	while(1)
	{
		
		
		if(mode == NORMAL)
		{
		/*
				This is the normal mode in on demand traffic light control system, and there are the steps to implement this mode
				1. Turn on cars' Green LED and blink the pedestrians' Yellow LED
				2. turn off all LEDs, to prevent the errors if it return from the pedestrian's mode
				3. turn on cars' Red LED and the pedestrian's Green LED
				4. blink cars' Yellow LED and turn on the pedestrians' Red LED
			
			*/
			
			//Turn off all leds
			TurnLEDoff();
			//switch car led to red and pedestrian to green
			LED_on(LED_GREEN_PORT,LED_GREEN_PIN);
			LED_on(LED_P_RED_PORT,LED_P_RED_PIN);
			delay_5s();
			TurnLEDoff();
			flag_G = 1;
			
			toggle_2_LEDs_5s(LED_YELLOW_PORT, LED_YELLOW_PIN,LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			flag_Y = 1;
			LED_off(LED_YELLOW_PORT, LED_YELLOW_PIN);
			LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_on(LED_RED_PORT,LED_RED_PIN);
			flag_R = 1;
			LED_on(LED_P_GREEN_PORT,LED_P_GREEN_PIN);
			delay_5s();
			LED_off(LED_RED_PORT,LED_RED_PIN);
			LED_off(LED_P_GREEN_PORT,LED_P_GREEN_PIN);
			toggle_2_LEDs_5s(LED_YELLOW_PORT, LED_YELLOW_PIN,LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			
	
			
			
			
	}// end if
	
		
		} //end of while 1
}  
			
ISR(EXT_INT_0)
		{
			
			
		
			if(flag_R == 1)
			{
				/*
				If a pedestrian press the button when the red LED is on 
				1. Will turn off all leds
				2. Red led for the cars and the green led for the peds will be on for 5 sec the peds pass the road 
				3. turn off both leds and the yelllow LED will blink for 5 sec
				4. turn off all leds and continue to normal mode */
							
				TurnLEDoff();
				LED_on(LED_RED_PORT,LED_RED_PIN);
				LED_on(LED_P_GREEN_PORT,LED_P_GREEN_PIN);
				delay_5s();
				LED_off(LED_RED_PORT,LED_RED_PIN);
				LED_off(LED_P_GREEN_PORT,LED_P_GREEN_PIN);
				toggle_2_LEDs_5s(LED_YELLOW_PORT, LED_YELLOW_PIN,LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
				LED_off(LED_YELLOW_PORT, LED_YELLOW_PIN);
				LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
							
			}//end if color
	
	

		/*
					this case if a pedstrian press the button when the yellow or the green LED for the car is on
					1.Turn off all leds
					2.Turn on the red pedstrian LED
					3.Turn off the red led and blink the yellow LED for 5 sec
					4.Turn on the car red led and the peds green LED on for five seconds to let the peds to pass
					5.blink the yellow for 5 sec then go back to normal mode
					*/
					
	
			 if (flag_G == 1 || flag_Y == 1 )
				{
					
	
					TurnLEDoff();
									
					LED_on(LED_P_RED_PORT,LED_P_RED_PIN);
				 	LED_on(LED_GREEN_PORT,LED_GREEN_PIN);
					delay_5s();
					LED_off(LED_P_RED_PORT,LED_P_RED_PIN);
				 	LED_off(LED_GREEN_PORT,LED_GREEN_PIN);
					toggle_2_LEDs_5s(LED_YELLOW_PORT, LED_YELLOW_PIN,LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
					LED_off(LED_YELLOW_PORT, LED_YELLOW_PIN);
					LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
					
					LED_on(LED_RED_PORT,LED_RED_PIN);
					LED_on(LED_P_GREEN_PORT,LED_P_GREEN_PIN);
					delay_5s();
					LED_off(LED_RED_PORT,LED_RED_PIN);
					LED_off(LED_P_GREEN_PORT,LED_P_GREEN_PIN);
					toggle_2_LEDs_5s(LED_YELLOW_PORT, LED_YELLOW_PIN,LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
					
					TurnLEDoff();
					//go to normal mode
				}
						
		}//end ISR




	/*function to turn off all leds*/


void TurnLEDoff(void)
{
	LED_off(LED_RED_PORT, LED_RED_PIN);
	LED_off(LED_YELLOW_PORT, LED_YELLOW_PIN);
	LED_off(LED_GREEN_PORT, LED_GREEN_PIN);
	// turn off all pedestrian's LEDs
	LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
	LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
	LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
	
	 /*flag_R = 0;
	 flag_G = 0;
	 flag_Y = 0;*/
	
}


