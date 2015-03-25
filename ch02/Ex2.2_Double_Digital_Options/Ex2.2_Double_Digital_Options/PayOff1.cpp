//
//
//
//                  PayOff1.cpp
//
//

#include <PayOff1.h>
#include <MinMax.h>

PayOff::PayOff(double Strike_, double upperStrike_, OptionType TheOptionsType_)
:
    Strike(Strike_), upperStrike(upperStrike_), TheOptionsType(TheOptionsType_)
{
}

double PayOff::operator ()(double spot) const
{
    switch (TheOptionsType)
    {
    case call : 
        return max(spot-Strike,0.0);

    case put:
        return max(Strike-spot,0.0);

	case doubleDigital:
		return (upperStrike > spot) && (spot > Strike) ? 1 : 0;
	
	default:
        throw("unknown option type found.");

    }
}

/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/

