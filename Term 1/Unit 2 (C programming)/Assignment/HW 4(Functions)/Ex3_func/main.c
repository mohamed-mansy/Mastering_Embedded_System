/*
 * main.c
 *
 *  Created on: Feb 10, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>
#include <string.h>

void Rev_sentence(char str[]);

int main(){
//	setvbuf(stdout, NULL, _IONBF, 0);
//	setvbuf(stderr, NULL, _IONBF, 0);
//
//	char str [50] = "Hello";
//	printf("Enter a sentence: ");
//	gets(str);

	//Rev_sentence(str);
	printf("%p\n", main());

	return 0;
}
void Rev_sentence(char str[]){

	if(*str != '\0'){
		Rev_sentence(str + 1);
		printf("%c", *str);
	}

}
