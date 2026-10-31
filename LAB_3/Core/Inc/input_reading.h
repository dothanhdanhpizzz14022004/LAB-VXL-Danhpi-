#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#define NO_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
#define DURATION_FOR_AUTO_INCREASING 100

#include "main.h"

void button_init(void);

void button_reading(void);

unsigned char is_button_pressed(unsigned char index);

unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
