/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int SumNumber(int num , int num2);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int start;
	printf("Enter the begining of sum: ");
	scanf("%d", &start);
	int end;
	printf("Enter the last number of sum: ");
	scanf("%d", &end);

	printf("%d", SumNumber(start , end));

	return 0;
}
int SumNumber(int num , int num2){

	static int sum = 0;

	if(num != num2){
		sum += num;
		SumNumber(++num , num2);
	}

	return sum;
}
