/*
 * pressure_Sensor.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Mohamed_Ayman
 */

#include "pressure_Sensor.h"
#include "Mointor_Alarm.h"

int Pval = 0;
int threshold = 20;

void (*pressure_State_ptr) ();

state_define(Reading)
{
	//get the value from pressure sensor
	Pval = getPressureVal();

	//check the pressure value with threshold
	if(Pval > threshold)
	{
		High_Pressure_Detection();
	}

	Delay(10000);
	
	pressure_State_ptr = state(Reading);

}

