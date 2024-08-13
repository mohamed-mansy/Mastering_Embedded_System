/*
 * LIFO.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Mohamed_Ayman
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdio.h>
#include <stdlib.h>

//type definition

typedef struct {
	unsigned int *Base;
	unsigned int *head;
	unsigned int length;
	unsigned int count;
}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_NULL
}LIFO_status_t;

//APIs

LIFO_status_t LIFO_add_item(LIFO_Buf_t* lifo_buf , unsigned int item);

LIFO_status_t LIFO_get_item(LIFO_Buf_t* lifo_buf , unsigned int* item);

LIFO_status_t LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf, unsigned int length);

#endif /* LIFO_H_ */
