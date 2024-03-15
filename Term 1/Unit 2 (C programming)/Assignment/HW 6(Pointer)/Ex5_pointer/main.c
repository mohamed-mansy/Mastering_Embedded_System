/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

struct SEmployee{
	char* name;
	int ID;
};

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct SEmployee emp1 = {"Alex" , 1002} , emp2 = {"Mohamed", 25} , emp3 = {"Moka", 77};

	struct SEmployee (*arr[]) = {&emp1 , &emp2 , &emp3};

	struct SEmployee (*(*ptr)[3]) = &arr;

	printf("Employee1 name: %s , Employee1 Id: %d\n", (**(*ptr+0)).name , (**(*ptr)).ID);






	return 0;
}

