/*
 * BMS_Sys_Temperature_eavaluation.c
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */

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

struct SensorReadValue_eval_st temperature_eval[MAX_EVALUATION_TYPES] =					
{																	\
	{																\
		LOW_SYSTEM_DAMAGE_TEMPERATURE,								\
		LOW_SYSTEM_STOP_TEMPERATURE,								\
		Fault_low_temp,												\
		Sysfault_Sleep,												\
	},																\
	{																\
		MIN_OPERATIONAL_TEMPERATURE,								\
		MAX_OPERATIONAL_TEMPERATURE,								\
		Fault_none,													\
		Sysfault_none,												\
	},																\
	{																\
		HIGH_SYSTEM_STOP_TEMPERATURE,								\
		HIGH_SYSTEM_DAMAGE_TEMPERATURE,								\
		Fault_high_temp,											\
		SysFault_Standby,											\
	}																\
};


void Fc_Temperature_Sensor_check(void)
{
	int Retval;
	float temp;
	/*Read appropriate sensor*/
	Retval = Sys_Temp_sr(&temp);
	/*************************/
	if(Retval)
	{
		/*Sensor error*/
		Sysfault_global = Sysfault_Shutdown;
		Fault_type_global = Fault_sensor_failure;
	}
	else
	{
		Fc_Temperature_Evaluation(temp);
	}
}/*end of Fc_Temperature_Sensor_check*/


void Fc_Temperature_Evaluation(float measured_temp)
{	
	int idx = 0;
	for(idx = 0 ; idx<MAX_EVALUATION_TYPES ; idx++ )
		{
			if(isInRange(temperature_eval[idx].low_value , temperature_eval[idx].high_value , measured_temp ))
			{
				Sysfault_global = temperature_eval[idx].sf_type;
				Fault_type_global = temperature_eval[idx].f_type;
			}
		}
}/*end of Fc_Temperature_Evaluation*/
