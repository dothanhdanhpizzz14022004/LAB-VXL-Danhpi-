#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

#define RED_STATUS    1
#define YELLOW_STATUS 2
#define GREEN_STATUS  3

extern int red_time;
extern int yellow_time;
extern int green_time;

void display_segment_1(int number);
void display_segment_2(int number);

void update_buffer1(int v);
void update_buffer2(int v);

void led_init(void);
void mode_run(void);
void display_scan(void);

#endif /* INC_LED_DISPLAY_H_ */
