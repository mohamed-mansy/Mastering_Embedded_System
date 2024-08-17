/*
 * DC.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */
#include "DC.h"

//variables
int DC_speed = 0;

//state pointer to function
void (*DC_state_ptr)();

void DC_init()
{
	//init PWM
	printf("init DC_motor\n");
}

void DC_motor(int s)
{
	DC_speed = s;
	DC_state_ptr = state(DC_busy);
	printf("CA ----------speed = %d----------> DC\n", DC_speed);
}

//definition of states functions
state_define(DC_idle)
{
	//state_Name
	//DC_state_id = DC_idle;

	//state_Action
	//call PWM to make speed = DC_speed

	printf("DC_idle State: speed = %d\n", DC_speed);
}


state_define(DC_busy)
{
	//state_Name
	//DC_state_id = DC_busy;

	//state_Action
	//call PWM to make speed = DC_speed

	DC_state_ptr = state(DC_idle);
	printf("DC_busy State: speed = %d\n", DC_speed);
}

