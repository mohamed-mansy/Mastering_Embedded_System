/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int ReverseDigit(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("The Reverse Digit is: %d", ReverseDigit(num));


	return 0;
}
int ReverseDigit(int num){

	int rem , reveredNumber = 0;
	while(num != 0){
		rem = num % 10;
		reveredNumber = reveredNumber * 10 + rem;
		num /= 10;
	}

	return reveredNumber;
}
