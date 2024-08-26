/*
 * Mointor_Alarm.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Mohamed_Ayman
 */

#include "Mointor_Alarm.h"

volatile int AlarmPeriod = 200000;

void High_Pressure_Detection()
{
	Set_Alarm_actuator(1);
	Delay(AlarmPeriod);
	Set_Alarm_actuator(0);
	Delay(AlarmPeriod);
}
