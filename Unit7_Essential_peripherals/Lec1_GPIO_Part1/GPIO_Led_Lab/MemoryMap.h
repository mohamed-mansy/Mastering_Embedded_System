/*
 * MemoryMap.h
 *
 *  Created on: Oct 5, 2024
 *      Author: Administrator
 */

#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

//GPIOA
#define DDRA  *((volatile unsigned char *) 0x3A)
#define PORTA  *((volatile unsigned char *) 0x3B)
#define PINA  *((volatile unsigned char *) 0x39)
//i made volatile on data not on the address

//GPIOB
#define DDRB  *((volatile unsigned char *) 0x37)
#define PORTB  *((volatile unsigned char *) 0x38)
#define PINB  *((volatile unsigned char *) 0x36)

//GPIOC
#define DDRC  *((volatile unsigned char *) 0x34)
#define PORTC  *((volatile unsigned char *) 0x35)
#define PINC  *((volatile unsigned char *) 0x33)

#endif /* MEMORYMAP_H_ */
