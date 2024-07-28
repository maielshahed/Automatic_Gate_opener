/*
 * LCD.c
 *
 * Created: 6/10/2024 7:02:07 PM
 *  Author: RS3
 */ 
#include <avr/io.h>
#include "LCD.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_vinit(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	//pin output
	DIO_vsetpindir('A',0,1);
	DIO_vsetpindir('A',1,1);
	DIO_vsetpindir('A',2,1);
	DIO_vsetpindir('A',3,1);
	DIO_vsetpindir('A',4,1);
	DIO_vsetpindir('A',5,1);
	DIO_vsetpindir('A',6,1);
	DIO_vsetpindir('A',7,1);
	DIO_vsetpindir('B',EN,1);
	DIO_vsetpindir('B',RW,1);
	DIO_vsetpindir('B',RS,1);
	
	DIO_vwrite('B',RW,0);  //w  portB |(1<<RW)
	LCD_vsend_cmd(EIGHT_BITS); //8 bit mode   =0X38 CMMOEND
	_delay_ms(1);
	LCD_vsend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_vsend_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_vsend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);

	#elif defined four_bits_mode
		DIO_vsetpindir('A',4,1);
		DIO_vsetpindir('A',5,1);
		DIO_vsetpindir('A',6,1);
		DIO_vsetpindir('A',7,1);
		DIO_vsetpindir('B',EN,1);
		DIO_vsetpindir('B',RW,1);
		DIO_vsetpindir('B',RS,1);

DIO_vwrite('B',RW,0);
 LCD_vsend_cmd(RETURN_HOME); //return home
 _delay_ms(10);
 LCD_vsend_cmd(FOUR_BITS); //4bit mode 0X28
 _delay_ms(1);
 LCD_vsend_cmd(CURSOR_ON_DISPLAN_ON);//display on cursor on
 _delay_ms(1);
 LCD_vsend_cmd(CLR_SCREEN);//clear the screen
 _delay_ms(10);
 LCD_vsend_cmd(ENTRY_MODE); //entry mode
 _delay_ms(1);
 #endif
}



static void send_falling_edge(void)
{
	DIO_vwrite('B',EN,1);//V=5
	_delay_ms(2);
	DIO_vwrite('B',EN,0); //V=0
	_delay_ms(2);
}


void LCD_vsend_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_vWRITEport('A',cmd);
	DIO_vwrite('B',RS,0);//commend reg
	send_falling_edge();

	#elif defined four_bits_mode
	write_high_nibble('A',cmd>>4);
	DIO_vwrite('B',RS,0);
	send_falling_edge();
	
	write_high_nibble('A',cmd);
	DIO_vwrite('B',RS,0);
	send_falling_edge();
	_delay_ms(1);
	#endif
}


void LCD_vsend_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port('A',data);
	DIO_write('B',RS,1);// data reg
	send_falling_edge();

	#elif defined four_bits_mode
	write_high_nibble('A',data>>4);
	DIO_vwrite('B',RS,1);
	send_falling_edge();
	
	write_high_nibble('A',data);
	DIO_vwrite('B',RS,1);
	send_falling_edge();
	
	_delay_ms(1);
	#endif
}

void LCD_vsend_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_vsend_char(*data);
		data++;
	}
}


void LCD_clearscreen()
{
	LCD_vsend_cmd(CLR_SCREEN);//0x01
	_delay_ms(10);
}

void LCD_movecursor(char row,char coloumn)
{
	char data ;
	if(row >    2 || row     <  1  || coloumn > 16 || coloumn<1)
	{
		data=0x80;
	}
	
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	
	LCD_vsend_cmd(data);
	_delay_ms(1);
}


