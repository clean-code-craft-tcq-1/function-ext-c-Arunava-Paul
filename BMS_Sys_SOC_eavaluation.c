/*
 * BMS_Sys_SOC_eavaluation.c
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */
#include "BMS_Common_Include.h"
#include "BMS_System_Check.h"
#include "BMS_Sensor_Core.h"
#include "BMS_System_Threshold_Values_Cfg.h"

extern Sysfault_type_en Sysfault_global;
extern Fault_type_en Fault_type_global;


/**********************

struct SensorReadValue_eval_st
{
	float low_value;
	float high_value;
	Fault_type_en f_type;
	Sysfault_type_en sf_type;	
};

*************************/

struct SensorReadValue_eval_st SOC_eval[MAX_EVALUATION_TYPES] =					
{																	\
	{																\
		BATTERY_DRAINED,											\
		LOW_SYSTEM_STOP_SOC,										\
		Fault_soc_low,												\
		Sysfault_Sleep,												\
	},																\
	{																\
		MIN_OPERATION_SOC_VALUE,									\
		MAX_OPERATION_SOC_VALUE,									\
		Fault_none,													\
		Sysfault_none,												\
	},																\
	{																\
		HIGH_SOC_BREACH,											\
		HIGH_SOC_SYSTEM_STOP,										\
		Fault_soc_high,												\
		Sysfault_disconnect_charger,								\
	}																\
};

void Fc_SOC_Sensor_check(void)
{
	int Retval;
	float soc;
	/*Read appropriate sensor*/
	Retval = Sys_SOC_sr(&soc);
	/*************************/
	if(Retval)
	{
		/*Sensor error*/
		Sysfault_global = Sysfault_Shutdown;
		Fault_type_global = Fault_sensor_failure;
	}
	else
	{
		Fc_SOC_Evaluation(soc);
	}
}/*end of Fc_SOC_Sensor_check*/


void Fc_SOC_Evaluation(float measured_SOC)
{	
	int idx = 0;
	for(idx = 0 ; idx<MAX_EVALUATION_TYPES ; idx++ )
		{
			if(SOC_eval[idx].low_value <= measured_SOC <= SOC_eval[idx].high_value)
			{
				Sysfault_global = SOC_eval[idx].sf_type;
				Fault_type_global = SOC_eval[idx].f_type;
			}
		}
}/*end of Fc_SOC_Evaluation*/