/*
 * dio.h
 *
 * Created: 12/1/2022 8:01:50 PM
 *  Author: Michael Ezzat Tanyous
 */ 


#ifndef DIO_H_
#define DIO_H_
// include register.h
#include "../../utilities/registers.h" 
// include manipulate_bit
#include "../../utilities//bit_manipulation.h"
// all internal driver typedefs
// all driver macros
// PORTs names
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// PINs names
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
// direction defines 
#define IN 0
#define OUT 1
// value defines 
#define LOW 0
#define HIGH 1
// enum to return DIO state
typedef enum EN_DIOState_t{
	FALSE, TRUE
	}EN_DIOState_t;
// all driver functions prototypes
EN_DIOState_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // initialize DIO direction
EN_DIOState_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); // write date to DIO
EN_DIOState_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber); // toggle dio
EN_DIOState_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value); // read dio



#endif /* DIO_H_ */