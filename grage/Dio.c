/*
 * CFile1.c
 *
 * Created: 4/30/2024 3:17:20 PM
 *  Author: RS3
 */ 

#include <avr/io.h>

#include "Std_macros.h"

void DIO_vsetpindir(unsigned char port,unsigned char pin,unsigned char direction){
	
	
	switch(port){
		
		case 'A':
		case 'a':
		if (direction==1)
		{
			SET_BIT(DDRA,pin);//Set the direction of the given pin in port A as output
			//DDRA |=(1<<pin);

		} 
		else
		{
			CLR_BIT(DDRA,pin);//CLEAR the direction of the given pin in port A as input

		}
		break;
		
		case 'B':
		case 'b':
		if (direction==1)
		{
			SET_BIT(DDRB,pin);//Set the direction of the given pin in port B as output

		}
		else
		{
			CLR_BIT(DDRB,pin);//CLEAR the direction of the given pin in port B as input

		}
		break;
		
		case 'D':
		case 'd':
		if (direction==1)
		{
			SET_BIT(DDRD,pin);//Set the direction of the given pin in port D as output

		}
		else
		{
			CLR_BIT(DDRD,pin);//CLEAR the direction of the given pin in port D as input

		}
		break;
		
		case 'C':
		case 'c':
		if (direction==1)
		{
			SET_BIT(DDRC,pin);//Set the direction of the given pin in port C as output

		}
		else
		{
			CLR_BIT(DDRC,pin);//CLEAR the direction of the given pin in port C as input

		}
		break;
		default:break;
		
		
}
}
//port direction==output
void DIO_vwrite(unsigned char port,unsigned char pin,unsigned char val){
	
	
	switch(port){
		
		case 'A':
		case 'a':
		if (val==1)
		{
			SET_BIT(PORTA,pin);//Set the value of the given pin in port A as High

			//PORTA |=(1<<pin);

		}
		else
		{
			CLR_BIT(PORTA,pin);//Set the value of the given pin in port A as LOW


		}
		break;
		
		case 'B':
		case 'b':
		if (val==1)
		{
			SET_BIT(PORTB,pin);//Set the value of the given pin in port B as High
		}
		else
		{
			CLR_BIT(PORTB,pin);//Set the value of the given pin in port B as LOW


		}
		break;
		
		case 'D':
		case 'd':
		if (val==1)
		{
			SET_BIT(PORTD,pin);//Set the value of the given pin in port D as High


		}
		else
		{
			CLR_BIT(PORTD,pin);//Set the value of the given pin in port D as LOW
		}
		break;
		
		case 'C':
		case 'c':
		if (val==1)
		{
			SET_BIT(PORTC,pin);//Set the value of the given pin in port C as High
		}
		else
		{
			CLR_BIT(PORTC,pin);//Set the value of the given pin in port C as LOW


		}
		break;
		default:break;
		
		
	}
}

void DIO_vtogglepin(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin);//Toggle the value of the given pin in port A
		break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin);//Toggle the value of the given pin in port B
		break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin);//Toggle the value of the given pin in port D
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin);//Toggle the value of the given pin in port C
		break;
		default:break;
	}
}
unsigned char DIO_uread(unsigned char port ,unsigned char pin){
	unsigned char return_value;
	switch(port){
		
		case 'A':
		case 'a':
		return_value=READ_BIT(PINA,pin);//Read the value from the given pin in port A
		break;


	case 'B':
	case 'b':
	return_value=READ_BIT(PINB,pin);//Read the value from the given pin in port B
	break;
		
			case 'C':
			case 'c':
			return_value=READ_BIT(PINC,pin);//Read the value from the given pin in port C
			break;
			
				case 'D':
				case 'd':
				return_value=READ_BIT(PIND,pin);//Read the value from the given pin in port D
				break;
		default:break;
		
	}
	return return_value;
}



//direction port


void DIO_vsetportdir(unsigned char port,unsigned char direction){
	
	switch(port){
		
		case 'A':
		case 'a':
		DDRA=direction;//set the direction of port A

		break;
		
		case 'B':
		case 'b':	
			DDRB=direction;

		break;
		
		case 'D':
		case 'd':
		DDRD=direction;
		
		
		break;
		
		case 'C':
		case 'c':
		DDRC=direction;
		
		break;
		default:break;	
	}
}



