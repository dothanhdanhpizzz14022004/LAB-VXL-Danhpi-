/*
 * scheduler.h
 *
 *  Created on: Nov 10, 2025
 *      Author: ADMIN
 */

#ifndef APP_SCHEDULER_H_
#define APP_SCHEDULER_H_

#include <stdint.h>

#define SCH_MAX_TASKS 10

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;

	uint32_t TaskID;
}sTasks;

void SCH_Init(void);

void SCH_Add_Task (void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(uint8_t TASK_INDEX);
#endif /* APP_SCHEDULER_H_ */
