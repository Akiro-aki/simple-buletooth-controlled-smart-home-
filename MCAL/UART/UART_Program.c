/*
 * UART_prog.c
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_Private.h"


void UART_Init(void)
{
	/*1- Set Baud Rate*/
	UART_SetBaudRate(BOUD_RATE);

	/*Select UCSRC*/
	SET_BIT(UCSRC,URSEL);
	/*2- Select mode*/
	UART_SetMode(OPERATION_MODE,SPEED_MODE);

	/*3- select Data bits*/
	UART_SetDataBits(DATA_BITS);

	/*4- select Parity bits*/
	UART_SetParity(PARITY);

	/*5- select stop bits*/
	UART_SetStopBits(STOP_BITS);

	/*6- enable Tx*/
	UART_EnableTx();

	/*7- enable Rx*/
	UART_EnableRx();

	/*8- Disable all interrupts*/
	UART_DisableTxInterrupt();
	UART_DisableRxInterrupt();
	UART_DisableDataEmptyInterrupt();
}

void UART_SetParity(u8 parity)
{
	switch(parity)
	{
		case NO_PARITY:
			CLEAR_BIT(UCSRC,UPM0);
			CLEAR_BIT(UCSRC,UPM1);
			break;
		case EVEN_PARITY:
			CLEAR_BIT(UCSRC,UPM0);
			SET_BIT(UCSRC,UPM1);
			break;
		case ODD_PARITY:
			SET_BIT(UCSRC,UPM0);
			SET_BIT(UCSRC,UPM1);
			break;
		default:
			/*error handling*/
			break;
	}
}

void UART_SetStopBits(u8 noOfStopBits)
{
	switch(noOfStopBits)
	{
		case ONE_STOP_BIT:
			CLEAR_BIT(UCSRC,USBS);
			break;
		case TWO_STOP_BIT:
			SET_BIT(UCSRC,USBS);
			break;
		default:
			/*error handling*/
			break;
	}
}

void UART_SetDataBits(u8 noOfDataBits)
{
	switch(noOfDataBits)
	{
		case DATA_BITS_5:

				break;
		case DATA_BITS_6:

			break;
		case DATA_BITS_7:

				break;
		case DATA_BITS_8:
			SET_BIT(UCSRC,UCSZ0);
			SET_BIT(UCSRC,UCSZ1);
			CLEAR_BIT(UCSRB,UCSZ2);
			break;
		case DATA_BITS_9:

			break;
		default:
			/*error handling*/
			break;
	}
}

void UART_SetBaudRate(u16 baud)
{
	UBRRL = (u8) baud;

	if(baud > 255)
	{
		CLEAR_BIT(UCSRC,URSEL);
		UBRRH = (u8)(baud >> 8);
	}
}

void UART_SetMode(u8 synchMode, u8 speed)
{
	switch(speed)
	{
		case NORMAL_SPEED:
			CLEAR_BIT(UCSRA,U2X);
			break;

		case DOUBLE_SPEED:
			SET_BIT(UCSRA,U2X);
			break;

		default :
			/*error handling*/
			break;
	}

	switch(synchMode)
	{
		case UART_ASYNCH:
			CLEAR_BIT(UCSRC,UMSEL);
			break;

		case UART_SYNCH:
			SET_BIT(UCSRC,UMSEL);
			break;

		default :
			/*error handling*/
			break;
	}
}

void UART_TransmitData(u16 data)
{
	/*1- Polling on the data register empty flag*/
	while(!GET_BIT(UCSRA,UDRE));

	/*2- Add the 1st 8-bits to the UDR*/
	UDR = data;

	/*3- Checking if the mode use 9-bits data mode*/
	if(DATA_BITS == DATA_BITS_9)
	{
		/*get the ninth bit (index 8) of the data*/
		if(GET_BIT(data,8) == 1)
		{
			SET_BIT(UCSRB,TXB8);
		}
		else
		{
			CLEAR_BIT(UCSRB,TXB8);
		}
	}
}

