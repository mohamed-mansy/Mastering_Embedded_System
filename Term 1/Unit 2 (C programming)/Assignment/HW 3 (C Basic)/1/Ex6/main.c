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
	float temp;
	printf("Enter the two numbers: ");
	scanf("%f %f", &num1, &num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("After swapping, value of num1 = %.2f\n", num1);
	printf("After swapping, value of num2 = %.2f\n", num2);

	return 0;
}

