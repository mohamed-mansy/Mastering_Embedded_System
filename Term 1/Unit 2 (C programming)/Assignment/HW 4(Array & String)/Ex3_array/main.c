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

	int row, column;
	printf("Enter rows and column of matrix: ");
	scanf("%d %d", &row, &column);

	int a[10][10];
	int t[10][10];
	printf("Enter the elements of matrix: \n");
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf("Enter the items (%d , %d): ", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	printf("Matrix is: \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	printf("Transpose of Matrix is: \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			t[j][i] = a[i][j];
		}
	}

	for (i = 0; i < column; i++) {
		for (j = 0; j < row; j++) {
			printf("%d\t", t[i][j]);
		}
		printf("\n");
	}
	return 0;
}
