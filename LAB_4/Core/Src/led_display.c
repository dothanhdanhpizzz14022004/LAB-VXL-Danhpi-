/*
 * led_display.c
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */


#include "led_display.h"

int status1 = RED_STATUS;
int status2 = GREEN_STATUS;

int red_time = 5;
int yellow_time = 2;
int green_time = 3;
int statement = 1;
int counter_traffic = 0;
int time1, time2;

void display_segment_1(int number){
	switch(number){
		case 0:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_6, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2|GPIO_PIN_5, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
			break;
	}
}

void display_segment_2(int number){
	switch(number){
		case 0:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_13, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9|GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			break;
	}
}

void led_init(void){
	time1 = red_time;
	time2 = green_time;
	status1 = RED_STATUS;
	status2 = GREEN_STATUS;
	statement = 1;
	counter_traffic = 0;
}

void segment_display(void){
	statement *= -1;
	counter_traffic++;
	if(statement == 1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10|GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11|GPIO_PIN_13, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10|GPIO_PIN_12, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11|GPIO_PIN_13, GPIO_PIN_RESET);
	}
}

void led(void){
	segment_display();
	if(counter_traffic >= 2){
		counter_traffic = 0;
		time1--;
		time2--;
	}
	switch (status1) {
		case RED_STATUS:
			if(statement == 1){
				display_segment_1(time1 / 10);
			}
			else{
				display_segment_1(time1 % 10);
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
			if(time1 <= 0){
				status1 = GREEN_STATUS;
				time1 = green_time;
			}
			break;
		case GREEN_STATUS:
			if(statement == 1){
				display_segment_1(time1 / 10);
			}
			else{
				display_segment_1(time1 % 10);
				}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_SET);
			if(time1 <= 0){
				status1 = YELLOW_STATUS;
				time1 = yellow_time;
			}
			break;
		case YELLOW_STATUS:
			if(statement == 1){
				display_segment_1(time1 / 10);
			}
			else{
				display_segment_1(time1 % 10);
				}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_6, GPIO_PIN_SET);
			if(time1 <= 0){
				status1 = RED_STATUS;
				time1 = red_time;
			}
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
			break;
	}

	switch (status2) {
		case RED_STATUS:
			if(statement == 1){
				display_segment_2(time2 / 10);
			}
			else{
				display_segment_2(time2 % 10);
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
			if(time2 <= 0){
				status2 = GREEN_STATUS;
				time2 = green_time;
			}
			break;
		case GREEN_STATUS:
			if(statement == 1){
				display_segment_2(time2 / 10);
			}
			else{
				display_segment_2(time2 % 10);
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8, GPIO_PIN_SET);
			if(time2 <= 0){
				status2 = YELLOW_STATUS;
				time2 = yellow_time;
			}
			break;
		case YELLOW_STATUS:
			if(statement == 1){
				display_segment_2(time2 / 10);
			}
			else{
				display_segment_2(time2 % 10);
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_9, GPIO_PIN_SET);
			if(time2 <= 0){
				status2 = RED_STATUS;
				time2 = red_time;
			}
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
			break;
	}
}

void default_led(void){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}

void red_setting(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
	segment_display();
	if(statement == 1){
		display_segment_1(mode/10);
	}
	else{
		display_segment_1(mode%10);
	}
	if(statement == 1){
		display_segment_2(duration/10);
	}
	else{
		display_segment_2(duration%10);
	}
}

void yellow_setting(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_9, GPIO_PIN_SET);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	segment_display();
	if(statement == 1){
		display_segment_1(mode/10);
	}
	else{
		display_segment_1(mode%10);
	}
	if(statement == 1){
		display_segment_2(duration/10);
	}
	else{
		display_segment_2(duration%10);
	}
}

void green_setting(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_8|GPIO_PIN_7, GPIO_PIN_SET);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
	segment_display();
	if(statement == 1){
		display_segment_1(mode/10);
	}
	else{
		display_segment_1(mode%10);
	}
	if(statement == 1){
		display_segment_2(duration/10);
	}
	else{
		display_segment_2(duration%10);
	}
}
