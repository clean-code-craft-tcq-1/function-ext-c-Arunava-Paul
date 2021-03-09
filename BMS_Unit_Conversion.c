#include "BMS_Common_Include.h"
#include "BMS_Unit_Conversion.h"

float Ferenheit2Celcius_fc(float value)
{
	float Celc_val;
	Celc_val = (value - 32) * 5 / 9;
	return Celc_val;
}/*end of Ferenheit2Celcius_fc*/