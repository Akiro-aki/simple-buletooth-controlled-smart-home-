
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"


void SPI_INIT(void)
{
	/*1- SELECT LSB or MSB*/
	#if WRITE_MODE==LSB
		SET_BIT(SPCR,DORD);
	#elif WRITE_MODE==MSB
		CLEAR_BIT(SPCR,DORD);
	#endif

	/*2- SELECT MASTER or Slave	*/
	#if SPI_MODE ==	MASTER
		SET_BIT(SPCR,MSTR);
	#elif SPI_MODE == SLAVE
		CLEAR_BIT(SPCR,MSTR);
	#endif


	/*3- SELECT CLOCK POLARITY*/
	#if CLOCK_POLATITY_MODE == RAISING
		CLEAR_BIT(SPCR,CPOL);
	#elif  CLOCK_POLATITY_MODE == FALLING
		SET_BIT(SPCR,CPOL);
	#endif


	/*4- SELECT CLOCK PHASE*/
	#if CLOCK_PHASE_MODE == SAMPLE
		CLEAR_BIT(SPCR,CPHA);
	#elif  CLOCK_PHASE_MODE == SETUP
		SET_BIT(SPCR,CPHA);
	#endif



	/*SELECT D2S*/
	/*5- SELECT CLOCK, Double or normal*/
	SET_BIT(SPCR,SPR0);
	CLEAR_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);


	/*6- ENABLE SPI*/
	SPI_Enable();
}


void SPI_TRAS_RECIVE(u8 DATA ,u8 *recive)
{
	if(recive != NULLPTR)
	{
		// * 1- busy wait on write collision flag
		/*WRITE COLLISION wait to avoid write collision*/
		while( GET_BIT(SPSR , WCOL));

		// * 2- add data to data register
		/* SPDR= DATA*/
		SPDR = DATA;

		// * 3- busy wait on SPI Operation flag
		/*BUST WAIT FLAG*/
		while(GET_BIT(SPSR,SPIF)==0);

		// * 4- read data from the data register
		*recive = SPDR;
	}
	else
	{
		/*error handling*/
	}
}

/*
* Set enable bit
* */
void SPI_Enable(void)
{
	SET_BIT(SPCR,SPE);
}

/*
* Clear enable bit
* */
void SPI_Disable(void)
{
	CLEAR_BIT(SPCR,SPE);
}
