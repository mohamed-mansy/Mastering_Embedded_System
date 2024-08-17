/*
 * US.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */
#include "US.h"

//variables
int US_distance = 0;

//state pointer to function
void (*US_state_ptr)();

//to get random distance
int ultrasonic_get_distance_random(int Low, int End, int count);

void US_init()
{
	//init US_driver
	printf("US_driver\n");
}

//definition of states functions

state_define(US_Busy)
{
	//state_Name
	//US_state_id = US_Busy;

	//state_Action
	US_distance = ultrasonic_get_distance_random(45, 55, 1);

	printf("US_Busy State: distance = %d\n", US_distance);
	US_Set_Distance(US_distance);
	US_state_ptr = state(US_Busy);
}

int ultrasonic_get_distance_random(int Low, int End, int count)
{
	//low the beginning of range and end is the end of range
	//count is =>how many number to get the random numbers
	//this will generate random number between low and end
	unsigned int i;
	for(i = 0; i < count; i++)
	{
		int rand_num = (rand() % (End - Low + 1)) + Low;
		return rand_num;
	}

}
