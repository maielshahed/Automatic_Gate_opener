/*
 * timer.c
 *
 * Created: 9/25/2019 7:22:07 PM
 *  Author: Mohamed Zaghlol
 */ 
 
#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=80;
	/* select timer clock */	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}


void timer_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer1_wave_fastPWM(double value)
{
	/* set OC1A as output pin */
	SET_BIT(DDRD,5);
	/* select fast PWM mode*/
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/* load a value in OCR1A,ICR1 */
	OCR1A=value*1000;
	ICR1=19999;
	/* select timer clock, no prescaling */
	SET_BIT(TCCR1B,CS10);
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	SET_BIT(TCCR1A,COM1A1);
}

void timer1_servomotor(double speed)
{//f_cpu 8000000
	
		/* set OC1A as output pin */
		SET_BIT(DDRD,5);
	
	// Set Timer1 to Fast PWM mode, 16-bit
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);  // Prescaler 8

	// Set TOP value for 50Hz PWM (20ms period)
	ICR1 = 19999;  // (8MHz / 8 / 50Hz) - 1

	// Initialize OCR1A to neutral position (1ms pulse)
	OCR1A =speed*1000;  // 1.5ms / (1 / (8MHz / 8)) = 3000
}


void timer_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}
