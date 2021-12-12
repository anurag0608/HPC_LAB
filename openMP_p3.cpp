// openMP_p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#define N 20000 // num of section
#define M 2000 // items per section
int main()
{
	omp_set_num_threads(20);

	int** cart = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
		cart[i] = (int*)malloc(M * sizeof(int));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cart[i][j] = rand() % 100;
		}
	}
	double sum = 0.0;
	
	clock_t begin = std::clock();

	#pragma omp parallel for
	for(int i =0;i<N;i++){
		int rowSum = 0;
		for (int j = 0; j < M; j++) {
			rowSum += cart[i][j];
		}
		#pragma omp critical
		sum += rowSum;
	}
	clock_t end = std::clock();

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Final sum : %lf", sum);
	printf("\nTime taken : %f ", time_spent);
	return 0;
}

