/*
 * main.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Administrator
 */

#include "MemoryMap.h"
#include "Utils.h"
#define F_CPU	8000000UL
#include "util/delay.h"

int main()

{

	DDRA = 0xff;
	CLEAR_BIT(DDRB, 0);
	SET_BIT(PORTB, 0);

	unsigned char i;

	while(1){




		while(READ_BIT(PINB, 0) == 0)
		{
			SET_BIT(PORTA, i);
			i++;
			_delay_ms(1000);

			if(PORTA == 0xff)
			{
				PORTA = 0x0;
				i = 0;
			}
		}


	}

}
