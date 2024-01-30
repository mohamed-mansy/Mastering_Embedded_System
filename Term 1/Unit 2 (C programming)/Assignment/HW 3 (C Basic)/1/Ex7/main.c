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
	printf("Enter the two numbers: ");
	scanf("%f %f", &num1, &num2);

	sum = num1 + num2; // sum = 1.2 + 2.45 = 3.65
	num2 = sum - num2; // num2 = 3.65 - 2.45 = 1.2
	num1 = sum - num1; // num1 = 3.65 - 1.2 = 2.45

	printf("After swapping, value of num1 = %.2f\n", num1);
	printf("After swapping, value of num2 = %.2f\n", num2);



	return 0;
}


