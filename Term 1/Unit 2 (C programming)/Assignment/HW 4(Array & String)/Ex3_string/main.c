/*
 * main.c
 *
 *  Created on: Feb 4, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>
#include <string.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char str[100];
	char rev[100];
	printf("Enter a string: ");
	scanf("%s", str);

	int length = strlen(str);

	printf("reverse string is: ");
	int i , j;
	for(j = 0 , i = length-1; i >= 0 && j < length ; i-- , j++){
		rev[j] = str[i];
	}
	printf("%s", rev);

	return 0;
}
