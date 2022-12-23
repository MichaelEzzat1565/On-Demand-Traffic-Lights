/*
 * dio.c
 *
 * Created: 12/1/2022 8:01:13 PM
 *  Author: Michael Ezzat Tanyous
 */ 

// include dio.h
#include "dio.h"
// functions' definitions
// initialize the digital input/output pin
EN_DIOState_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A :
		  if (direction == IN)
		  {
			  CLR_BIT(DDRA, pinNumber); // input
			  return TRUE;
		  }
		  else if (direction == OUT)
		  {
			    SET_BIT(DDRA, pinNumber); // output
				return TRUE;
		  }
		  else
		  {
			  // error handling
			  return FALSE;
		  }		
		case PORT_B :
		  if (direction == IN)
		  {
			 CLR_BIT(DDRB, pinNumber); // input
			 return TRUE;
		  }
		  else if (direction == OUT)
		  {
			  SET_BIT(DDRB, pinNumber); // output
			  return TRUE;
		  }
		  else
		  {
			  // error handling
			  return FALSE;
		  }
		case PORT_C :
		  if (direction == IN)
		  {
			  CLR_BIT(DDRC, pinNumber);  // input
			  return TRUE;
		  }
		  else if (direction == OUT)
		  {
			   SET_BIT(DDRC, pinNumber); // output
			   return TRUE;
		  }
		  else
		  {
			  // error handling
			  return FALSE;
		  }
		case PORT_D :
		 if (direction == IN)
		 {
			CLR_BIT(DDRD, pinNumber); // input
			return TRUE;
		 }
		 else if (direction == OUT)
		 {
			 SET_BIT(DDRD, pinNumber); // output
			 return TRUE;
		 }
		 else
		 {
			 // error handling
			 return FALSE;
		 }
	}
	return FALSE;
}
//this function is writing low or high in the dio pin
EN_DIOState_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A :
		if (value == LOW )
		{
			CLR_BIT(PORTA, pinNumber); // 0
			return TRUE;
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTA, pinNumber); // 1
			return TRUE;
		}
		else
		{
			// error handling
			return FALSE;
		}
		case PORT_B :
		if (value == LOW)
		{
			CLR_BIT(PORTB, pinNumber); // 0
			return TRUE;
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTB, pinNumber); // 1
			return TRUE;
		}
		else
		{
			// error handling
			return FALSE;
		}
		case PORT_C :
		if (value == LOW)
		{
			CLR_BIT(PORTC, pinNumber); // 0
			return TRUE;
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTC, pinNumber); // 1
			return TRUE;
		}
		else
		{
			// error handling
			return FALSE;
		}
		case PORT_D :
		if (value == LOW)
		{
			CLR_BIT(PORTD, pinNumber); // 0
			return TRUE;
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTD, pinNumber); // 1
			return TRUE;
		}
		else
		{
			// error handling
			return FALSE;
		}
	}
	return FALSE;
}
//this function toggle the dio pin
EN_DIOState_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch (portNumber)
	{
		case PORT_A:
		  Toggle_BIT(PORTA, pinNumber); // if 0 wil be 1 , if 1 will be 0
		  return TRUE;
		  case PORT_B:
		  Toggle_BIT(PORTB, pinNumber);
		  return TRUE;
		  case PORT_C:
		  Toggle_BIT(PORTC, pinNumber);
		  return TRUE;
		  case PORT_D:
		  Toggle_BIT(PORTD, pinNumber);
		  return TRUE;
		  default:
		  return FALSE;
	}
}

//this function read the state of the dio pin
EN_DIOState_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value)
{
	switch (portNumber)
	{
		case PORT_A:
		  *value= READ_BIT(PINA, pinNumber); // READ_BIT(REG, BIT_NO) ((REG & (1<<BIT_NO))>>BIT_NO)
		  return TRUE;
		case PORT_B:
		  *value = READ_BIT(PINB, pinNumber);
		  return TRUE;
	    case PORT_C:
		  *value= READ_BIT(PINC, pinNumber);
		  return TRUE;
	    case PORT_D:
		  *value = READ_BIT(PIND, pinNumber);
		  return TRUE;
		default:
		return FALSE;
	}
}