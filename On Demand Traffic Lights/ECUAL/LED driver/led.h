/*
 * led.h
 *
 * Created: 12/2/2022 12:15:04 PM
 *  Author: Say My Name
 */ 

#ifndef LED_H_
#define LED_H_
// include the used lower layer .h files
#include "../../MCAL/DIO driver/dio.h"
#include "../../MCAL/TIMER0 driver/timer0.h"

//define Cars LEDs pins and ports
#define LED_CarsGreen_PIN PIN0
#define LED_CarsGreen_PORT PORT_A
#define LED_CarsYellow_PIN PIN1
#define LED_CarsYellow_PORT PORT_A
#define LED_CarsRed_PIN PIN2
#define LED_CarsRed_PORT PORT_A
// define pedestrians LEDs pins and ports
#define LED_PedsGreen_PIN PIN0
#define LED_PedsGreen_PORT PORT_B 
#define LED_PedsYellow_PIN PIN1
#define LED_PedsYellow_PORT PORT_B
#define LED_PedsRed_PIN PIN2
#define LED_PedsRed_PORT PORT_B

// all driver functions' prototypes
void LED_init(uint8_t ledPin, uint8_t ledPort);
void LED_on(uint8_t ledPin, uint8_t ledPort);
void LED_off(uint8_t ledPin, uint8_t ledPort);
void LED_toggle(uint8_t ledPin, uint8_t ledPort);

#endif /* LED_H_ */