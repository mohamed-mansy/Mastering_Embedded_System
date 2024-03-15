/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[15];
	int *ptr , n;
	printf("Enter numbers of element in array: ");
	scanf("%d", &n);

	ptr = arr;

	printf("Enter the elements of array: \n");
	int i;
	for(i = 0; i < n; i++){
		printf("element - %d: ", i+1);
		scanf("%d", ptr);
		ptr++;
	}

	ptr = &arr[n-1];

	printf("The elements of array in reverse order are :\n");
	for(i = n; i > 0; i--){
		printf("element - %d = %d\n", i , *ptr--);
	}




	return 0;
}


