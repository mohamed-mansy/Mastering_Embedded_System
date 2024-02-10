/*
 * main.c
 *
 *  Created on: Feb 10, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int prime_number(int number);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num1 = 10 , num2 = 30 , i , flag;
	printf("Enter two numbers (intervals): ");
	scanf("%d %d", &num1 , &num2);

	printf("prime numbers between %d and %d: ", num1 , num2);

	for(i = num1+1; i < num2; ++i){
		flag = prime_number(i);
		if(flag == 0)
			printf("%d ", i);
	}

	return 0;
}
int prime_number(int number){

	int i , flag = 0;
	for(i = 2; i <= number/2; ++i){
		if(number % i == 0){
			flag = 1;
			break;
		}
	}
	return flag;


}
