/*
 * Timer0_Private.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Ahmed Saber
 */

#ifndef MCAL_TIMERS_TIMER0_PRIVATE_H_
#define MCAL_TIMERS_TIMER0_PRIVATE_H_

/*************************TIMER0*************************/
/* Timer 0 */
#define TCNT0   (*(volatile u8*)0x52)
#define TCCR0   (*(volatile u8*)0x53)
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TIFR    (*(volatile u8*)0x58)
#define TIMSK   (*(volatile u8*)0x59)
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

#define TWCR    (*(volatile u8*)0x56)
#define SPMCR   (*(volatile u8*)0x57)
#define OCR0    (*(volatile u8*)0x5C)

#endif /* MCAL_TIMERS_TIMER0_PRIVATE_H_ */
