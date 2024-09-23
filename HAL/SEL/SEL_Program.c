/*
 * SEL_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: walid
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "SEL_Config.h"
#include "SEL_Interface.h"
#include <util/delay.h>

void SEL_Init(void){

  vSet_Pin_Direction(SOLENOID1_PORT,SOLENOID1_PIN,OUTPUT);

}

void SEL_On(void){

   vSet_Pin_OUTPUTvalue(SOLENOID1_PORT,SOLENOID1_PIN,HIGH);

}

void SEL_Off(void){

   vSet_Pin_OUTPUTvalue(SOLENOID1_PORT,SOLENOID1_PIN,LOW);
//   _delay_ms(15000);
//   vSet_Pin_OUTPUTvalue(SOLENOID1_PORT,SOLENOID1_PIN,HIGH);
}
