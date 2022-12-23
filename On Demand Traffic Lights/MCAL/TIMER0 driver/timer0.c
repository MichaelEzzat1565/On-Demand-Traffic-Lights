/*
 * timer0.c
 *
 * Created: 12/4/2022 2:40:42 PM
 *  Author: Michael Ezzat Tanyous
 */ 
// including timer0.h
#include <math.h>
#include "timer0.h"

// driver defines
#define CPU_Frequency (pow(10, 3)) 


// function implementation
//tihs function to select timer's mode
void Timer0_init(uint32_t timer_mode)
{
	// choose timer mode
	TCCR0 = timer_mode; // Normal mode
}
//this function start the timer by setting it's prescaler
void Timer0_start(uint32_t Prescaler)
{
	// Timer statr -> set the Prescaler(setting the clock source)
	switch(Prescaler)
	{
		case No_prescaler:  // no prescaler
		   SET_BIT(TCCR0, 0); 
		   break;
		case CLK_8:   // prescaler is 8
		   SET_BIT(TCCR0, 1); 
		   break;
		case CLK_64:  // prescaler is 64
		  SET_BIT(TCCR0, 0);
		  SET_BIT(TCCR0, 1);
		  break;
		case CLK_256:      // prescaler is 256
		  SET_BIT(TCCR0, 2);
		  break;
		case CLK_1024:     // prescaler is 1024
	   	  SET_BIT(TCCR0, 0);
		  SET_BIT(TCCR0, 2);
		  break;
		case External_Falling_Edge:   // counting at falling edge
		  SET_BIT(TCCR0, 1);
		  SET_BIT(TCCR0, 2);
		  break;
		case External_Rising_Edge:   // counting at rising edge
		  SET_BIT(TCCR0, 0);
		  SET_BIT(TCCR0, 1);
		  SET_BIT(TCCR0, 2);
		  break;
	}
	
}

//this function stop the timer
void Timer0_stop(void)
{
	TCCR0 = 0x00;  // make all bits in the register to 0
}

//this function makes timer starting to count a dellay time
void Timer0_Delay_NormalMode(uint32_t Dellay_ms , uint32_t Prescaler)
{
	   double timer_initial_value = 0;  // timer initial value
	   uint16_t Number_Of_Overflows = 0;    // number of overflows
	   uint32_t Overflow_Counter = 0;   // to count the number of overflows have been done
	   double tick_time;    // the time of one tick
	   double time_max_delay;   // timer maximum delay
	   tick_time = (double)Prescaler/ (double)CPU_Frequency;  // calculate the tick time
	   time_max_delay = tick_time * 256.0;   // calculate the maximum delay
	   if(Dellay_ms < time_max_delay)  // if the delay req. is less than the max. dealy
	   {
		   Number_Of_Overflows = 1;  // we only need one overflow
		   timer_initial_value = ((time_max_delay - (double)Dellay_ms)/tick_time);   // calculate the initial value that the timer should start from
	   }
	   if(Dellay_ms == time_max_delay)   // if the delay req. is equal to the max. delay
	   {
		   Number_Of_Overflows = 1;   //we only need one overflow
		   timer_initial_value = 0;   // the timer will start from 0 because the delay is equal to the max. delay time
	   }
	   if(Dellay_ms > time_max_delay)   // if the delay req. is more than the max. delay
	   {
		   Number_Of_Overflows = ceil((double)Dellay_ms/time_max_delay);   // calculate number of needed overflows
		   timer_initial_value = 256.0 - (((double)Dellay_ms/tick_time)/(double)Number_Of_Overflows);   // calculate the initial value to start from
	   }
	   TCNT0 = timer_initial_value;   // set the register to the initial value
	   while(Overflow_Counter < Number_Of_Overflows)   // start counting the overflow
	   {
		   // wait until the overflow flag to be set
		   while((TIFR0 & (1<<0)) != 1); // busy wait ( until overflow flag bit to be 1)
		   // clear the overflow flag (by writing logic 1 to the flag)
		   SET_BIT(TIFR0,0);
		   Overflow_Counter++;  // increment overflow counter
	   }
	   Overflow_Counter = 0; // after counting we reset the counter to zero
	   
}