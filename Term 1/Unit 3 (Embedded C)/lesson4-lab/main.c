/*Copywrite @mohamed_Ayman
Kit=TivaC
MCU=TM4C123GXL
description: Toggle_led portf pin3
Learn_In_Depth
*/

#define SYSCTL_RCGC2_R_E	(*((volatile unsigned int*)(0x400FE108))) // enable the GPIO port
#define GPIO_PORTF_DIR_R	(*((volatile unsigned int*)(0x40025400))) // set the direction input/ouput
#define GPIO_PORTF_DEN_R	(*((volatile unsigned int*)(0x4002551C))) // enable the GPIO pin
#define GPIO_PORTF_Data_R	(*((volatile unsigned int*)(0x400253FC))) // set the pin High or Low


int main()
{
	volatile unsigned int i;
	SYSCTL_RCGC2_R_E = 0x20;
	//delay to make sure GPIOF is up and run
	for(i = 0; i < 200; i++);
	
	GPIO_PORTF_DIR_R |= (1 << 3);//Direction is output for pin3 portF
	GPIO_PORTF_DEN_R |= (1 << 3);
	
	while(1){
		
		GPIO_PORTF_Data_R |= (1 << 3);//set pin 1
		for(i = 0; i < 20000; i++);
		
		GPIO_PORTF_Data_R &= ~(1 << 3);//set pin 0
		for(i = 0; i < 20000; i++);
	}
	
	
	return 0;
}
	