/*
 * input_processing.c
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */


#include "input_processing.h"


enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState[3] = {BUTTON_RELEASED};


int mode = 1;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int duration = 1;
uint8_t button1Flag = 0;
uint8_t button3Flag = 0;

void fsm_for_input_processing(void){
	for(int i=0; i<3; i++){
		switch(buttonState[i]){
			case BUTTON_RELEASED:
				if(is_button_pressed(i)){
					buttonState[i] = BUTTON_PRESSED;
					switch (i){
						case 0:
							mode++;
							duration = 1;
							button1Flag = 1;
							if(mode>4){
								mode = 1;
							}
							break;
						case 1:
							duration++;
							if(duration > 99){
								duration = 1;
							}
							break;
						case 2:
							switch (mode){
								case 2:
									red_time = duration;
									break;
								case 3:
									yellow_time = duration;
									break;
								case 4:
									green_time = duration;
									break;
								default:
									break;
							}
							button3Flag = 1;
							break;
							default:
								break;
					}
				}
				break;
			case BUTTON_PRESSED:
				if(!is_button_pressed(i)){
					buttonState[i] = BUTTON_RELEASED;
					switch (i){
						case 0:
							button1Flag = 0;
							break;
						default:
							break;
					}
				}
				else{
					if(is_button_pressed_1s(i)){
						buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
						switch (i){
							case 0:
								counter1 = 0;
								break;
							case 1:
								counter2 = 0;
								break;
							case 2:
								counter3 = 0;
								break;
						}
					}
				}
				break;
			case BUTTON_PRESSED_MORE_THAN_1_SECOND:
				if(!is_button_pressed(i)){
					buttonState[i] = BUTTON_RELEASED;
					if(i == 0){
						button1Flag = 0;
					}
					break;
				}
				else{
					switch (i){
						case 0:
							counter1--;
							if(counter1 <=0){
								counter1 = 50;
								mode++;
								duration = 1;
								if(mode>4){
									mode = 1;
								}
								button1Flag = 1;
							}
							break;
						case 1:
							counter2--;
							if(counter2 <= 0){
								counter2 = 50;
								duration++;
								if(duration > 99){
									duration = 1;
								}
							}
							break;
						case 2:
							counter3--;
							if(counter3 <= 0){
								counter3 = 50;
								switch (mode){
									case 2:
										red_time = duration;
										break;
									case 3:
										yellow_time = duration;
										break;
									case 4:
										green_time = duration;
										break;
									default:
										break;
								}
							}
					}
				}
		}
	}
}


