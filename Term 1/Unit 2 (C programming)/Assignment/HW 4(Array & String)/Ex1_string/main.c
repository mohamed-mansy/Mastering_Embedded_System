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

	char ch;
	printf("Enter a character to find frequency: ");
	scanf("%c", &ch);

	int i , frequency = 0;
	for(i = 0; i < strlen(str)+1; i++){
		if(str[i] == ch){
			frequency++;
		}
	}
	printf("frequency of %c = %d", ch , frequency);

	return 0;
}
