// openMP_p6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main()
{
	int A[] = { 1,4,0,10,6,8,9,200,1,80 };
	int greatest = -1;
	#pragma omp parallel
	{
		for (int i = 0; i < 10; i++) {
			if (A[i] > greatest) {
				#pragma omp critical
				greatest = A[i];
			}
		}
	}
	
	printf("%d", greatest);
	return 0;
}

