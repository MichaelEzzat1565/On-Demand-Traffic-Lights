/*
 * Test.c
 *
 * Created: 12/19/2022 12:21:34 PM
 *  Author: Say My Name
 */ 

#include "Test.h"
//this function test project's drivers
void test(void)
{
	
	//testButton();
	//testLED();
	//testDIO();
	testTimer0();
	
}
// this function test button driver
void testButton(void)
{
	uint8_t value = 'a';   // to show the state of the button
	BUTTON_init(PIN0, PORT_D);  // test BUTTON_init() fun by any port and pin we need
	BUTTON_read(PIN0, PORT_D, &value);  // tesst BUTTON_read() fun. by any port and pin we need
}
// this function is to test LED driver
void testLED(void)
{
	LED_init(PIN1, PORT_C);  // to test LED_init() function by any port and pin we need
	LED_on(PIN1, PORT_C);    // to test LED_on() function by any port and pin we need
	LED_off(PIN1, PORT_C);   // to test LED_of() function by any port and pin we need
	LED_toggle(PIN1, PORT_C);   //// to test LED_toggle() function by any port and pin we need
}
// this function is to test DIO driver
void testDIO(void)
{
	uint8_t value = 'a';  //to the state of the DIO
	DIO_init(PIN2, PORT_A, OUT); // to test DIO_init() function as ouptu by any port and pin we need
	DIO_init(PIN2, PORT_A, IN);   // to test DIO_init() function as input by any port and pin we need
	DIO_write(PIN2, PORT_A, HIGH);  // to test DIO_write() function as high by any port and pin we need
	DIO_write(PIN2, PORT_A, LOW);    // to test DIO_write() function as low by any port and pin we need
	DIO_toggle(PIN2, PORT_A);     // to test DIO_toggle() function by any port and pin we need
	DIO_read(PIN2, PORT_A, &value);   // to test DIO_read() function by any port and pin we need
}
// this function is to test Timer0 driver
void testTimer0(void)
{
	Timer0_init(Normal_Mode);   // to test Timer0_init() function with the used mode (normal mode)
	Timer0_start(CLK_1024);   // to test Timer0_start() function with any prescaler we need
	Timer0_Delay_NormalMode(500 , CLK_1024); // to test Timer0_Delay_NormalMode() funtion with any needed delay 
	Timer0_stop();  // to test Timer0_stopp() function
}