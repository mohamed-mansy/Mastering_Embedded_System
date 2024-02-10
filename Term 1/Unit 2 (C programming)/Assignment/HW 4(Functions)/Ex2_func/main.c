/*
 * main.c
 *
 *  Created on: Feb 10, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int factorial(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int fact , num;
	printf("Enter a positive number: ");
	scanf("%d", &num);

	fact = factorial(num);
	printf("Factorial of %d = %d", num , fact);

	return 0;
}
int factorial(int num){

	if(num == 0)
		return 1;

	else
		return num * factorial(num - 1);
}
