/*
 * DC.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"

//enum{
//	DC_idle,
//	DC_busy
//}DC_state_id;

//declare states function
//instead of write this=> void st_DC_Wating();
state_define(DC_idle);
state_define(DC_busy);

void DC_init();

//state pointer to function
extern void (*DC_state_ptr)();

#endif /* DC_H_ */
