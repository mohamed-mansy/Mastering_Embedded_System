/*
 * pressure_Sensor.h
 *
 *  Created on: Aug 25, 2024
 *      Author: Mohamed_Ayman
 */
#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "driver.h"
#include "state.h"


//declare states function
state_define(Reading);

extern void (*pressure_State_ptr) ();

#endif
