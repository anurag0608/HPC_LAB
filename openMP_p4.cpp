// openMP_p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define STEPS 100000
int main()
{
	double step = (double)(1.0 / STEPS);
	double x, pi, sum;
	pi = 0.0;
	sum = 0.0;

	#pragma omp parallel for private(x)
	for (int i = 0; i < STEPS; i++) {
		x = (i + 0.5) * step;
		#pragma omp critical
		sum += 4.0 / (1.0 + x * x);
	}
	pi = step * sum;
	printf("%f", pi);
	return 0;
}
