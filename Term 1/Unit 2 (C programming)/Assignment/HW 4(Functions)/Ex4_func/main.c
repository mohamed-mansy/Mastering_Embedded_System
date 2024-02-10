/*
 * main.c
 *
 *  Created on: Feb 10, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int square(int num , int base);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num , base , result;
	printf("Enter base number: ");
	scanf("%d", &base);
	printf("Enter positive number: ");
	scanf("%d", &num);

	result = square(num , base);
	printf("%d^%d = %d", num , base , result);



	return 0;
}
int square(int num , int base){

	if(base == 0)
		return 1;

	else
		return num * square(num , base - 1);





}
