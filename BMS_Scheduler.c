/*
 * BMS_Cyclic_Task.c
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */
#include "BMS_Common_Include.h"
#include "BMS_Scheduler.h"
#include "BMS_Scheduler_Cfg.h"
#include "BMS_Timer_module.h"

void Fc_Cyclic_task(void)
{
	static int idx_f,idx_b;
	while(1)
	{
		if(Fc_counter_elapsed() == TRUE)
		{
			Fc_start_timer();
			//call the function
			(*Cyc_aptr[idx_f])();
			idx_f++;			
		}/*end of if(counter_elapsed() == TRUE)*/
		else
		{			
			//call the function
			(*Bg_aptr[idx_b])();
			idx_b++;			
		}/*end of else*/
		fc_Task_Index_Handler(&idx_f , &idx_b);
	}
}/*end of Fc_Cyclic_task*/

void fc_Task_Index_Handler(int *cyc_idx, int *bg_idx)
{
	if(*cyc_idx == MAX_FG_TASK)
	{
		*cyc_idx = 0; //Initialize the index
	}
	if(*bg_idx == MAX_BG_TASK)
	{
		*bg_idx = 0; //Initialize the index
	}
}/*end of fc_Task_Index_Handler*/
