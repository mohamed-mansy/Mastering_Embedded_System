/*Learn_in_depth
startup Cortex-m3
Eng.Mohamed_Ayman
*/

.section .vectors
.word  0x20001000 		/*Stack_Top_Address*/
.word _reset			/*1 Reset*/
.word Vector_handler	/*2 NMI*/
.word Vector_handler	/*3 Hard Falut*/
.word Vector_handler	/*4 MM Falut*/
.word Vector_handler	/*5 Bus Falut*/
.word Vector_handler 	/*6 Usage Falut*/
.word Vector_handler	/*7 RESERVED*/
.word Vector_handler	/*8 RESERVED*/
.word Vector_handler	/*9 RESERVED*/
.word Vector_handler	/*10 RESERVED*/
.word Vector_handler	/*11 SV call*/
.word Vector_handler	/*12 Debug reserved*/
.word Vector_handler	/*13 RESERVED*/
.word Vector_handler	/*14 pendSV*/
.word Vector_handler	/*15 SysTick*/
.word Vector_handler	/*16 IRQ0*/
.word Vector_handler	/*17 IRQ1*/
.word Vector_handler	/*18 IRQ2*/

.section .text
_reset:
	bl main
	b .

.thumb_func  /*Enable 16-bit instruction so we have 16 or 32-bit instruction whenever compiler use*/	
Vector_handler:
	b _reset