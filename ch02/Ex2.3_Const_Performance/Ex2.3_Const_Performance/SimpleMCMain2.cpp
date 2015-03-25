//
//
//	                	SimpleMCMain2.cpp
//
//     
// 

/*
requires 
         PayOff1.cpp
         Random1.cpp, 
         SimpleMC.cpp, 
*/

#include<SimpleMC.h>
#include<iostream>
#include <ctime>	
using namespace std;

int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;
	double resultCall, resultPut;
	clock_t start;

	Expiry = 1.0;
	Strike = 100;
	Spot = 100;
	Vol = 0.20;
	r = 0.01;
	NumberOfPaths = 500000;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

	start = clock();

	for (int i = 0; i < 10; i++)
	{
		resultCall = SimpleMonteCarlo2(callPayOff,
			Expiry,
			Spot,
			Vol,
			r,
			NumberOfPaths);

		resultPut = SimpleMonteCarlo2(putPayOff,
			Expiry,
			Spot,
			Vol,
			r,
			NumberOfPaths);
	}

	double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "using const, duration is " << duration << endl;

	start = clock();

	for (int i = 0; i < 10; i++)
	{
		resultCall = SimpleMonteCarloSlow(callPayOff,
			Expiry,
			Spot,
			Vol,
			r,
			NumberOfPaths);

		resultPut = SimpleMonteCarloSlow(putPayOff,
			Expiry,
			Spot,
			Vol,
			r,
			NumberOfPaths);
	} 

	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << "not const, duration is " << duration << endl;

    double tmp;
    cin >> tmp;

	return 0;

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

