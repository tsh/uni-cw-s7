// PrlProg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <emmintrin.h>
#include <ctime>
#include <Windows.h>


/* 26.	Дано 2 масиву чисел типу double однакової розмірності. Розробити алгоритм для обчислення z[i]= x[i]-y[i]. */

#define N 32768
int _tmain(int argc, _TCHAR* argv[])
{
	srand(std::time(0));
	__m128d a;
	double x[N], y[N], z[N];
	int i;
	int start_s=clock();
	for (i=0; i<N; i++){
		x[i]=rand();
		y[i]=rand();
		z[i] = x[i] - y[i];
	}
	int stop_s=clock();
	std::cout<<(stop_s -start_s)<<std::endl;

	__m128d* X = (__m128d*)x;
	__m128d* Y = (__m128d*)y;
	__m128d* Z = (__m128d*)z;
	int start_s2=clock();
	for (i=0; i<N/8; ++i){
		Z[i] = _mm_sub_pd(X[i], Y[i]);
	}
	int stop_s2=clock();
	std::cout<<stop_s2 -start_s2;
	getchar();
	return 0;
}

