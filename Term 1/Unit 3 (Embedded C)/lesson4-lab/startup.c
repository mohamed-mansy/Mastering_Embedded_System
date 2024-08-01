/*
startup.c cortex-m4
End.Mohamed_Ayman
*/

#include <stdint.h>
extern int main(void);

void Reset_Handler();

void Default_Handler(){
	
	Reset_Handler();
}
void NMI_Handler() __attribute__ ((weak, alias("Default_Handler")));;
	
void H_fault_Handler() __attribute__ ((weak, alias("Default_Handler")));;
	
//booking 1024 B located by .bss through unintialized array of int 256 element (256 * 4 = 1024)
static unsigned long Stack_top[256];


void ( * const g_p_fun_vectors[])()__attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)) ,
	&Reset_Handler ,
	&NMI_Handler ,
	&H_fault_Handler 
	
};

extern uint32_t E_text;
extern uint32_t S_data;
extern uint32_t E_data;
extern uint32_t S_bss;
extern uint32_t E_bss;

void Reset_Handler(){
	// copy .data from flash to sram
	uint32_t data_size = (unsigned char*)&E_data - (unsigned char*)&S_data;
	unsigned char* p_src = (unsigned char*)&E_text;
	unsigned char* p_des = (unsigned char*)&S_data;
	for(int i = 0; i < data_size; i++){
		
		*((unsigned char*)p_des++) = *((unsigned char*)p_src++);
	}
	
	// init .bss with zero
	uint32_t bss_size = (unsigned char*)&E_bss - (unsigned char*)&S_bss;
	p_des = (unsigned char*)&S_bss;
	for(int i = 0; i < data_size; i++){
		
		*((unsigned char*)p_des++) = (unsigned char) 0;
	}
	// call main
	main();
}