/*
 * timer.c
 *
 *  Created on: Nov 11, 2025
 *      Author: ADMIN
 */


#include "timer.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		SCH_Update();
	}
}
