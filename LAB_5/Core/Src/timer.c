/*
 * timer.c
 *
 *  Created on: Nov 26, 2025
 *      Author: ADMIN
 */

#include "timer.h"

int counter0 = 0;
uint8_t timer0_flag = 0;

int counter1 = 0;
uint8_t timer1_flag = 0;


void setTimer0(int duration) {
	counter0 = duration/TIMER_CYCLE;
	timer0_flag = 0;
}

void setTimer1(int duration) {
	counter1 = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void TimerRun() {
	if (counter0 > 0) {
		counter0--;
		if (counter0 <= 0) {
			timer0_flag = 1;
		}
	}
	if (counter1 > 0) {
		counter1--;
		if (counter1 <= 0) {
			timer1_flag = 1;
		}
	}
}

