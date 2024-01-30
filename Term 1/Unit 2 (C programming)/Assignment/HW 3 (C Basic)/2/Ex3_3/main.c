/*
 * main.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float num1, num2, num3;
	printf("Enter three numbers: ");
	scanf("%f %f %f", &num1, &num2, &num3);

	if (num1 > num2) {
		if(num1 > num3){
			printf("the largest number is %.3f", num1);
		}
		else
			printf("the largest number is %.3f", num3);
	}
	if(num2 > num1){
		if(num2 > num3){
			printf("the largest number is %.3f", num2);
		}
		else
			printf("the largest number is %.3f", num3);

	}

	return 0;
}

