/*
 * BMS_Harzard_Protection.h
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */

#ifndef BMS_HARZARD_PROTECTION_H_
#define BMS_HARZARD_PROTECTION_H_

extern void Fc_Hazard_Control(void);
extern void Fc_System_shutdown(void);
extern void Fc_Disconnect_Charger(void);
extern void Fc_System_Sleep(void);
extern void Fc_System_Standby(void);

typedef void (*hazard_ctrl_fcpt)(void);

struct Hazard_Control_st
{
	Sysfault_type_en Sys_fault_index;
	hazard_ctrl_fcpt hazard_ctrl_pfcpt;
};
/***This sequence should be same as enum present in the BMS_System_Check.h**/
#define HAZARD_CONTROL_ACCUMULATED_DATA {												\
	{											\
		Sysfault_none,						\
		0,						\
	},											\
	{											\
		SysFault_Standby,						\
		Fc_System_Standby,						\
	},											\
	{											\
		Sysfault_Shutdown,						\
		Fc_System_shutdown,					\
	},											\
	{											\
		Sysfault_Sleep,							\
		Fc_System_Sleep,						\
	},											\
	{											\
		Sysfault_disconnect_charger,			\
		Fc_Disconnect_Charger					\
	}											\
}

#endif /* BMS_HARZARD_PROTECTION_H_ */
