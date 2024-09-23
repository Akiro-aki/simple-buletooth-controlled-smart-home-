/*
 * BLTH_Program.c
 *
 *  Created on: Aug 14, 2024
 *      Author: walid
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/UART/UART_Config.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/UART/UART_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Config.h"
#include "BLTH_Config.H"
#include "BLTH_Interface.H"
#include <util/delay.h>
//#include "../../LIB/BIT_MATH.h"
//#include "../../LIB/STD_TYPES.h"
//#include "UART_Config.h"
//#include "UART_Interface.h"
//#include "UART_Private.h"

void BLTH_Init(void)
{
  UART_Init();
}

void BLTH_SendData(u8 data)
{
    UART_TransmitData(data);
}

u8 BLTH_ReceiveData(void)
{
    return UART_ReceiveData();
}

void BLTH_SendString(u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		BLTH_SendData(str[i]);
		_delay_ms(100);
		i++;
	}
}


