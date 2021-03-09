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
		if(C_rate < MIN_CHARGE_RATE)
		{
			Fault_type_global = Fault_chargeRate_low;
			Sysfault_global = Sysfault_none;
		}
		else if(C_rate > MAX_CHARGE_RATE)
		{
			Fault_type_global = Fault_chargeRate_high;
			Sysfault_global = Sysfault_disconnect_charger;
		}
		else
		{
			//system normal,do nothing
		}
	}
}/*end of Fc_Charge_Rate_Sensor_check*/
