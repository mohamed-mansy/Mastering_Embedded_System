/*
 * CA.c
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */
#include "CA.h"

//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

//state pointer to function
void (*CA_state_ptr)();

//States Connection
void US_Set_Distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)?(CA_state_ptr = state(CA_Wating)) : (CA_state_ptr = state(CA_Driving));
	printf("US ------distance = %d------------> CA\n", CA_distance);
}

//definition of states functions
state_define(CA_Wating)
{
	//state_Name
	//CA_state_id = CA_Wating;

	printf("CA_Wating State: distance = %d, speed = %d\n", CA_distance, CA_speed);
	//state_Action
	CA_speed = 0;
	DC_motor(CA_speed);

	//event
	//ultrasonic_get_distance

}

state_define(CA_Driving)
{
	//state_Name
	//CA_state_id = CA_Driving;

	printf("CA_Driving State: distance = %d, speed = %d\n", CA_distance, CA_speed);
	//state_Action
	CA_speed = 30;
	DC_motor(CA_speed);

	//event
	//ultrasonic_get_distance

}

