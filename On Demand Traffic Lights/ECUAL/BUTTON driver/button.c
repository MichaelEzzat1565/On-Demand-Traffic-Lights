/*
 * button.c
 *
 * Created: 12/2/2022 1:58:33 PM
 *  Author: Michael Ezzat Tanyous
 */ 
#include "button.h"
//this function is to intitialize the button as input device
EN_ButtonState_t BUTTON_init(uint8_t buttonPin, uint8_t buttonPort)
{
	if(DIO_init(buttonPin, buttonPort, IN))  // make the dio pin as input
	{
		return BUTTON_OK;
	}
	else
	{
		// error handling
		return ERROR;
	}
}
//this function is to read button state
EN_ButtonState_t BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t *value)
{
	if(DIO_read(buttonPin, buttonPort, value))  // read the state of the dio pin
	{
		return BUTTON_OK;
	}
	else
	{
		//error handling
		return ERROR;
	}
}