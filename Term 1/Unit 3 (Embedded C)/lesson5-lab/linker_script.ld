/*Learn_in_depth
linker_script Cortex-m3
Eng.Mohamed_Ayman
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000 ,   LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000 ,	LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
	E_text = .;
	} > flash
	.data : {
	S_data = .;
		*(.data)
		*(.data.*)	
	. = ALIGN(4);
	E_data = .;
	}> sram AT> flash
	.bss : {
	S_bss = .;
		*(.bss*)
	. = ALIGN(4);
	E_bss = .;
	. = . + 0x1000;
	heap_end = .;
	. = ALIGN(4);
	. = . + 0x1000;
	stack_top = .;
	}> sram


}