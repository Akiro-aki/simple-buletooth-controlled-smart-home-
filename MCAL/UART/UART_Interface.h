/*
 * UART_int.h
 *
 *  Created on: May 24, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*Parity Options*/
#define NO_PARITY			0
#define EVEN_PARITY			1
#define ODD_PARITY			2

/*Stop bits options*/
#define ONE_STOP_BIT		0
#define TWO_STOP_BIT		1

/*Data bits options*/
#define DATA_BITS_5			0
#define DATA_BITS_6			1
#define DATA_BITS_7			2
#define DATA_BITS_8			3
#define DATA_BITS_9			4

/*baud rate options*/
/*in case of normal speed*/
#define BAUD_9600_F_8		51
/*in case of Double speed*/
#define BAUD_9600_F_8_D		103

/*Mode Options*/
/*Synchronization*/
#define UART_ASYNCH			0
#define UART_SYNCH			1
/*Speed */
#define NORMAL_SPEED		0
#define DOUBLE_SPEED		1

void UART_Init(void);

void UART_SetParity(u8 parity);
void UART_SetStopBits(u8 noOfStopBits);
void UART_SetDataBits(u8 noOfDataBits);
void UART_SetBaudRate(u16 baud);
void UART_SetMode(u8 synchMode, u8 speed);


void UART_TransmitData(u16 data);
u16 UART_ReceiveData(void);


void UART_EnableTx(void);
void UART_DisableTx(void);
void UART_EnableRx(void);
void UART_DisableRx(void);
void UART_EnableTxInterrupt(void);
void UART_DisableTxInterrupt(void);
void UART_EnableRxInterrupt(void);
void UART_DisableRxInterrupt(void);
void UART_EnableDataEmptyInterrupt(void);
void UART_DisableDataEmptyInterrupt(void);


//
//void UART_Init();
//void UART_Send_Char(u8 data);
//u8 UART_Recive_Char();

#endif /* MCAL_UART_UART_INT_H_ */
