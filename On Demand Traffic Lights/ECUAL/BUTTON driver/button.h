/*
 * button.h
 *
 * Created: 12/2/2022 1:58:49 PM
 *  Author: Michael Ezzat Tanyous
 */ 

// including the used lower layer .h files
#include "../../MCAL/DIO driver/dio.h"
#include "../../MCAL/Interrupt library/Interrupts.h"
// driver's defines
#ifndef BUTTON_H_
#define BUTTON_H_
// enum to return button state
typedef enum EN_ButtonState_t
{
	ERROR, BUTTON_OK
}EN_ButtonState_t;
//driver defines
#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2
// All driver's functions prototypes
EN_ButtonState_t BUTTON_init(uint8_t buttonPin, uint8_t buttonPort);
EN_ButtonState_t BUTTON_read(uint8_t buttonPin, uint8_t buttonPort, uint8_t* value);



#endif /* BUTTON_H_ */