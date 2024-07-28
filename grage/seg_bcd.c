/*
 * seg_bcd.c
 *
 * Created: 5/12/2024 12:40:42 AM
 *  Author: RS3
 */ 

#include "Dio.h"
#include "Std_macros.h"
//port low init 0-3
void seven_seg_init(unsigned char portname)
{
	DIO_vsetpindir(portname,0,1);
	DIO_vsetpindir(portname,1,1);
	DIO_vsetpindir(portname,2,1);
	DIO_vsetpindir(portname,3,1);
}
 void seven_seg_write(unsigned char portname,unsigned char val)
 {

	 write_low_nibble(portname,val);
 }
