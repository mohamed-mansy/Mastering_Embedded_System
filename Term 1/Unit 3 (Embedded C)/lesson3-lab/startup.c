/*
startup.c with Cortex-m3
Learn_in_depth
Eng.Mohamed_Ayman
*/

#include <stdint.h>
extern int main(void);

void Reset_Handler();

void Defalut_Handler(){
	Reset_Handler();
}

void NMI_Handler() __attribute__ ((weak, alias ("Defalut_Handler")));;

void H_fault_Handler() __attribute__ ((weak, alias ("Defalut_Handler")));;
	
void MM_fault_Handler()__attribute__ ((weak, alias ("Defalut_Handler")));;
	
void Bus_fault()__attribute__ ((weak, alias ("Defalut_Handler")));;
	
void Usage_fault_Handler()__attribute__ ((weak, alias ("Defalut_Handler")));;
	
extern uint32_t _stack_top; // I use extern to make sure that linker to resolving the symbol there is in linker_script//

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	
	(uint32_t) &_stack_top ,
	(uint32_t) &Reset_Handler ,
	(uint32_t) &NMI_Handler ,
	(uint32_t) &H_fault_Handler ,
	(uint32_t) &MM_fault_Handler ,
	(uint32_t) &Bus_fault ,
	(uint32_t) &Usage_fault_Handler
};
extern uint32_t E_text;
extern uint32_t S_data;
extern uint32_t E_data;
extern uint32_t S_bss;
extern uint32_t E_bss;


void Reset_Handler(){
	//Copy .data from flash to sram
	uint32_t data_size = (unsigned char*)&E_data - (unsigned char*)&S_data;
	unsigned char* p_src = (unsigned char*)&E_text;
	unsigned char* p_des = (unsigned char*)&S_data;
	for(int i = 0; i < data_size; i++)
	{
		*((unsigned char*)p_des++) = *((unsigned char*)p_src++);
	}
	//init the .bss with zero
	uint32_t bss_size = (unsigned char*)&E_bss - (unsigned char*)&S_bss;
	p_des = (unsigned char*)&S_bss;
	for(int i = 0; i < bss_size; i++)
	{
		*((unsigned char*)p_des++) = (unsigned char)0;
	}
	//jump to main
	
	main();
}