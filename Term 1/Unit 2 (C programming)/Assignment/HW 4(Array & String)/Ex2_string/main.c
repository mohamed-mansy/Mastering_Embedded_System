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
	printf("Enter a string: ");
	gets(str);

	int i = 0 , length = 0;
	while(str[i] != 0){
		length++;
		i++;
	}
	printf("Length of string is: %d", length);


	return 0;
}
