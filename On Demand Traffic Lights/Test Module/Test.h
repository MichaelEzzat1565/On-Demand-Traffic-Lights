/*
 * Test.h
 *
 * Created: 12/19/2022 12:22:11 PM
 *  Author: Say My Name
 */ 


#ifndef TEST_H_
#define TEST_H_
#include "../ECUAL/BUTTON driver/button.h"
#include "../ECUAL/LED driver/led.h"
#include "../MCAL/DIO driver/dio.h"
#include "../MCAL/TIMER0 driver/timer0.h"

void testButton(void);
void testLED(void);
void testDIO(void);
void testTimer0(void);
void test(void);


#endif /* TEST_H_ */