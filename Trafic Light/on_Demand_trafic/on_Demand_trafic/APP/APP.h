/*
 * APP.h
 *
 * Created: 10/11/2022 7:20:52 PM
 *  Author: HP
 */ 


#ifndef APP_H_
#define APP_H_

	#include "../ECUAL/LED/LED.h"
	#include "../ECUAL/BUTTON/Button.h"


	typedef enum EN_mode_t
	{
		NORMAL, PEDESTRIAN
	}EN_mode_t;

	void App_init(void);
	void App_start(void);
	void TurnLEDoff(void);



#endif /* APP_H_ */