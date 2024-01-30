/*
 * main.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int n , i;
	int sum = 0;
	printf("Enter an integer: ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++){
		sum = sum + i;
	}
	printf("sum = %d", sum);

	return 0;
}

