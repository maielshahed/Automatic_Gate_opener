/*
 * grage.c
 *
 * Created: 7/22/2024 6:20:32 PM
 *  Author: RS3
 */ 

/*
 * Ultrasonic_sensor.c
 *
 * Created: 7/9/2024 12:36:03 AM
 *  Author: RS3
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Dio.h"
#include "seg_bcd.h"
#include "Std_macros.h"
#define  F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
	LCD_vinit();
	seven_seg_init('D');
	unsigned short a,b,high,distance;
	unsigned char count=9;
	DIO_vsetpindir('D',5,1);//output
	DIO_vsetpindir('D',7,1);
	
	
	
	while(1)
	{
		seven_seg_write('D',count);
		TCCR1A = 0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */
		DIO_vwrite('D',7,1);
		_delay_us(50);
		DIO_vwrite('D',7,0);
		
		TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		TCNT1=0;
		TCCR1B = 0;  		/* Stop the timer */
		high=b-a;
		distance=((high*34600)/(F_CPU*2)) ;
		//_delay_ms(3000);
		
		if (distance>=80)
		{
			SET_BIT(PORTD,5);
			_delay_ms(2);
			CLR_BIT(PORTD,5);
			//_delay_ms(1000);
			
			LCD_clearscreen();
			LCD_vsend_string("no object");
			_delay_ms(500);
			
		seven_seg_write('D',count);
			
			
			
		}
		else
		{
			
			
			SET_BIT(PORTD,5);
			_delay_ms(1);
			CLR_BIT(PORTD,5);
			//_delay_ms(2000);
			
			
			
			
			LCD_clearscreen();
			LCD_vsend_string("distance=");
			LCD_vsend_char((distance/10)+48);
			LCD_vsend_char((distance%10)+48);
			LCD_vsend_string("cm");
			_delay_ms(500);
			//_delay_ms(500);
				count --;
		
		seven_seg_write('D',count);
			
			
			
		}
	}
}

