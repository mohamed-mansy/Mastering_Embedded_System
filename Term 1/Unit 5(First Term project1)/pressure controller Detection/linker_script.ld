/*Learn_in_depth
linker_script Cortex-m3
Eng.Mohamed_Ayman
*/

MEMORY
{
	FLASH(rx) : ORIGIN = 0x08000000 , LENGTH = 128K
	SRAM(rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors)
		*(.text)
		*(.rodata) 
		E_text = .;
	}> FLASH 
	
	.data :
	{
		S_data = .;
		*(.data)
		. = ALIGN(4);
		E_data = .;
	}> SRAM AT> FLASH
	
	.bss :
	{
		S_bss = .;
		*(.bss)
		E_bss = .;
		. = ALIGN(4);
		. = . + 0x1000;
		stack_top = .;
	}> SRAM
	
	
	
}