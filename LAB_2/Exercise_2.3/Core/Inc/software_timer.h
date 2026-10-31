/*
 * software_timer.h
 *
 *  Created on: Sep 20, 2025
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_s
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void timeRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
