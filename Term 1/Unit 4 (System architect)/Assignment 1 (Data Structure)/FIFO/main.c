/*
 * main.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Mohamed_Ayman
 */

#include "fifo.h"
//create buffer
#define width 5
element_type uart_buff[width];

int main(){

	element_type i, temp = 0;

	FIFO_buf_t uart_buffer1;
	if(FIFO_init(&uart_buffer1 , uart_buff, width) == FIFO_no_error)
		printf("FIFO init ------Done\n");

	//add items
	for(i = 0; i < 7; i++){
		printf("FIFO enqueue (%x) \n", i);
		if(FIFO_enqueue_item(&uart_buffer1, i) == FIFO_no_error)
			printf("FIFO enqueue ------Done\n");
		else
			printf("FIFO enqueue ------failed\n");
	}

	FIFO_print(&uart_buffer1);

	//pop items

	if(FIFO_dequeue_item(&uart_buffer1, &temp) == FIFO_no_error)
		printf("FIFO dequeue %x ------Done\n", temp);

	if(FIFO_dequeue_item(&uart_buffer1, &temp) == FIFO_no_error)
		printf("FIFO dequeue %x ------Done\n", temp);

	FIFO_print(&uart_buffer1);






	return 0;
}
