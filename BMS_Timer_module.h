/*
 * BMS_Timer_module.h
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_TIMER_MODULE_H_
#define BMS_TIMER_MODULE_H_

#include "time.h"

int Fc_time_difference(clock_t timestamp_current);
int Fc_counter_elapsed(void);
void Fc_start_timer(void);

#define TRUE 1
#define FALSE 0

#define MICROSECOND_VALUE(a) (a / CLOCKS_PER_SEC)
#define MAX_CLOCK_CYCLE_TIME 0xFFFFFFFF /*Arbitrary number. Since not original controller system counter max value not known*/

#endif /* BMS_TIMER_MODULE_H_ */
