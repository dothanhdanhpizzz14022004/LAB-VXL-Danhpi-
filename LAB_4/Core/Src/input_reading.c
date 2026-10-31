/*
 * input_reading.c
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */


#include "input_reading.h"

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];


void button_init(void){
	for(char i = 0; i < NO_OF_BUTTONS; i++){
		buttonBuffer[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		flagForButtonPress1s[i] = 0;
		counterForButtonPress1s[i] = 0;
	}
}


void button_reading(void){
	for(char i=0; i<NO_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		switch (i){
			case 0:
				debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
				break;
			case 1:
				debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
				break;
			case 2:
				debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
				break;
		}

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				}
				else{
					flagForButtonPress1s[i] = 1;
				}
			}
			else{
				flagForButtonPress1s[i] = 0;
				counterForButtonPress1s[i] = 0;
			}
		}
	}
}


unsigned char is_button_pressed(uint8_t index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}


unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}

