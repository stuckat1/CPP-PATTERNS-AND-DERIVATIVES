//
//
//                          PayoffCreator.cpp
//
//
#include "PayOffCreator.h"



PayOff* PayOffCreator(std::string& nameOfFunction, double Strike_)
{
	if (0 == nameOfFunction.compare("call"))
		return new PayOffCall(Strike_);
	if (0 == nameOfFunction.compare("put"))
		return new PayOffPut(Strike_);

	return NULL;
}