/*
 * CA.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"

//enum{
//	CA_Wating,
//	CA_Driving
//}CA_state_id;

//declare states function
//instead of write this=> void st_CA_Wating();
state_define(CA_Wating);
state_define(CA_Driving);

//state pointer to function
extern void (*CA_state_ptr)();

#endif /* CA_H_ */
