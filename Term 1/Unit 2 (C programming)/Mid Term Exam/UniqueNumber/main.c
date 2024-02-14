/*
 * main.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

void FindUniqueNumber(int arr[] , int freq[] , int size);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[50] , freq[50];
	int size , i;
	printf("Enter the size of array: ");
	scanf("%d", &size);

	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
		freq[i] = -1;
	}

	FindUniqueNumber(arr , freq , size);

	return 0;
}
void FindUniqueNumber(int arr[] , int freq[] , int size){

	// find frequency of each element //
	int i , j;
	for(i = 0; i < size; i++){
		int count = 1;
		for(j = 1 + i; j < size; j++){
			if(arr[i] == arr[j]){
				count++;
				freq[j] = 0;
			}
		}

		if(freq[i] != 0)
			freq[i] = count;
	}

	for(i = 0; i < size; i++){
		if(freq[i] == 1)
			printf("the unique number is: %d", arr[i]);
	}

}

