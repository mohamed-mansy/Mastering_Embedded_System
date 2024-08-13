/*
 * fifo.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Administrator
 */

#include "fifo.h"

FIFO_status	FIFO_enqueue_item(FIFO_buf_t* fifo_buf, element_type item)
{
	//check fifo is valid
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//check fifo is full
	if(FIFO_is_full(fifo_buf)== FIFO_full)
		return FIFO_full;

	//add items
	*(fifo_buf->head) = item;

	//circular FIFo
	if(fifo_buf->head == (fifo_buf->base + fifo_buf->length * sizeof(element_type)))
		fifo_buf->head = fifo_buf->base;
	else
		fifo_buf->head++;

	fifo_buf->count++;

	return FIFO_no_error;
}

FIFO_status	FIFO_dequeue_item(FIFO_buf_t* fifo_buf, element_type* item)
{
	//check fifo is valid
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//check fifo is empty
	if(fifo_buf->count == 0)
		return FIFO_empty;

	//pop items
	*(item) = *(fifo_buf->tail);
	fifo_buf->count--;
	//circular FIFo
	if(fifo_buf->tail == (fifo_buf->base + fifo_buf->length * sizeof(element_type)))
		fifo_buf->tail = fifo_buf->base;
	else
		fifo_buf->tail++;

	return FIFO_no_error;
}

FIFO_status	FIFO_init(FIFO_buf_t* fifo_buf, element_type* buf, int lenght)
{
	if(buf == NULL)
		return FIFO_NULL;

	fifo_buf->base = buf;
	fifo_buf->head = buf;
	fifo_buf->tail = buf;
	fifo_buf->length = lenght;
	fifo_buf->count = 0;

	return FIFO_no_error;
}

FIFO_status	FIFO_is_full(FIFO_buf_t* fifo_buf)
{
	//check fifo is valid
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	if(fifo_buf->length == fifo_buf->count)
		return FIFO_full;

	return FIFO_empty;

}

void FIFO_print(FIFO_buf_t* fifo_buf)
{
	element_type i, *temp;
	if(fifo_buf->count == 0)
		printf("FIFO is empty\n");

	temp = fifo_buf->tail;
	printf("\n==========FIFO_print===============\n");
	for(i = 0; i < fifo_buf->count; i++){
		printf("\t %X \n", *temp);
		temp++;
	}
	printf("\n========================\n");

}
