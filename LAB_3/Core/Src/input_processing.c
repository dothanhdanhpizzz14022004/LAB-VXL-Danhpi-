#include "input_processing.h"
#include "led_display.h"      /* red_time, yellow_time, green_time */

#define BUTTON_PERIOD  10                      /* ms, = chu kỳ TIMER_BUTTON */
#define AUTO_REPEAT    (500 / BUTTON_PERIOD)   /* tự lặp mỗi 0.5s khi giữ nút */

enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND };
static enum ButtonState buttonState[NO_OF_BUTTONS] = { BUTTON_RELEASED };
static int repeat_counter[NO_OF_BUTTONS];

int mode = 1;
int duration = 1;

/* ---- 3 hành động tương ứng 3 nút ---- */
static void action_change_mode(void){
    mode++;
    if(mode > 4) mode = 1;
    duration = 1;
}

static void action_increase(void){
    duration++;
    if(duration > 99) duration = 1;
}

static void action_set(void){
    switch(mode){
        case 2: red_time    = duration; break;
        case 3: yellow_time = duration; break;
        case 4: green_time  = duration; break;
        default: break;
    }
}

static void do_action(int i){
    switch(i){
        case 0: action_change_mode(); break;
        case 1: action_increase();    break;
        case 2: action_set();         break;
        default: break;
    }
}

/* ---- FSM chung cho cả 3 nút ---- */
void fsm_for_input_processing(void){
    for(int i = 0; i < NO_OF_BUTTONS; i++){
        switch(buttonState[i]){

            case BUTTON_RELEASED:
                if(is_button_pressed(i)){
                    buttonState[i] = BUTTON_PRESSED;
                    do_action(i);                      /* nhấn 1 lần */
                }
                break;

            case BUTTON_PRESSED:
                if(!is_button_pressed(i)){
                    buttonState[i] = BUTTON_RELEASED;
                }
                else if(is_button_pressed_1s(i)){
                    buttonState[i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                    repeat_counter[i] = AUTO_REPEAT;   /* bắt đầu đếm 0.5s */
                }
                break;

            case BUTTON_PRESSED_MORE_THAN_1_SECOND:
                if(!is_button_pressed(i)){
                    buttonState[i] = BUTTON_RELEASED;
                }
                else{
                    if(--repeat_counter[i] <= 0){
                        repeat_counter[i] = AUTO_REPEAT;
                        do_action(i);                  /* tự lặp mỗi 0.5s */
                    }
                }
                break;
        }
    }
}
