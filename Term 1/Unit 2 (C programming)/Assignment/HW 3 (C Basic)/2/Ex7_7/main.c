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

	int number ,i;
	int Factorial = 1;
	printf("Enter the number: ");
	scanf("%d", &number);

	if(number < 0)
		printf("Error!!! Factorial of negative number dosen't exist");

	else if(number == 0)
		printf("Factorial = 1");

	if(number > 0){
		for(i = number; i >= 1; i--){
			Factorial *= i;
		}
		printf("Factorial = %d", Factorial);
	}


	return 0;
}

