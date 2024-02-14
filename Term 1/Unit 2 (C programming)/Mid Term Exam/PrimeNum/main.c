/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int prime_number(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num1 , num2 , i , flag;
	printf("Enter two number: ");
	scanf("%d %d", &num1 , &num2);

	printf("prime numbers between %d to %d: ", num1 , num2);

	for(i = num1; i < num2; i++){
		flag = prime_number(i);
		if(flag == 0)
			printf("%d ", i);

	}

	return 0;
}
int prime_number(int num){
	int i , flag = 0;

	for(i = 2; i <= num / 2; i++){
		if(num % i == 0){
			flag = 1;
			break;
		}
	}

	return flag;

}
