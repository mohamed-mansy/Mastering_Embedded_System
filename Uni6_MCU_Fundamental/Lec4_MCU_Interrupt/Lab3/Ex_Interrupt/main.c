/*
 * main.c
 *
 *
 *      Author: Mohamed_Ayman
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define Set_BIT(Reg, bit) Reg |= (1 << bit)

#define Clear_BIT(Reg, bit) Reg &= ~(1 << bit)

#define Toggle_BIT(Reg, bit) Reg ^= (1 << bit)

#define Read_BIT(Reg, bit) ((Reg & (1 << bit)) >> bit)

int main()
{
	//make portD pins 5, 6, and 7 are output
	Set_BIT(DDRD , 5);
	Set_BIT(DDRD , 6);
	Set_BIT(DDRD , 7);

	//make portD pins 2, and 3 are input and make PortB pin 2 is input
	Clear_BIT(DDRD, 2);
	Clear_BIT(DDRD, 3);
	Clear_BIT(DDRB, 2);

	//Any logical change on INT0 generates an interrupt request
	Set_BIT(MCUCR, 0);
	Clear_BIT(MCUCR , 1);

	//The rising edge of INT1 generates an interrupt request.
	Set_BIT(MCUCR, 2);
	Set_BIT(MCUCR, 3);

	//if ISC2 is written to zero, a falling edge on INT2 activates the interrupt
	Clear_BIT(MCUCSR, 6);

	//Bit 6 – INT0: External Interrupt Request 0 Enable
	Set_BIT(GICR , 6);
	//Bit 7 – INT1: External Interrupt Request 0 Enable
	Set_BIT(GICR , 7);
	//Bit 5 – INT2: External Interrupt Request 0 Enable
	Set_BIT(GICR , 5);

	//The global interrupt enable bit must be set for interrupts to be enabled
	Set_BIT(SREG , 7);

	while(1)
	{
		Clear_BIT(PORTD, 5);
		Clear_BIT(PORTD, 6);
		Clear_BIT(PORTD, 7);
	}

}

ISR(INT0_vect)
{
	Set_BIT(PORTD, 5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	Set_BIT(PORTD, 6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	Set_BIT(PORTD, 7);
	_delay_ms(1000);
}
