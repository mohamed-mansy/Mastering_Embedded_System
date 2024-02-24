/*
 * main.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

struct Sstduent{
	char name[50];
	int roll;
	float mark;
};

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Sstduent S1;
	printf("Enter information of students:\nEnter name: ");
	scanf("%s", S1.name);

	printf("Enter roll number: ");
	scanf("%d", &S1.roll);

	printf("Enter mark: ");
	scanf("%f", &S1.mark);

	printf("Displaying information\n");
	printf("Name: %s\nRoll: %d\nMarks: %.2f", S1.name , S1.roll , S1.mark);

	return 0;
}
