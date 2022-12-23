/*
 * app.h
 *
 * Created: 12/2/2022 12:54:59 PM
 *  Author: Michael Ezzat Tanyous
 */ 


#ifndef APP_H_
#define APP_H_
#include "../ECUAL/LED driver/led.h"
#include "../ECUAL/BUTTON driver/button.h"

typedef enum EN_Mode_t 
{
   NORMAL, PEDESTERIAN
}EN_Mode_t;

typedef enum EN_CarsLEDsState_t
{
	 GREEN_OFF , GREEN_ON
}EN_CarsLEDsState_t; 


void APP_init(void);
void APP_start(void);
void LED_5SEC_BLINK(uint8_t ledPin ,uint8_t ledPort, EN_Mode_t* Mode_State);
void yellowLEDsblink(void);
void readCarsLEDsState(EN_CarsLEDsState_t* Cars_Green_LED);

#endif /* APP_H_ */