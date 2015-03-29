//
//
//
//                            Power.cpp
//
//

#include <cmath>
#include <Power.h>

PowerCall::PowerCall(double Strike_, double Power_)
            : Strike(Strike_), Power(Power_){
}

double PowerCall::operator()(double Spot) const
{
	if (std::pow(Spot, Power) > Strike)
		return std::pow(Spot, Power) - Strike;

    return 0;
}

PowerPut::PowerPut(double Strike_, double Power_)
	: Strike(Strike_), Power(Power_){
}

double PowerPut::operator()(double Spot) const
{
	if (Strike > std::pow(Spot, Power))
		return Strike - std::pow(Spot, Power);

	return 0;
}
