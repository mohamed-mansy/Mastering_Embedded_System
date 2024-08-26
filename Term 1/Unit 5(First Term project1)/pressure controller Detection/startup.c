/*
startup.c cortex-m3
End.Mohamed_Ayman
*/

#include <stdint.h>
extern int main(void);

void Reset_Handler();
void Defult_Handler()
{
	Reset_Handler();
}

void NMI_Handler() __attribute__((weak, alias("Defult_Handler")));;

void H_fault_Handler() __attribute__((weak, alias("Defult_Handler")));;

void MM_fault_Handler() __attribute__((weak, alias("Defult_Handler")));;

void Bus_fault_Handler() __attribute__((weak, alias("Defult_Handler")));;

void Usage_fault_Handler() __attribute__((weak, alias("Defult_Handler")));;

extern uint32_t stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) ={
	(uint32_t) &stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault_Handler,
	(uint32_t) &Usage_fault_Handler
};

extern uint32_t E_text;
extern uint32_t S_data;
extern uint32_t E_data;
extern uint32_t S_bss;
extern uint32_t E_bss;

void Reset_Handler()
{
	//copy .data from ROM to RAM
	uint32_t Data_size = (unsigned char *)&E_data - (unsigned char *)&S_data;
	unsigned char *p_src = (unsigned char *)&E_text;
	unsigned char *p_des = (unsigned char *)&S_data;
	for(int i = 0; i < Data_size; i++)
	{
		*((unsigned char *)p_des++) = *((unsigned char *)p_src++);
	}
	
	//init .bss with zero
	uint32_t bss_size = (unsigned char *)&E_bss - (unsigned char *)&E_bss;
	p_des = (unsigned char *)&S_bss;
	for(int i = 0; i < bss_size; i++)
	{
		*((unsigned char *)p_des++) = (unsigned char)0;
	}
	//jumb to main
	main();
}