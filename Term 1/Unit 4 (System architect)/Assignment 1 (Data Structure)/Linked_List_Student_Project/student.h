
/*
 * student.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Mohamed_Ayman
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//type definition
struct SData{
	unsigned int ID;
	char Name[40];
	float height;
};

//Linked_list Node
struct Sstudent{
	struct SData Student;
	struct Sstudent* PNext_Student;
};

//struct Sstudent *gpFirstStudent = NULL;

//APIs
void AddStudent();

int Delete_Student();

void View_Student();

void DeleteALL();

void Get_Number_Node();

void count_the_Nodes();

int get_length_node();

void get_nth_node_end();

void get_middle_linkedList();

void Revers_linkedList();

#endif /* STUDENT_H_ */
