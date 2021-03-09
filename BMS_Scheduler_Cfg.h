/*
 * BMS_Scheduler_Cfg.h
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_SCHEDULER_CFG_H_
#define BMS_SCHEDULER_CFG_H_

#include "BMS_System_Check.h"
#include "BMS_Hazard_Control.h"
#include "BMS_User_Interface.h"

/***********Configure the function needs tobe added here******************/

CyclicTask_funcptrarray Cyc_aptr[] = {Fc_Temperature_Sensor_check,Fc_SOC_Sensor_check,Fc_Charge_Rate_Sensor_check};
BckTask_funcptrarray Bg_aptr[] = {Fc_Display_Msg,Fc_Battery_Check,Fc_Hazard_Control};

/************************************************************************/

#define MAX_FG_TASK (sizeof(Cyc_aptr)/sizeof(Cyc_aptr[0]))
#define MAX_BG_TASK (sizeof(Bg_aptr)/sizeof(Bg_aptr[0]))

#endif /* BMS_SCHEDULER_CFG_H_ */
