/*
 * main.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>
#include <string.h>

void ReverseWord(char str[]);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char str[20];
	printf("Enter a string: ");
	gets(str);

	ReverseWord(str);


	return 0;
}
void ReverseWord(char str[]){

	int i , len , index , wordStart , wordEnd;
	char rev[20];
	len = strlen(str);
	index = 0;
	wordStart = len - 1;
	wordEnd = len - 1;

	while(wordStart > 0){

		if(str[wordStart] == ' '){

			i = wordStart + 1;
			while(i <= wordEnd){
				rev[index] = str[i];
				index++;
				i++;
			}
			rev[index++] = ' ';
			wordEnd = wordStart - 1;
		}

		wordStart--;
	}

	for(i = 0; i <= wordEnd; i++){
		rev[index] = str[i];
		index++;
	}

	rev[index] = 0; // Add Null Character //

	printf("reverse string words is :%s\n", rev);




}
