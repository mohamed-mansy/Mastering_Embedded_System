/*
 * main.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float a[2][2];
	float b[2][2];

	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("Matrix1: (%d , %d): ", i, j);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Matrix1 is: \n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%f\t", a[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("Matrix2: (%d , %d): ", i, j);
			scanf("%f", &b[i][j]);
		}
	}

	printf("Matrix2 is: \n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%f\t", b[i][j]);
		}
		printf("\n");
	}

	printf("sum of matrix: \n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%f\t", a[i][j] + b[i][j]);
		}
		printf("\n");
	}

	return 0;
}
