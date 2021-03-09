/*
 * User_Interface.h
 *
 *  Created on: Feb 27, 2021
 *      Author: PUL1KOR
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#define LANGUAGE_DEFAULT		0
#define LANGUAGE_DEUTCH			1


extern void Fc_Display_Msg(void);

struct user_interface_st
{
	unsigned int failure_identifier;
	char *user_msg_string;
};

#endif /* USER_INTERFACE_H_ */
