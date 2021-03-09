/*
 * BMS_System_Threshold_Values_Cfg.h
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_SYSTEM_THRESHOLD_VALUES_CFG_H_
#define BMS_SYSTEM_THRESHOLD_VALUES_CFG_H_

/*********************************************
	Section for Temperatures
*********************************************/

#define LOW_SYSTEM_DAMAGE_TEMPERATURE  -120.0f
#define LOW_SYSTEM_STOP_TEMPERATURE     0.0f
#define MIN_OPERATIONAL_TEMPERATURE		0.1f
#define MAX_OPERATIONAL_TEMPERATURE		44.9f
#define HIGH_SYSTEM_STOP_TEMPERATURE    45.0f
#define HIGH_SYSTEM_DAMAGE_TEMPERATURE  80.0f

/********************************************/

/*********************************************
	Section for SOC
*********************************************/

#define BATTERY_DRAINED				0.0f
#define LOW_SYSTEM_STOP_SOC			20.0f
#define MIN_OPERATION_SOC_VALUE		21.0f
#define MAX_OPERATION_SOC_VALUE		79.9f
#define HIGH_SOC_BREACH				80.0f
#define HIGH_SOC_SYSTEM_STOP		100.0f

/********************************************/

/*********************************************
	Section for Charge Rate
*********************************************/

#define MIN_CHARGE_RATE					0.0f
#define MIN_SYSTEM_STOP_CHARGE_RATE		0.2f
#define MIN_ALLOWED_CHARGE_RATE			0.3f
#define MAX_ALLOWED_CHARGE_RATE			0.7f
#define MAX_SYSTEM_STOP_CHARGE_RATE		0.8f
#define MAX_BREACH_CHARGE_RATE			1.0f


/********************************************/


#endif /* BMS_SYSTEM_THRESHOLD_VALUES_CFG_H_ */
