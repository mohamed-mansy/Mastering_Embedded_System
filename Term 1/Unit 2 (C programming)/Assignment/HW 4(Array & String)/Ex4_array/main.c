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

	int a[100];
	int n, i , position , x;
	printf("Enter number of element: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++){
		printf("Enter the element %d: ", i+1);
		scanf("%d", &a[i]);
	}

	printf("Enter the element to be inserted : ");
	scanf("%d", &x);

	printf("Enter the location: ");
	scanf("%d", &position);

	// increase the size by 1
	n++;
	for(i = n-1; i >= position; i--){
		a[i] = a[i-1];
	}
	a[position - 1] = x;
	printf("Enter the elements after inserted: \n");
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}



	return 0;
}
