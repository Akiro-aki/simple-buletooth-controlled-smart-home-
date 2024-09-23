/*
 * SPI_conf.h
 *
 *  Created on: May 25, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_SPI_SPI_CONF_H_
#define MCAL_SPI_SPI_CONF_H_
//*****************WRITE_MODE******************/

//  SELECT LSB OR MSB
#define WRITE_MODE    LSB

//*****************SPI_MODE******************/

//  SELECT MASTER OR  SLAVE
#define SPI_MODE    MASTER

//*****************CLOCK_POLATITY_MODE******************/

//  SELECT RAISING OR  FALLING
#define CLOCK_POLATITY_MODE    RAISING


//*****************CLOCK_PHASE_MODE******************/

//  SELECT SETUP OR  SAMPLE
#define CLOCK_PHASE_MODE    SAMPLE

#endif /* MCAL_SPI_SPI_CONF_H_ */
