/*
 * BMS_Sensor_Core.c
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */
#include "BMS_Common_Include.h"
#include "BMS_Sensor_Core.h"
#include "BMS_Unit_Conversion.h"

int Sys_Temp_sr(float *temp)
{
	float sensor_value;
	/*Core sensor read is presnt*/
	sensor_value = 90.0;
	/****************************/
	/***************************
	   If the sensor reads in 
	   Farenheit then convert the value
    ****************************/
#if(TEMP_SENSOR_TYPE == FERENHEIT_SENSOR)
	*temp = Ferenheit2Celcius_fc(sensor_value);
#else
	*temp = sensor_value;
#endif

	return 0;
}/*end of Sys_Temp_sr*/

int Sys_SOC_sr(float *soc)
{
	/*Core sensor read is presnt*/
	*soc = 40.5;
	/****************************/
	return 0;
}/*end of Sys_SOC_sr*/

int Sys_C_rate_sr(float *c_rate)
{
	/*Core sensor read is presnt*/
	*c_rate = 0.5;
	/****************************/
	return 0;
}/*end of Sys_C_rate_sr*/

