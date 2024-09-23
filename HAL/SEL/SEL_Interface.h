/*
 * SEL_Interface.h
 *
 *  Created on: Aug 13, 2024
 *      Author: walid
 */

#ifndef HAL_SEL_SEL_INTERFACE_H_
#define HAL_SEL_SEL_INTERFACE_H_

#include "SEL_Config.h"

// Public function declarations
void SEL_Init(void);
//void SEL_SetPower(int power);
//int SEL_GetPower(void);
void SEL_On(void);   // Turn the solenoid on
void SEL_Off(void);  // Turn the solenoid off

#endif /* HAL_SEL_SEL_INTERFACE_H_ */
