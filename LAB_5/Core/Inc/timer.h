/*
 * timer.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_CYCLE 10

#include "main.h"

extern uint8_t timer0_flag;
extern uint8_t timer1_flag;
void setTimer0(int duration);
void setTimer1(int duration);
void TimerRun();

#endif /* INC_TIMER_H_ */
