/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int CountOnes(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("result = %d", CountOnes(num));

	return 0;
}
int CountOnes(int num){

	int count = 0;
	while(num != 0){
		if(num & 1)
			count++;
		num = num >> 1;

	}

	return count;
}
