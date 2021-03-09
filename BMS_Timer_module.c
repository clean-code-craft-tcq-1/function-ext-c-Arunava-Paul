/*
 * BMS_Timer_module.c
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */
#include "BMS_Common_Include.h"
#include "time.h"
#include "BMS_Timer_module.h"

clock_t timestamp_start;

void Fc_start_timer(void)
{
	timestamp_start = clock();
}/*end of Fc_start_timer*/

int Fc_counter_elapsed(void)
{
	clock_t timestamp_current = clock();
	if( Fc_time_difference(timestamp_current) >= 500 )
		return TRUE;
	else
		return FALSE;
}/*end of Fc_counter_elapsed*/

int Fc_time_difference(clock_t timestamp_current)
{
	if(timestamp_current > timestamp_start)
	{
		return MICROSECOND_VALUE(timestamp_current - timestamp_start);
	}
	else
	{
		/*counter overflow condition*/
		return MICROSECOND_VALUE((MAX_CLOCK_CYCLE_TIME - timestamp_start) + timestamp_current);
	}
}/*end of Fc_time_difference*/
