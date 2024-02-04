/*
 * main.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n , i;
	float average , sum = 0.0;
	printf("enter the numbers of data: ");
	scanf("%d", &n);
	float a[50];

	for(i = 1; i <= n; i++){
		printf("Enter number %d: ", i);
		scanf("%f", &a[i]);
		sum += a[i];
	}
	average = sum / (i-1);
	printf("Average is : %0.2f", average);

	return 0;
}
