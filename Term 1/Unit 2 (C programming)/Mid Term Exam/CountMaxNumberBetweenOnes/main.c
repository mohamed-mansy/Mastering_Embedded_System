/*
 * main.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int Count_Number_Of_Ones(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	// c function to count the max number of ones between two zeros //

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("the max number of ones: %d", Count_Number_Of_Ones(num));

	return 0;
}
int Count_Number_Of_Ones(int num){

	int count = 0;
	for(; num > 0; num >>= 1){
		if(num % 2 == 0)
			count = 0;

		else
			count++;
	}

	return count;
}
