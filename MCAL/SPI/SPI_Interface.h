/*
 * SPI_init.h
 *
 *  Created on: May 25, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_

///*
// * 1- Select which bit to send first 	"Options -> Configuration"
// * 2- Select Master or Slave			"Options -> Configuration"
// * 3- Select Clock Polarity				"Options -> Configuration"
// * 4- Select Clock Phase				"Options -> Configuration"
// * 5- Select Pre-scaler					"Options -> Configuration"
// * 6- Enable SPI
// * */
//void SPI_Init(void);
//
//
///*
// * 1- busy wait on write collision flag
// * 2- add data to data register
// * 3- busy wait on SPI Operation flag
// * 4- read data from the data register
// * */
//u8 SPI_Tranceive(u8 data);


#define LSB    0
#define MSB    1

#define  MASTER 0
#define  SLAVE  1

#define RAISING 0
#define FALLING 1

#define SAMPLE  0
#define SETUP   1

void SPI_INIT(void);

void SPI_TRAS_RECIVE(u8 DATA, u8* recive);

/*
 * Set enable bit
 * */
void SPI_Enable(void);

/*
 * Clear enable bit
 * */
void SPI_Disable(void);

#endif /* MCAL_SPI_SPI_INIT_H_ */
