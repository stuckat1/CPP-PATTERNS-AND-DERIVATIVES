
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

int main()
{

	clock_t t_start = clock();

	double* ptr;
	
	for (int i = 1; i < 8; i++)
	{
		int k = (int)pow(10, i);

		for (int j = 0; j < 10000; j++)
		{
			ptr = new double[k];
			delete[] ptr;
		}

		clock_t t_delta = clock() - t_start;

		cout << k << " doubles took " << t_delta << " clock ticks" << endl;

	}
}