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

	float num1 , num2;
	float sum;
	printf("enter the two numbers: ");
	scanf("%f %f", &num1, &num2);

	sum = num1 * num2;
	printf("the multiply: %f", sum);

	return 0;
}

