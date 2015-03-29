//
//
//
//                          Power.h
//
//                              

#ifndef POWER_H
#define POWER_H

#include <Payoff2.h>

class PowerCall : public PayOff
{
public:
    
	PowerCall(double Strike_, double Power_);
    
    virtual double operator()(double Spot) const;
	virtual ~PowerCall(){}

private:

    double Strike;
	double Power;


};

class PowerPut : public PayOff
{
public:

	PowerPut(double Strike_, double Power_);

	virtual double operator()(double Spot) const;
	virtual ~PowerPut(){}

private:

	double Strike;
	double Power;

};
#endif
