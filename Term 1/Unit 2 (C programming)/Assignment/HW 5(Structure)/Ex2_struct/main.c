/*
 * main.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

struct SDistance {
	int feet;
	float inch;
};

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct SDistance D1, D2, Result;
	printf("Enter information for 1st distance\nEnter feet: ");
	scanf("%d", &D1.feet);

	printf("Enter inch: ");
	scanf("%f", &D1.inch);

	printf("Enter information for 2st distance\nEnter feet: ");
	scanf("%d", &D2.feet);

	printf("Enter inch: ");
	scanf("%f", &D2.inch);

	Result.feet = D1.feet + D2.feet;
	Result.inch = D1.inch + D2.inch;

	// convert inches to feet if greater than 12 //
	if(Result.inch >= 12.0){
		Result.inch = Result.inch - 12.0;
		++Result.feet;
	}

	printf("\nsum of distances = %d\'-%.2f\"" , Result.feet , Result.inch);

	return 0;
}
