/*
 * main.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Administrator
 */
#include "LIFO.h"

unsigned int buffer1[5]; // 5*4 =20Bytes

int main(){

	unsigned int i , temp = 0;
	//uart_lifo for static, and I2C_lifo for dynamic
	LIFO_Buf_t uart_lifo , I2C_lifo;

	//static allocation
	LIFO_init(&uart_lifo , buffer1 , 5);

	printf("first buffer (static allocation)\n");
	for(i = 0; i< 5; i++){
		if(LIFO_add_item(&uart_lifo , i) == LIFO_no_error)
		printf("UART_LIFO add : %d\n", i);
	}


	for(i = 0; i< 5; i++){
		if(LIFO_get_item(&uart_lifo , &temp) == LIFO_no_error)
		printf("UART_LIFO get : %d\n", temp);
	}

	//Dynamic allocation
	unsigned int* buffer2 = (unsigned int*) malloc(5* sizeof(int));
	LIFO_init(&I2C_lifo, buffer2, 5);

	printf("second buffer (dynamic allocation)\n");

	for(i = 0; i< 5; i++){
			if(LIFO_add_item(&I2C_lifo , i) == LIFO_no_error)
				printf("I2C_LIFO add : %d\n", i);
		}


		for(i = 0; i< 5; i++){
			if(LIFO_get_item(&I2C_lifo , &temp) == LIFO_no_error)
				printf("I2C_LIFO get : %d\n", temp);
		}


	return 0;
}
