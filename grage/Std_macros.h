/*
 * max.h
 *
 * Created: 4/26/2024 3:14:04 PM
 *  Author: RS3
 */ 


#ifndef MAX_H_
#define MAX_H_
/*
#define  DDRA  *((volatile unsigned char *)(0X3A))
#define  PORTA  *((volatile unsigned char *)(0X3B))


#define  DDRB  *((volatile unsigned char *)(0X37))
#define  PORTB  *((volatile unsigned char *)(0X38))


#define  DDRD  *((volatile unsigned char *)(0X31))
#define  PORTD  *((volatile unsigned char *)(0X32))


#define  DDRC  *((volatile unsigned char *)(0X34))
#define  PORTC  *((volatile unsigned char *)(0X35))
*/


#define  REGISTOR_SIZE 5
#define  SET_BIT(reg,bit)   reg|=(1<<bit)
#define  CLR_BIT(reg,bit)   reg&=~(1<<bit)
#define  TOG_BIT(reg,bit)   reg^=(1<<bit)
#define  READ_BIT(reg,bit)   ((reg&(1u<<bit))>>bit)
#define  IS_BIT_SET(reg,bit)   (reg&(1<<bit))>>bit
#define  IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define  ROR(reg,num)  reg=(reg<<(READ_BIT-num))|(reg>>(num))
#define  ROL(reg,num)  reg=(reg>>(READ_BIT-num))|(reg<<(num))



#endif /* MAX_H_ */