/*
 * BMS_System_Check.c
 *
 *  Created on: Feb 28, 2021
 *      Author: PUL1KOR
 */
#include "BMS_Common_Include.h"
#include "BMS_System_Check.h"
#include "BMS_System_Threshold_Values_Cfg.h"
#include <assert.h>

Sysfault_type_en Sysfault_global;
Fault_type_en Fault_type_global;

void Fc_System_init(void)
{
	Sysfault_global = Sysfault_none;
	Fault_type_global = Fault_none;
}/*end of Fc_System_init*/


void Fc_Battery_Check(void)
{
	if(!((Fault_type_global == Fault_none)))
	{
		assert(1);
	}
	else
	{
		assert(0);
	}
}


int isInRange(float lowerLimit, float upperLimit, float no)
{
    return (lowerLimit < no && no < upperLimit);
}

