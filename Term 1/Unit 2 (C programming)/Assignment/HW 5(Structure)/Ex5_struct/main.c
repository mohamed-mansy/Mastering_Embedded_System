/*
 * main.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

#define pi 3.1415 // Macro

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float area , raduis;
	printf("Enter the radius: ");
	scanf("%f", &raduis);

	area = pi * raduis * raduis;
	printf("Area = %.2f", area);

	return 0;
}

