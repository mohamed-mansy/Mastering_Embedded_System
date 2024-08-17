/*
 * US.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */

#ifndef US_H_
#define US_H_
#include "state.h"

//enum{
//	US_Busy
//}US_state_id;

//declare states function
//instead of write this=> void st_US_Wating();
state_define(US_Busy);

void US_init();

//state pointer to function
extern void (*US_state_ptr)();

#endif /* US_H_ */
