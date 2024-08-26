/*
 * Mointor_Alarm.h
 *
 *  Created on: Aug 25, 2024
 *      Author: Mohamed_Ayman
 */
#ifndef MOINTOR_ALARM_H_
#define MOINTOR_ALARM_H_
#include "state.h"

//enum {
//	Alarm_Off,
//	Alarm_On
//}Alarm_State_Id;

//declare states function
state_define(Alarm_Off);
state_define(Alarm_On);


extern void (*Alarm_State_ptr) ();

#endif
