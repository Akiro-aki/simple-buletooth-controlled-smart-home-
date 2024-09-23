/*
 * BLTH_Interface.h
 *
 *  Created on: Aug 14, 2024
 *      Author: walid
 */

#ifndef HAL_BLUETOOTH_BLTH_INTERFACE_H_
#define HAL_BLUETOOTH_BLTH_INTERFACE_H_

void BLTH_Init(void);
void BLTH_SendData(u8 data);
u8 BLTH_ReceiveData(void);
void BLTH_SendString(u8 *str);
#endif /* HAL_BLUETOOTH_BLTH_INTERFACE_H_ */
