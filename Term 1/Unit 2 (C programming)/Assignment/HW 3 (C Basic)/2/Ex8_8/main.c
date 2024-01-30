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

	float num1, num2;
	char ch;
	printf("Enter operator + or - or * or /: ");
	scanf("%c", &ch);

	printf("enter two numbers: ");
	scanf("%f %f", &num1, &num2);

	switch (ch) {
	case '+':
		printf("the sum is %f", (num1 + num2));
		break;

	case '-':
		printf("the subtract is %f", (num1 - num2));
		break;

	case '*':
		printf("the multiply is %f", (num1 * num2));
		break;

	case '/':
		printf("the division is %f", (num1 / num2));
		break;
	}

	return 0;
}

