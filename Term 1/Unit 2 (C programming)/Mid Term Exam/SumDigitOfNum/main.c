/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int sum_Digit(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("the sum of all digits is: %d", sum_Digit(num));


	return 0;
}
int sum_Digit(int num){

	static int sum = 0;
	int rem;
	if(num != 0){
		rem = num % 10;
		sum += rem;
		sum_Digit(num / 10);
	}
	else
		return 0;

	return sum;

	/////////////or we can make this//////////////////////

//	 while (num != 0)
//	    {
//	        rem = num % 10;
//	        sum = sum + rem;
//	        num = num / 10;
//	    }

}
