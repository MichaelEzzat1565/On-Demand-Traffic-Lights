/*
 * Interrupts.h
 *
 * Created: 12/5/2022 6:28:36 PM
 *  Author: Michael Ezzat Tanyous
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/*External Interrupt Vector*/
/*External Interrupt Request 0*/
#define EXT_INT_0 __vector_1
/*External Interrupt Request 1*/
#define EXT_INT_1 __vector_2
/*External Interrupt Request 2*/
#define EXT_INT_2 __vector_3

/* Enable global interrupt -> setting bit 7 in the status register SREG to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
/* Disable global interrupt -> setting bit 7 in the status register SREG to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR deffinition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)




#endif /* INTERRUPTS_H_ */