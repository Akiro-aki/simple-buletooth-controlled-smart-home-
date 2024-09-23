/*
 * Timer0_Program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Ahmed Saber
 */
#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "Timers_Config.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void vTIMER0_INIT(void)
{
	/*1. Mode Selection*/
	switch(TIMER0_MODE)
	{
		case TIMER0_NORMAL_MODE:
			CLEAR_BIT(TCCR0,3);
			CLEAR_BIT(TCCR0,6);
			break;

		case TIMER0_PHASECORRECT_MODE:
			CLEAR_BIT(TCCR0,3);
			SET_BIT(TCCR0,6);
			break;

		case TIMER0_CTC_MODE:
			SET_BIT(TCCR0,3);
			CLEAR_BIT(TCCR0,6);
			break;

		case TIMER0_FASTPWM_MODE:
			SET_BIT(TCCR0,3);
			SET_BIT(TCCR0,6);
			break;

		default:
			/*for future use*/
			break;
	}

	/*2. Enable overflow interrupt*/
	vTIMER0_OV_InterruptEnable();

	/*3. Set initial value*/
	vTIMER0_preload(TIMER0_INITIAL_VALUE);
}

void vTIMER0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}

void vTIMER0_OV_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}

void vTIMER0_START(void)
{
	/*Select Pre-scaler*/
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER0_PRESCALLER;
}

void vTIMER0_STOP(void)
{
	TCCR0 = 0x00;
}

void vTIMER0_preload(u8 preload)
{
	TCNT0 = preload;
}
