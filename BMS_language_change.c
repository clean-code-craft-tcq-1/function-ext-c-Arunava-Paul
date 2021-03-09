#include "BMS_Common_Include.h"
#include "BMS_System_Check.h"
#include "BMS_language_change.h"
#include "BMS_Deutch_LanguagePack_Cfg.h"

const struct translated_msg_pack_st translated_msg[Fault_max_condition] = LANGUAGE_ERROR_INFO_STRUCTURE;
char* Translate_fc(unsigned int index)
{
	char *msg;
	msg = translated_msg[index].msg_translated;
	return msg;
}/*end of Translate_fc*/