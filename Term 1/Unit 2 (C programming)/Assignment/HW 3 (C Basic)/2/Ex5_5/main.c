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

	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		printf("%c is an alphabet", ch);

	else
		printf("%c is not an alphabet", ch);

	return 0;
}
