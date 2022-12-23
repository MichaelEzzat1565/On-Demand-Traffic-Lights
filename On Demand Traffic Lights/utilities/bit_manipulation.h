/*
 * bit_manipulation.h
 *
 * Created: 12/2/2022 9:17:36 AM
 *  Author: Michael Ezzat Tanyous
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(REG, BIT_NO) REG |=(1<<BIT_NO)
#define CLR_BIT(REG, BIT_NO) REG &=~(1<<BIT_NO)
#define READ_BIT(REG, BIT_NO) ((REG & (1<<BIT_NO))>>BIT_NO)
#define Toggle_BIT(REG, BIT_NO) REG ^=(1<<BIT_NO)




#endif /* BIT_MANIPULATION_H_ */