
#include "Uart.h"

unsigned char string_buffer[100] = "learn in depth:<Mohamed";
unsigned char const string_buffer2[100] = "learn in depth:<Mohamed";

void main(void){
	
	Uart_Send_String(string_buffer);
}