/*
 * BMS_System_Check.h
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_SYSTEM_CHECK_H_
#define BMS_SYSTEM_CHECK_H_

#define MAX_EVALUATION_TYPES   3

typedef enum
{
	Fault_none = 0,
	Fault_low_temp,
	Fault_high_temp,
	Fault_soc_low,
	Fault_soc_high,
	Fault_chargeRate_high,
	Fault_chargeRate_low,
	Fault_sensor_failure,
	Fault_max_condition
}Fault_type_en;

typedef enum
{
	Sysfault_none = 0,
	SysFault_Standby,
	Sysfault_Shutdown,
	Sysfault_Sleep,
	Sysfault_disconnect_charger,
    Sysfault_max_condition
}Sysfault_type_en;


struct SensorReadValue_eval_st
{
	float low_value;
	float high_value;
	Fault_type_en f_type;
	Sysfault_type_en sf_type;	
};

extern void Fc_SOC_Sensor_check(void);
extern void Fc_Charge_Rate_Sensor_check(void);
extern void Fc_System_init(void);
extern void Fc_Battery_Check(void);
extern void Fc_Temperature_Sensor_check(void);
extern void Fc_Temperature_Evaluation(float measured_temp);
extern void Fc_SOC_Evaluation(float measured_SOC);

#endif /* BMS_SYSTEM_CHECK_H_ */
