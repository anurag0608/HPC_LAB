// openMP_p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
#define N 100
int main()
{
	double *fib = (double*)malloc(N * sizeof(double));

	omp_set_num_threads(omp_get_max_threads());

	fib[0] = 0.0;

	fib[1] = 1.0;
	#pragma omp parallel
	{
		for (int i = 2; i < N; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
			//printf("Thread id : %d\n", omp_get_thread_num());
		}
	}
	#pragma omp barrier
	#pragma omp single
	{
		printf("Fib series.. \n");
		for (int i = 0; i < N; i++)
			printf("%0.0f ", fib[i]);
	}
	return 0;
}
