/*
 * main.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mohamed_Ayman
 */

#include <stdio.h>

struct Scomplex{
	double Real;
	double Imaginary;
};

struct Scomplex ReadComplex(char name[]);
struct Scomplex Add(struct Scomplex value1 , struct Scomplex value2);
void print(char name[] , struct Scomplex result);

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Scomplex Value1 , Value2 , Result;
	Value1 = ReadComplex("for 1st complex number");
	Value2 = ReadComplex("for 2nd complex number");
	Result = Add(Value1 , Value2);

	print("Sum" , Result);


	return 0;
}
struct Scomplex ReadComplex(char name[]){

	struct Scomplex value;
	printf("%s\n", name);
	printf("Enter real and imaginary respectively: ");
	scanf("%lf %lf", &value.Real , &value.Imaginary);

	return value;
}

struct Scomplex Add(struct Scomplex value1 , struct Scomplex value2){

	struct Scomplex Result;
	Result.Real = value1.Real + value2.Real;
	Result.Imaginary = value1.Imaginary + value2.Imaginary;

	return Result;
}

void print(char name[] , struct Scomplex result){

	printf("%s = %.2lf + %.2lfi", name , result.Real , result.Imaginary);

}
