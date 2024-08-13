/*
 * fifo.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Administrator
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include "stdint.h"

//USER configuration
//select the element type (uint8_t, uint16_t, uint32, .....)
#define element_type uint8_t

//type definition
typedef struct{
	unsigned int count;
	unsigned int length;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_empty,
	FIFO_full,
	FIFO_NULL
}FIFO_status;

//FIFO APIs
FIFO_status	FIFO_enqueue_item(FIFO_buf_t* fifo_buf, element_type item);

FIFO_status	FIFO_dequeue_item(FIFO_buf_t* fifo_buf, element_type* item);

FIFO_status	FIFO_init(FIFO_buf_t* fifo_buf, element_type* buf, int lenght);

FIFO_status	FIFO_is_full(FIFO_buf_t* fifo_buf);

void FIFO_print(FIFO_buf_t* fifo_buf);


#endif /* FIFO_H_ */
