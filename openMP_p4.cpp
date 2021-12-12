// openMP_p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define STEPS 1000000
int main()
{
	double step = (double)(1.0 / STEPS);
	double x, pi;
	
	int NUM_THREADS = omp_get_num_threads();
	//omp_set_num_threads(NUM_THREADS);

	double* sum = (double*)malloc(NUM_THREADS * sizeof(double));
	pi = 0.0;

	#pragma omp parallel private(x)
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		sum[id] = 0.0;
		for (int i = id; i < STEPS; i += nt) {
			x = (i + 0.5) * step;
			sum[id] += (4.0 / (1 + x * x));
		}
	}
	for (int i = 0; i < NUM_THREADS; i++) {
		//printf("%f ", sum[i]);
		pi += sum[i] * step;
	}
	printf("PI : %f", pi);
	return 0;
}
