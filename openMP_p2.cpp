// openMP_p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 50000
#define SCALAR 34457
int main()
{   // SAXPY
    // Z->A*X+Y
    // where A & Y are vectors and X is a scalar
    omp_set_num_threads(omp_get_max_threads());
    int *Z, *A, X, *Y;
    Z = (int*)malloc(N * sizeof(int));
    A = (int*)malloc(N * sizeof(int));
    Y = (int*)malloc(N * sizeof(int));
    X = SCALAR;

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        Y[i] = rand() % 100;
    }

    clock_t begin = std::clock();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Z[i] = A[i] * X + Y[i];
        }
    }
    clock_t end = std::clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time taken : %f seconds", time_spent);
    return 0;
}


