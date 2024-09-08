/*
 *
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	main.c	>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>
#include "student.h"

#define student_Numbers 50

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int choice;

	FIFO_Buf_t student_queue;
	FIFO_Student_t student_buf[student_Numbers];

	printf("Welcome to the Student Management System\n");

	FIFO_init(&student_queue, student_buf, student_Numbers);

	while(1){
		printf("\n===========================\n");
		printf("Choose the task that you want to perform \n");
		printf("1. Add the Student Details Manually\n");
		printf("2. Add the Student Details From Text file\n");
		printf("3. Find the Student Details by roll number\n");
		printf("4. Find the Student Details by First Name\n");
		printf("5. Find the Student Details by Course Id\n");
		printf("6. Show all information of the students\n");
		printf("7. Find the Total number of Students \n");
		printf("8. Update the Student Details by roll number\n");
		printf("9. Delete the Student Details by roll number\n");
		printf("10. To Exit\n");


		printf("Enter your choice to perform the task\n");
		scanf("%d", &choice);
		printf("\n===========================\n");

		switch (choice) {
		case 1:
			add_student_manually(&student_queue);
			break;

		case 2:
			add_student_file(&student_queue);
			break;

		case 3:
			find_Student_by_id(&student_queue);
			break;

		case 4:
			find_Student_by_name(&student_queue, student_buf);
			break;

		case 5:
			find_Student_by_courseId(&student_queue);
			break;

		case 6:
			Show_info(&student_queue);
			break;

		case 7:
			Count_The_Student(&student_queue);
			break;

		case 8:
			Update_Student(&student_queue);
			break;

		case 9:
			Delete_Student(&student_queue);
			break;

		case 10:
			Exit();
			break;

		}
	}


	return 0;
}