u16 UART_ReceiveData(void)
{
	/*1- define a variable to be returned*/
	u16 retData = 0;

	/*2- Poll on the RX complete flag*/
	while(GET_BIT(UCSRA,RXC)==0);

	/*3- read the 1st 8-bits data from UDR Register*/
	retData = UDR;

	/*4- check if the mode is 9-bits data mode*/
	if(DATA_BITS == DATA_BITS_9)
	{
		/*5- get the value of the bit*/
		if(GET_BIT(UCSRB,RXB8) == 1)
		{
			SET_BIT(retData,8);
		}
		else
		{
			CLEAR_BIT(retData,8);
		}
	}

	return retData;
}

void UART_EnableTx(void)
{
	SET_BIT(UCSRB,TXEN);
}

void UART_DisableTx(void)
{
	CLEAR_BIT(UCSRB,TXEN);
}

void UART_EnableRx(void)
{
	SET_BIT(UCSRB,RXEN);
}

void UART_DisableRx(void)
{
	CLEAR_BIT(UCSRB,RXEN);
}

void UART_EnableTxInterrupt(void)
{

}

void UART_DisableTxInterrupt(void)
{

}

void UART_EnableRxInterrupt(void)
{

}

void UART_DisableRxInterrupt(void)
{

}

void UART_EnableDataEmptyInterrupt(void)
{

}

void UART_DisableDataEmptyInterrupt(void)
{

}


















//
//void UART_Init()
//{
//	// 2D speed
//	if(SPEED_MODE==NOT_SET_2DS)
//	{
//		CLEAR_BIT(UCSRA,U2X);
//	}
//	else if(SPEED_MODE==SET_2DS)
//	{
//		SET_BIT(UCSRA,U2X);
//	}
//
//	// select baud rate
//	UBRRL=BOUD_RATE;
//
//	u8 UCSRC_var=0x00;
//	//SELECT PARITY
//	if(PARITY_MODE==DISSABLE_PARITY){
//		CLEAR_BIT(UCSRC_var,UPM0);
//		CLEAR_BIT(UCSRC_var,UPM1);
//
//	}
//	else if(PARITY_MODE==EVEN_PARITY){
//		CLEAR_BIT(UCSRC_var,UPM0);
//		SET_BIT(UCSRC_var,UPM1);
//
//	}
//	else if(PARITY_MODE==ODD_PARITY){
//		SET_BIT(UCSRC_var,UPM0);
//		SET_BIT(UCSRC_var,UPM1);
//	}
//
//
//	// select stop
//	if(SELECT_STOP==ONE_STOP)
//	{
//		CLEAR_BIT(UCSRC_var,USBS);
//	}
//	else if(SELECT_STOP==TWO_STOP)
//	{
//		SET_BIT(UCSRC_var,USBS);
//	}
//
//	//SELECT# of bit
//	if(SELECT_NUM_BIT==BIT_8)
//	{
//		SET_BIT(UCSRC_var,UCSZ0);
//		SET_BIT(UCSRC_var,UCSZ1);
//		CLEAR_BIT(UCSRB,UCSZ2);
//	}
//
//	//ASENCH
//	CLEAR_BIT(UCSRC_var,UMSEL);
//
//	/*Select UCSRC reg*/
//	//CLEAR_BIT(UCSRC,URSEL);
//	UCSRC = UCSRC_var;
//
//	//enable tx
//	SET_BIT(UCSRB,TXEN);
//	//vSet_Pin_Direction(PORT_D,PIN_1,OUTPUT);
//
//	//enable rx
//	SET_BIT(UCSRB,RXEN);
//	//vSet_Pin_Direction(PORT_D,PIN_0,INPUT);
//}
//
//void UART_Send_Char(u8 data)
//{
//	while(!GET_BIT(UCSRA,UDRE));
//	UDR=data;
//}
//
//u8 UART_Recive_Char(void)
//{
//	while(GET_BIT(UCSRA,RXC)==0);
//	return UDR;
//}
