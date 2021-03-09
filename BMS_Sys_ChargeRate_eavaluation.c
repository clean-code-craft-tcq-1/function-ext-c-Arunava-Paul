/*
 * BMS_Sys_ChargeRate_eavaluation.c
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
struct SensorReadValue_eval_st chargerate_eval[MAX_EVALUATION_TYPES] =					
{																	\
	{																\
		MIN_CHARGE_RATE,											\
		MIN_SYSTEM_STOP_CHARGE_RATE,								\
		Fault_chargeRate_low,										\
		Sysfault_Sleep,												\
	},																\
	{																\
		MIN_ALLOWED_CHARGE_RATE,									\
		MAX_ALLOWED_CHARGE_RATE,									\
		Fault_none,													\
		Sysfault_none,												\
	},																\
	{																\
		MAX_SYSTEM_STOP_CHARGE_RATE,								\
		MAX_BREACH_CHARGE_RATE,										\
		Fault_chargeRate_high,										\
		Sysfault_disconnect_charger,								\
	}																\
};

void Fc_Charge_Rate_Sensor_check(void)
{
	int Retval;
	float C_rate;
	/*Read appropriate sensor*/
	Retval = Sys_C_rate_sr(&C_rate);
	/*************************/
	if(Retval)
	{
		/*Sensor error*/
		Sysfault_global = Sysfault_Shutdown;
		Fault_type_global = Fault_sensor_failure;
	}
	else
	{
		Fc_ChargeRate_Evaluation(C_rate);
	}
}/*end of Fc_Charge_Rate_Sensor_check*/

void Fc_ChargeRate_Evaluation(float measured_chrate)
{	
	int idx = 0;
	for(idx = 0 ; idx<MAX_EVALUATION_TYPES ; idx++ )
		{
			if(isInRange(chargerate_eval[idx].low_value , chargerate_eval[idx].high_value , measured_chrate ))
			{
				Sysfault_global = chargerate_eval[idx].sf_type;
				Fault_type_global = chargerate_eval[idx].f_type;
			}
		}
}/*end of Fc_ChargeRate_Evaluation*/
