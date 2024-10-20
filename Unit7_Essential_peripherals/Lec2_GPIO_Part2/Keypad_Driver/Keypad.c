/*
 * Keypad.c
 *
 *  Created on: Oct 10, 2024
 *      Author: Administrator
 */

#include "Keypad.h"

int Keypad_Row[] = {R0, R1, R2, R3};
int Keypad_Column[] = {C4, C5, C6, C7};

void Keypad_Init()
{
	//make all Rows input
	Keypad_Direction &= ~(1 << R0) | (1 << R1) | (1 << R2) | (1 << R3);

	//make all columns output
	Keypad_Direction |= (1 << C4) | (1 << C5) | (1 << C6) | (1 << C7);


	keypad_port = 0xff;
}

char KeypadPressed()
{
	int i, j;
	//i for column and j for row
	for(i = 0; i < 4; i++)
	{
		keypad_port |= (1 << Keypad_Column[0]) | (1 << Keypad_Column[1]) | (1 << Keypad_Column[2]) | (1 << Keypad_Column[3]);


		keypad_port &= ~(1 << Keypad_Column[i]);

		for(j = 0; j < 4; j++)
		{
			if(!(Keypad_Pin & (1 << Keypad_Row[j]))) // check if key is pressed
			{
				while(!(Keypad_Pin & (1 << Keypad_Row[j]))) //wait for to be released (single press)
					switch(i)
					{
					case 0:
					{
						if(j == 0) return '7';
						if(j == 1) return '4';
						if(j == 2) return '1';
						if(j == 3) return '?';
						break;
					}
					case 1:
					{
						if(j == 0) return '8';
						if(j == 1) return '5';
						if(j == 2) return '2';
						if(j == 3) return '0';
						break;
					}
					case 2:
					{
						if(j == 0) return '9';
						if(j == 1) return '6';
						if(j == 2) return '3';
						if(j == 3) return '=';
						break;
					}
					case 3:
					{
						if(j == 0) return '/';
						if(j == 1) return '*';
						if(j == 2) return '-';
						if(j == 3) return '+';
						break;
					}


					}
			}
		}
	}

	return 'A' ; // Return A if no key is pressed
}
