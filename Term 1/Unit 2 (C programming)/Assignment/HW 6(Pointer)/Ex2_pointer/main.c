/*
 * main.c
 *
 *  Created on: Mar 8, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char alph[27];
	char* ptr;
	int i;

	ptr = alph;
	// storing alphabets in the array//
	for(i = 0; i < 26; i++){
		*ptr = i + 'A';
		ptr++;
	}
	ptr = alph; // Resetting the pointer to the first address in array

	for(i = 0; i < 26; i++){
		printf("%c  ", *ptr++);
	}

	return 0;
}

