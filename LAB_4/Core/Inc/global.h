/*
 * global.h
 *
 *  Created on: Nov 11, 2025
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "scheduler.h"
#include "main.h"
#include "timer.h"
#include "input_reading.h"
#include "input_processing.h"
#include "led_display.h"
#include "stdint.h"

extern int mode;
extern uint8_t button1Flag;
extern uint8_t button3Flag;
extern int duration;
extern int red_time;
extern int yellow_time;
extern int green_time;
extern int statement;
extern uint8_t current_index_task;

#endif /* INC_GLOBAL_H_ */
