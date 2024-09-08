/*
 * student.h
 *
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	Student_Database_Using_Queue.h	>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *      Author: Mohamed_Ayman
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Name_Width 20
#define Courses_Number 5

typedef struct{
	unsigned int roll;
	char Fname[Name_Width];
	char Lname[Name_Width];
	float GPA;
	unsigned int CourseId[Courses_Number];
}FIFO_Student_t;

//type definition
typedef struct {
	FIFO_Student_t *base;
	FIFO_Student_t *tail;
	FIFO_Student_t *head;
	unsigned int count;
	unsigned int length;
}FIFO_Buf_t;

//status
typedef enum {
	FIFO_no_error,
	FIFO_empty,
	FIFO_full,
	FIFO_null
}FIFO_status_t;

//APIs

FIFO_status_t FIFO_enqueue_item(FIFO_Buf_t *fifo_buf , FIFO_Student_t item);

FIFO_status_t FIFO_dequeue_item(FIFO_Buf_t *fifo_buf, FIFO_Student_t* item);

FIFO_status_t FIFO_init(FIFO_Buf_t *fifo_buf , FIFO_Student_t* buf, unsigned int length);

FIFO_status_t FIFO_is_full(FIFO_Buf_t *fifo_buf );

void add_student_file(FIFO_Buf_t *student_queue);

void add_student_manually(FIFO_Buf_t *student_queue);

void find_Student_by_id(FIFO_Buf_t *student_queue);

void find_Student_by_name(FIFO_Buf_t *student_queue, FIFO_Student_t *student);

void find_Student_by_courseId(FIFO_Buf_t *student_queue);

void Count_The_Student(FIFO_Buf_t *student_queue);

void Delete_Student(FIFO_Buf_t *student_queue);

void Update_Student(FIFO_Buf_t *student_queue);

void Show_info(FIFO_Buf_t *student_queue);

void Exit();


#endif /* STUDENT_H_ */

