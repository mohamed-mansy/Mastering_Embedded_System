/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

void reverse(int arr[], int size);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[5] = {1 , 2 , 3 ,4 ,5 };
	int n = sizeof(arr) / sizeof(int);

	reverse(arr , n);

	return 0;
}
void reverse(int arr[], int size){

	int rev[10];
	int i , j;

	for(i = size -1 , j = 0; i >= 0 && j < size; i-- , j++){
		rev[j] = arr[i];
	}

	rev[j] = 0; // Add Null termination //

	printf("output: ");

	for(j = 0; rev[j] != 0; j++){
	printf("%d ", rev[j]);
	}

}
