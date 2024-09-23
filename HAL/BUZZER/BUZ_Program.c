/*
 * BUZ_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: walid
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "BUZ_Config.h"
#include "BUZ_Interface.h"
#include <util/delay.h>

void Buzzer_Init(void){

	vSet_Pin_Direction(BUZZER_PORT,BUZZER_PIN,OUTPUT);

}
void Buzzer_On(void){

	vSet_Pin_OUTPUTvalue(BUZZER_PORT,BUZZER_PIN,HIGH);

}
void Buzzer_Off(void){

	vSet_Pin_OUTPUTvalue(BUZZER_PORT,BUZZER_PIN,LOW);

}
