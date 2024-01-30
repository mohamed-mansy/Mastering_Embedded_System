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

	float number;
	printf("Enter the number: ");
	scanf("%f", &number);

	if(number > 0)
		printf("%f is positive", number);

	else if(number < 0)
		printf("%f is negative", number);

	else
		printf("You entered zero");

	return 0;
}

