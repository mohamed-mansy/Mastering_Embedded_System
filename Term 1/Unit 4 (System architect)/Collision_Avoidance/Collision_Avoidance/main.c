/*
 * main.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */
#include "CA.h"
#include "DC.h"
#include "US.h"

void setup()
{
	//init all the drivers
	//init IRQ....
	//init HAL US_driver , DC_motor_driver
	//init Block
	//set states pointer for each block
	US_init();
	DC_init();

	CA_state_ptr = state(CA_Wating);
	US_state_ptr = state(US_Busy);
	DC_state_ptr = state(DC_idle);
	//it just pointer has address of state of CA_Wating function
	//not jump to this function
}

void main()
{
	volatile int i;
	setup();

	while(1)
	{
		//call state
		US_state_ptr();
		CA_state_ptr();
		DC_state_ptr();
		for(i = 0; i < 1000; i++);

	}

}
