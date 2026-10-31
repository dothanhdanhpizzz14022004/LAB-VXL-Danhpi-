#include "timer.h"

static int timer_counter[NO_OF_TIMERS];
static volatile uint8_t timer_flag[NO_OF_TIMERS];

void setTimer(int idx, int ms){
    int c = ms / TIMER_CYCLE;
    timer_counter[idx] = (c > 0) ? c : 1;
    timer_flag[idx] = 0;
}

uint8_t isTimerExpired(int idx){
    if(timer_flag[idx]){
        timer_flag[idx] = 0;
        return 1;
    }
    return 0;
}

void timer_run(void){
    for(int i = 0; i < NO_OF_TIMERS; i++){
        if(timer_counter[i] > 0){
            timer_counter[i]--;
            if(timer_counter[i] == 0) timer_flag[i] = 1;
        }
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    if(htim->Instance == TIM2) timer_run();
}
