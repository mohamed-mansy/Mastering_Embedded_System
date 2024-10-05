/*
 * Utils.h
 *
 *  Created on: Oct 5, 2024
 *      Author: Administrator
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(Reg, bit) Reg |= (1 << bit)

#define CLEAR_BIT(Reg, bit) Reg &= ~(1 << bit)

#define TOGGLE_BIT(Reg, bit) Reg ^= (1 << bit)

#define READ_BIT(Reg, bit) ((Reg >> bit) & 1)

#endif /* UTILS_H_ */
