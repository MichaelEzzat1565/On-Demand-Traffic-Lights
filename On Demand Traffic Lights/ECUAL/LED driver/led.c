/*
 * led.c
 *
 * Created: 12/2/2022 12:14:53 PM
 *  Author: Say My Name
 */ 
// include led.h
#include "led.h"

// functions' definitions
//this function is to initialize the LED's pin as output
void LED_init(uint8_t ledPin, uint8_t ledPort)
{
	DIO_init(ledPin, ledPort, OUT);  // make the dio pin as output
}
//this function is to turn on the LED
void LED_on(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin, ledPort, HIGH);  // set the dio pin
}
//this function is to turn of the LED
void LED_off(uint8_t ledPin, uint8_t ledPort)
{
	DIO_write(ledPin, ledPort, LOW);  // clear the dio pin
}
//this function is to toggle the LED
void LED_toggle(uint8_t ledPin, uint8_t ledPort)
{
	DIO_toggle(ledPin, ledPort);  // toggle the dio pin
}


