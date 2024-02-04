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

	int a[100];
	int n, i , value , flag;
	printf("Enter number of element: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter the element%d: ", i+1);
		scanf("%d", &a[i]);
	}

	printf("Enter the element to be searched: ");
	scanf("%d", &value);

	for(i = 0; i < n; i++){
		if(a[i] == value){
			flag = 1;
			break;
		}
	}

	if(flag == 1){
		printf("number found at location: %d", i+1);
	}
	else
		printf("number is not found");

	return 0;
}
