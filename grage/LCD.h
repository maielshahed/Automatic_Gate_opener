/*
 * LCD.h
 *
 * Created: 6/10/2024 7:00:22 PM
 *  Author: RS3
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "LCD_config.h"

//Send that as a command to the LCD 
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#if defined four_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28

#elif defined eight_bits_mode
//NUM PIN TO PORT
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38

#endif






void LCD_vinit(void);

static void send_falling_edge(void);
void LCD_vsend_cmd(char cmd);
void LCD_vsend_char(char data);
void LCD_vsend_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);



#endif /* LCD_H_ */