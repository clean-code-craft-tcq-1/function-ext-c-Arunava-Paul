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
			if(Cyc_aptr[idx_f] != NULL_PTR)
			{
				(*Cyc_aptr[idx_f])();
			}
			idx_f++;
			if(idx_f == MAX_FG_TASK)
			{
				idx_f = 0; //Initialize the index
			}
		}/*end of if(counter_elapsed() == TRUE)*/
		else
		{
			if(Bg_aptr[idx_b]!=NULL_PTR)
			{
				//call the function
				(*Bg_aptr[idx_b])();
			}
			idx_b++;
			if(idx_b == MAX_BG_TASK)
			{
				idx_b = 0; //Initialize the index
			}
		}/*end of else*/
	}
}/*end of Fc_Cyclic_task*/
