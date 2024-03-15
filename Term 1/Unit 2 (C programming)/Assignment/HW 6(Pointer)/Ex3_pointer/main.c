/*
 * main.c
 *
 *  Created on: Mar 8, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>
#include <string.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char str[20];
	char rev[20];
	char* strr = str;
	char* revr = rev;
	int i = -1;

	printf("Enter a string: ");
	gets(str);

	while(*strr){
		strr++;// Moving the pointer to the end
		i++;// counting characters
	}

	while(i >= 0){
		strr--; // back to the last element
		*revr = *strr; // *revr here write in the pointer & *strr read the data
		revr++;
		i--;
	}

	*revr = 0; // add null character

	printf("Reverse of the string is: %s", rev);


	return 0;
}

