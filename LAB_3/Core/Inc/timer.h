#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

#define TIMER_CYCLE   10
#define NO_OF_TIMERS  4

#define TIMER_BUTTON  0
#define TIMER_SCAN    1
#define TIMER_BLINK   2
#define TIMER_SECOND  3

extern TIM_HandleTypeDef htim2;

void    setTimer(int idx, int ms);
uint8_t isTimerExpired(int idx);
void    timer_run(void);

#endif
