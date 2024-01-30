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

	int number;
	printf("Enter the number: ");
	scanf("%d", &number);

	if(number % 2 ==0)
	{
		printf("%d is even", number);
	}
	else
		printf("%d is odd", number);

	return 0;
}

