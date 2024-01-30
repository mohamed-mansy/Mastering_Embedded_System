/*
 * main.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char ch;
	printf("Enter the character: ");
	scanf("%c", &ch);

	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		printf("%c is a vowel", ch);

	else
		printf("%c is a constant",ch);

	return 0;
}

