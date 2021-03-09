/*
 * BMS_Sensor_Core.h
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_SENSOR_CORE_H_
#define BMS_SENSOR_CORE_H_

int Sys_Temp_sr(float *temp);
int Sys_SOC_sr(float *soc);
int Sys_C_rate_sr(float *c_rate);

#define FERENHEIT_SENSOR	0
#define CELCIUS_SENSOR		1

#define TEMP_SENSOR_TYPE  CELCIUS_SENSOR

#endif /* BMS_SENSOR_CORE_H_ */
