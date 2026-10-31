#include "led_display.h"
#include "timer.h"
#include "input_processing.h"

static int status1 = RED_STATUS;
static int status2 = GREEN_STATUS;
static int time1, time2;

int red_time    = 5;
int yellow_time = 2;
int green_time  = 3;

static int buf1[2], buf2[2];

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

void update_buffer1(int v){ buf1[0] = v / 10; buf1[1] = v % 10; }
void update_buffer2(int v){ buf2[0] = v / 10; buf2[1] = v % 10; }


void display_scan(void){
    static uint8_t idx = 0;
    if(!isTimerExpired(TIMER_SCAN)) return;
    setTimer(TIMER_SCAN, 10);

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_SET);
    display_segment_1(buf1[idx]);
    display_segment_2(buf2[idx]);
    HAL_GPIO_WritePin(GPIOA, idx == 0 ? (GPIO_PIN_10|GPIO_PIN_12)
                                      : (GPIO_PIN_11|GPIO_PIN_13), GPIO_PIN_RESET);
    idx ^= 1;
}


static void set_light1(int s){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_SET);
    if(s == RED_STATUS)         HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    else if(s == YELLOW_STATUS) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    else if(s == GREEN_STATUS)  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}
static void set_light2(int s){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
    if(s == RED_STATUS)         HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
    else if(s == YELLOW_STATUS) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    else if(s == GREEN_STATUS)  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
}

static int next_status(int s){
    return (s == RED_STATUS) ? GREEN_STATUS :
           (s == GREEN_STATUS) ? YELLOW_STATUS : RED_STATUS;
}
static int status_time(int s){
    return (s == RED_STATUS) ? red_time :
           (s == GREEN_STATUS) ? green_time : yellow_time;
}


static void traffic_run(void){
    if(!isTimerExpired(TIMER_SECOND)) return;
    setTimer(TIMER_SECOND, 1000);

    time1--; time2--;
    if(time1 <= 0){ status1 = next_status(status1); time1 = status_time(status1); }
    if(time2 <= 0){ status2 = next_status(status2); time2 = status_time(status2); }

    set_light1(status1);
    set_light2(status2);
    update_buffer1(time1);
    update_buffer2(time2);
}

/* ---- Mode 2,3,4: nhấp nháy 2Hz ---- */
static void blink_run(uint16_t pins){
    static uint8_t on = 0;
    if(isTimerExpired(TIMER_BLINK)){
        setTimer(TIMER_BLINK, 250);
        on ^= 1;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|
                                 GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, pins, on ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
    update_buffer1(mode);       /* hiện "0x" */
    update_buffer2(duration);   /* hiện giá trị đang chỉnh */
}

void led_init(void){
    status1 = RED_STATUS;   time1 = red_time;
    status2 = GREEN_STATUS; time2 = green_time;
}

void mode_run(void){
    static int last_mode = 0;

    if(mode != last_mode){          /* vừa đổi mode: khởi tạo lại */
        last_mode = mode;
        if(mode == 1){
            status1 = RED_STATUS;   time1 = red_time;
            status2 = GREEN_STATUS; time2 = green_time;
            set_light1(status1);
            set_light2(status2);
            update_buffer1(time1);
            update_buffer2(time2);
            setTimer(TIMER_SECOND, 1000);
        } else {
            setTimer(TIMER_BLINK, 250);
        }
    }

    switch(mode){
        case 1: traffic_run(); break;
        case 2: blink_run(GPIO_PIN_4|GPIO_PIN_7); break;  /* đỏ   */
        case 3: blink_run(GPIO_PIN_5|GPIO_PIN_8); break;  /* vàng */
        case 4: blink_run(GPIO_PIN_6|GPIO_PIN_9); break;  /* xanh */
    }
}
