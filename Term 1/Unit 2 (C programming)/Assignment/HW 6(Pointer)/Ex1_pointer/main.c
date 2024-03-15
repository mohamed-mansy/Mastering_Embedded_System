/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int *ptr;
	int num;

	num = 5;
	printf("How to handle the pointers in the program: \n");
	printf("Address of m: %p\n", &num);
	printf("value of m: %d\n", num);

	ptr = &num;
	printf("Address of m: %p\n", ptr);
	printf("value of m: %d\n", *ptr);

	*ptr = 34;
	printf("Address of m: %p\n", ptr);
	printf("value of m: %d\n", num);


	return 0;
}

