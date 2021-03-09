/*
 * BMS_Cyclic_Task.h
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_CYCLIC_TASK_H_
#define BMS_CYCLIC_TASK_H_

extern void Fc_Cyclic_task(void);
extern void fc_Task_Index_Handler(int *cyc_idx, int *bg_idx);

#define NULL_PTR  (void*)0
typedef void (*CyclicTask_funcptrarray)(void);
typedef void (*BckTask_funcptrarray)(void);


#endif /* BMS_CYCLIC_TASK_H_ */
