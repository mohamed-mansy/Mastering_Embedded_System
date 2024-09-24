/*
 * main.c
 *
 *
 *      Author: Mohamed_Ayman
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main()
{
	//make portD pin 5 is output
	DDRD |= (1 << 5);

	//make portD pin 2 is input
	DDRD &= ~(1 << 2);

	//Any logical change on INT0 generates an interrupt request
	MCUCR |= (1 << 0);
	MCUCR &= ~(1<<1);

	//Bit 6 – INT0: External Interrupt Request 0 Enable
	GICR |= (1 << 6);

	//The global interrupt enable bit must be set for interrupts to be enabled
	SREG |= (1 << 7);

	while(1);

}

ISR(INT0_vect)
{
	PORTD |= (1 << 5);
	_delay_ms(1000);

	PORTD &= ~(1 << 5);
	_delay_ms(1000);
}
