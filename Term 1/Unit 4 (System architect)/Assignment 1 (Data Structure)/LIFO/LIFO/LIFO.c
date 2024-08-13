/*
 * LIFO.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Administrator
 */
#include "LIFO.h"


LIFO_status_t LIFO_add_item(LIFO_Buf_t* lifo_buf , unsigned int item)
{
	//check lifo is valid
	if(!lifo_buf->Base || !lifo_buf->head)
		return LIFO_NULL;

	//check lifo is full?
//if(lifo_buf->head >= (lifo_buf->Base + lifo_buf->length * 4))
	if(lifo_buf->length == lifo_buf->count)
		return LIFO_full;

	//add item
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	return LIFO_no_error;

}

LIFO_status_t LIFO_get_item(LIFO_Buf_t* lifo_buf , unsigned int* item)
{
	//check lifo is valid
		if(!lifo_buf->Base || !lifo_buf->head)
			return LIFO_NULL;

	//check if lifo is empty?
	if(lifo_buf->count == 0)
		return LIFO_empty;

	//get item
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;

	return LIFO_no_error;


}

LIFO_status_t LIFO_init(LIFO_Buf_t* lifo_buf , unsigned int* buf, unsigned int length)
{
	if(buf == NULL)
		return LIFO_NULL;

	lifo_buf->Base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
}
