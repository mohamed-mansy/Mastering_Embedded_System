/*
 * Keypad.h
 *
 *  Created on: Oct 10, 2024
 *      Author: Administrator
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_

#include <avr/io.h>

#define keypad_port			PORTD
#define Keypad_Pin			PIND
#define Keypad_Direction	DDRD

//Keypad information
#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define C4	4
#define C5	5
#define C6	6
#define C7	7

//Functions

void Keypad_Init();

char KeypadPressed();



#endif /* HAL_KEYPAD_H_ */
