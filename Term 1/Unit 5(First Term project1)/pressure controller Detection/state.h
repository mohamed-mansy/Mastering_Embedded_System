/*
 * state.h
 *
 *  Created on: Aug 25, 2024
 *      Author: Administrator
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdio.h>

//Automatic states function generator
#define state_define(__stateFun__) void ST_##__stateFun__()

#define state(__stateFun__) ST_##__stateFun__

//states connection(mapping)
void set_pressureVal(int Pval);
void High_Pressure_Detection();
void stop_Alarm();
void start_Alarm();

#endif

