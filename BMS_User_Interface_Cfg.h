#ifndef BMS_USER_INTERFACE_CFG_H_
#define BMS_USER_INTERFACE_CFG_H_

#define LANGUAGE_PACK LANGUAGE_DEFAULT

/***This sequence should be same as enum present in the BMS_System_Check.h**/
#define USER_INTERFACE_ACCUMULATED_DATA																	\
{																										\
	{																									\
		Fault_none,																						\
		"System ok",																					\
	},																									\
	{																									\
		Fault_low_temp,																					\
		"Warning!! System temperature low",																\
	},																									\
	{																									\
		Fault_high_temp,																				\
		"Warning!! System temperature high, Putting system into standby",								\
	},																									\
	{																									\
		Fault_soc_low,																					\
		"Warning!! System SOC low ,  Putting system into sleep , Please connect the vehicle to charge",	\
	},																									\
	{																									\
		Fault_soc_high,																					\
		"Warning!! System SOC is high, disconnecting from charger",										\
	},																									\
	{																									\
		Fault_chargeRate_high,																			\
		"Warning!! System charge rate is high , disconnecting from charger",							\
	},																									\
	{																									\
		Fault_chargeRate_low,																			\
		"Warning!! System charge rate is low",															\
	},																									\
	{																									\
		Fault_sensor_failure,																			\
		"Warning!! Sensor failure, Shutting down system",												\
	}																									\
}

#endif
