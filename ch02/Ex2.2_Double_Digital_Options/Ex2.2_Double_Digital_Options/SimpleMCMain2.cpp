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
using namespace std;

int main()
{

	double Expiry;
	double upperStrike, lowerStrike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter upper strike\n";
	cin >> upperStrike;

	cout << "\nEnter lower strike\n";
	cin >> lowerStrike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOff callPayOff(lowerStrike, upperStrike, PayOff::doubleDigital);

	double result = SimpleMonteCarlo2(callPayOff,
										Expiry,                                           
										Spot, 
										Vol, 
										r, 
										NumberOfPaths);
	
	cout <<"the prices is " << result << "  for the double digital option\n";

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

