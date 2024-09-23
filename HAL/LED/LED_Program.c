/*
 * LED_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: walid
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include <util/delay.h>

void LED_Init(void){
	vSet_Pin_Direction(LED_PORT,LED_PIN,OUTPUT);
}
void LED_On(void){
	vSet_Pin_OUTPUTvalue(LED_PORT,LED_PIN,HIGH);
}
void LED_Off(void){
	vSet_Pin_OUTPUTvalue(LED_PORT,LED_PIN,LOW);
}