void DIO_vWRITEport(unsigned char port,unsigned char val){
	
	switch(port){
		
		case 'A':
		case 'a':
		PORTA=val;//Write the given value to the port A

		break;
		
		case 'B':
		case 'b':
		PORTB=val;//Write the given value to the port B
	

		break;
		
		case 'D':
		case 'd':
		PORTD=val;//Write the given value to the port D
		
		break;
		
		case 'C':
		case 'c':
		PORTC=val;//Write the given value to the port C
		
		break;
		default:break;

	}
	}
	
	
	unsigned char DIO_ureadport(unsigned char port){
		unsigned char return_val;
		switch(port){
			
			case 'A':
			case 'a':
			return_val=PINA;//read the value to the port A

			break;
			
			case 'B':
			case 'b':
			PORTB=PINB;//READ value to the port B
			

			break;
			
			case 'D':
			case 'd':
			PORTD=PIND;//READ  value to the port D
			
			break;
			
			case 'C':
			case 'c':
			PORTC=PINC;//READ  value to the port C
			
			break;
			default:break;
		}			
			return return_val;

		}
		
		
void DIO_vtoggleport(unsigned char port){
			
			switch(port){
				
				case 'A':
				case 'a':
				PORTA=~PORTA;    // or PORTA=PORTA^0xff
				break;
				
				case 'B':
				case 'b':
				PORTB=~PORTB;//Write the given value to the port B
				

				break;
				
				case 'D':
				case 'd':
				PORTD=~PORTD;
				
				break;
				
				case 'C':
				case 'c':
				PORTC=~PORTC;
				
				break;
				
				
				default:
				break;
			}	
}		


			
/*by using internal pull up  
DIO_vwrite(unsigned char port,unsigned char pin,unsigned char val);

or

 */
void DIO_vconnectpullup(char portname ,char pinnumber, char connect_pullup)
{
	switch(portname)
	{
		case 'A':
		if(connect_pullup==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		if(connect_pullup==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
	case 'C':
	if(connect_pullup==1)
	{
		SET_BIT(PORTC,pinnumber);
		
	}
	else
	{
		CLR_BIT(PORTC,pinnumber);
	}
	break;
	case 'D':
	if(connect_pullup==1)
	{
		SET_BIT(PORTD,pinnumber);
		
	}
	else
	{
		CLR_BIT(PORTD,pinnumber);
	}
	break;
	
}
}

/*Another code

void write_low_nibble(unsigned char portname,unsigned char val)
{
	DIO_vwrite(portname,0,READ_BIT(val,0));
	DIO_vwrite(portname,1,READ_BIT(val,1));
	DIO_vwrite(portname,2,READ_BIT(val,2));
	DIO_vwrite(portname,3,READ_BIT(val,3));
}	*/
/*
void write_low_nibble(unsigned char portname,unsigned char val)
{
	DIO_vwrite(portname,4,READ_BIT(val,0));
	DIO_vwrite(portname,5,READ_BIT(val,1));
	DIO_vwrite(portname,6,READ_BIT(val,2));
	DIO_vwrite(portname,7,READ_BIT(val,3));
}	*/

	void write_low_nibble(unsigned char portname,unsigned char val)
	{
		val&=0x0f;//0b11110000
		switch(portname)
		{
			case 'A':
			case 'a':
			PORTA&=0xf0;
			PORTA|=val;
			break;
			case 'B':
			case 'b':
			PORTB&=0xf0;
			PORTB|=val;
			break;
case 'C':
case 'c':
PORTC&=0xf0;
PORTC|=val;
break;
case 'D':
case 'd':
PORTD&=0xf0;
PORTD|=val;
break;
}
}

void write_high_nibble(unsigned char portname,unsigned char val)
{
	val<<=4;
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA&=0x0f;
		PORTA|=val;
		break;
		case 'B':
		case 'b':
		PORTB&=0x0f;
		PORTB|=val;
		break;
		case 'C':
		case 'c':
		PORTC&=0x0f;
		PORTC|=val;
		break;
		case 'D':
		case 'd':
		PORTD&=0x0f;
		PORTD|=val;
		break;
	}
}

