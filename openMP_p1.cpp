// openMP_p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define N 10000
int main()
{
    int maxThreads = omp_get_max_threads();
    int **a = (int**)malloc(N * sizeof(int*));
    int *b = (int*)malloc(N * sizeof(int));
    int *c = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        a[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 100;
        }
        b[i] = rand() % 100;
        //printf("%d \n", b[i]);
    }
    omp_set_num_threads(maxThreads);
   

    clock_t begin = std::clock();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        c[i] = 0;
        for (int j = 0; j < N; j++) {
            c[i] += a[i][j] * b[j];
          // printf("Thread num : %d\n", omp_get_thread_num());
        }
    }
    double time_spent = 0.0;

    clock_t end = std::clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent);


    return 0;
}
