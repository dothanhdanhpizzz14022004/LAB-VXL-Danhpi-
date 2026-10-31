/*
 * led_dislay.h
 *
 *  Created on: Oct 17, 2025
 *      Author: ADMIN
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#define RED_STATUS 1
#define YELLOW_STATUS 2
#define GREEN_STATUS 3

#include "global.h"

void display_segment_1(int number);
void display_segment_2(int number);

void segment_display(void);
void led_init(void);
void led(void);
void default_led(void);
void red_setting(void);
void yellow_setting(void);
void green_setting(void);

#endif /* INC_LED_DISPLAY_H_ */
