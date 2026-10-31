/*
 * processing.c
 *
 *  Created on: Nov 26, 2025
 *      Author: ADMIN
 */


#include "processing.h"

volatile uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE] = {0};
char str[MAX_BUFFER_SIZE] = {0};
uint8_t index_buffer = 0;
volatile uint8_t buffer_flag = 0;
uint32_t ADCValue = 0;
enum FrameRecieve {IDLE, RECORD};
enum CmdProcessing {REQUEST, PROCESS, RESPOND};

void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart){
	if(huart -> Instance == USART2){
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, (uint8_t*)&temp, 1);
	}
}

enum FrameRecieve parser_state = IDLE;
void command_parser_fsm(){
	switch (parser_state){
		case IDLE:
			if(temp == '!'){
				parser_state = RECORD;
				index_buffer = 0;
				for(int i=0; i<MAX_BUFFER_SIZE; i++){
					buffer[i] = 0;
				}
			}
			break;
		case RECORD:
			if(temp == '#'){
				buffer[index_buffer] = '\0';
				parser_state = IDLE;
			}
			else{
				buffer[index_buffer] = temp;
				index_buffer++;
				if(index_buffer >= 30){
					index_buffer = 0;
				}
			}
			break;
		default:
			break;
	}
}

enum CmdProcessing cmd_state = REQUEST;
void uart_communiation_fsm(){
	switch(cmd_state){
		case REQUEST:
			if (strcmp((char *)buffer, "RST") == 0){
				cmd_state = PROCESS;
				ADCValue = HAL_ADC_GetValue(&hadc1);
			}
			break;
		case PROCESS:
			cmd_state = RESPOND;
			HAL_UART_Transmit(&huart2, (uint8_t *)str , sprintf((char *)str,"!ADC=%lu#\n", ADCValue), 1000);
			setTimer1(3000);
			break;
		case RESPOND:
			if(strcmp((char *)buffer, "OK") == 0){
				cmd_state = REQUEST;
			}
			if(timer1_flag == 1){
				cmd_state = PROCESS;
			}
	}
}
