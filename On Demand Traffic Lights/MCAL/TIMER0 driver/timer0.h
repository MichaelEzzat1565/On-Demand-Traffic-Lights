/*
 * timer0.h
 *
 * Created: 12/4/2022 2:41:00 PM
 *  Author: Michael Ezzat Tanyous
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

// all driver macros
// 1.modes
#define  Normal_Mode 0x00
#define PWM_Phase_Correct 0x01
#define CTC 0x02
#define Fast_PWM 0x03
// 2.prescaler
#define No_prescaler 1
#define CLK_8 8
#define CLK_64 64
#define  CLK_256 265
#define CLK_1024 1024
#define External_Falling_Edge 0x06
#define External_Rising_Edge 0x07
// inclding register.h
#include "../../utilities/registers.h"
// include manipulate_bit.h
#include "../../utilities//bit_manipulation.h"
//including types.h
#include "../../utilities/types.h"

// functions prototypes
void Timer0_init(uint32_t timer_mode);
void Timer0_start(uint32_t Prescaler);
void Timer0_stop(void);
void Timer0_Delay_NormalMode(uint32_t Dellay_ms , uint32_t Prescaler);


#endif /* TIMER0_H_ */