/*
 * Timer0_Interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_TIMERS_TIMER0_INTERFACE_H_
#define MCAL_TIMERS_TIMER0_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*************************TIMER0*************************/


#define		TIMER0_SCALER_1     	 1
#define		TIMER0_SCALER_8    		 2
#define	    TIMER0_SCALER_64 		 3
#define 	TIMER0_SCALER_256        4
#define 	TIMER0_SCALER_1024       5
#define 	EXTERNALl_FALLING        6
#define 	EXTERNAL_RISING          7


#define		TIMER0_NORMAL_MODE        0
#define		TIMER0_PHASECORRECT_MODE  1
#define		TIMER0_CTC_MODE           2
#define		TIMER0_FASTPWM_MODE       3


void vTIMER0_INIT(void);

void vTIMER0_START(void);

void vTIMER0_STOP(void);

void vTIMER0_preload(u8 preload);

void vTIMER0_OV_InterruptEnable(void);

void vTIMER0_OV_InterruptDisable(void);
void vTIMER0_Compare_OCR0(u8 OCR);




#define	OC0_DISCONNECTED   0
#define	RESERVED           1
#define	OC0_NON_INVERTING  2
#define OC0_INVERTING      3


#endif /* MCAL_TIMERS_TIMER0_INTERFACE_H_ */
