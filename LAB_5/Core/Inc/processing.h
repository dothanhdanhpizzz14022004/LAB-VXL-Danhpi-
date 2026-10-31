/*
 * processing.h
 *
 *  Created on: Nov 26, 2025
 *      Author: ADMIN
 */

#ifndef INC_PROCESSING_H_
#define INC_PROCESSING_H_

#include "main.h"
#include "string.h"
#include "timer.h"
#include "stdio.h"

#define MAX_BUFFER_SIZE 30

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

extern volatile uint8_t temp;
extern volatile uint8_t buffer_flag;
extern uint8_t buffer[MAX_BUFFER_SIZE];

void command_parser_fsm();
void uart_communiation_fsm ();

#endif /* INC_PROCESSING_H_ */
