/*
 * state.h
 *
 *  Created on: Aug 15, 2024
 *      Author: Administrator
 */

#ifndef STATE_H_
#define STATE_H_
#include <stdio.h>
#include <stdlib.h>

//Automatic states function generated
#define state_define(__stateFun__) void ST_##__stateFun__()

//To replace the name of the function
#define state(__stateFun__) ST_##__stateFun__

//States Connection => to interface module and another module
void US_Set_Distance(int d);
void DC_motor(int s);

#endif /* STATE_H_ */
