/*
 * User_Interface.c
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */
#include "BMS_System_Check.h"
#include "BMS_Common_Include.h"
#include "BMS_User_Interface.h"
#include "BMS_User_Interface_Cfg.h"
#include "BMS_language_change.h"

extern Fault_type_en Fault_type_global;
int Data_transmission_global = FALSE;
const struct user_interface_st usr_interface[Fault_max_condition] = USER_INTERFACE_ACCUMULATED_DATA;

void Fc_Display_Msg(void)
{	
	if(LANGUAGE_PACK == LANGUAGE_DEFAULT)
	{
		printf("\n%s\n", usr_interface[Fault_type_global].user_msg_string);
	}
	else
	{
		printf("\n%s\n", Translate_fc(Fault_type_global));
	}
	Data_transmission_global = TRUE;
}/*end of Fc_Display_Msg*/

