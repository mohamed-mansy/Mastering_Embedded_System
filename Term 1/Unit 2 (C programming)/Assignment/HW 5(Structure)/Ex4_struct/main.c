/*
 * main.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

struct Sstduent {
	char name[50];
	int roll;
	float mark;
};

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Sstduent student[10];
	printf("Enter information of students: \n");
	int i;
	for(i = 0; i < 10; i++){
		printf("For roll number ");
		scanf("%d", &student[i].roll);
		printf("Enter name: ");
		scanf("%s", student[i].name);
		printf("Enter marks: ");
		scanf("%f", &student[i].mark);
		printf("\n");
	}

	printf("Displaying information of students: \n");
	for(i = 0; i < 10; i++){
		printf("For roll %d\n", student[i].roll);
		printf("Name: %s\n", student[i].name);
		printf("Marks: %.2f\n", student[i].mark);
	}

	return 0;
}

