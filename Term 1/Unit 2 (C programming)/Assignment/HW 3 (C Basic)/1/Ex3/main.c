/*
 * main.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num1 , num2;
	int sum;
	printf("enter the two numbers: ");
	scanf("%d %d", &num1, &num2);

	sum = num1 + num2;
	printf("the sum: %d", sum);

	return 0;
}

