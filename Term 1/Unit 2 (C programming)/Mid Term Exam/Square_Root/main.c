/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>
#include <math.h>

float Square_Root(int num);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("%f", Square_Root(num));


	return 0;
}
float Square_Root(int num){

	//return pow(num , 0.5);

	float sqrt , temp;
	sqrt = num / 2;
	temp = 0;

	while(sqrt != temp){
		temp = sqrt;
		sqrt = (num /temp + temp) / 2;
	}

	return sqrt;


}
