// PrlProg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <emmintrin.h>
#include <ctime>
#include <Windows.h>
#include <intrin.h>


/* 26.	Дано 2 масиву чисел типу double однакової розмірності. Розробити алгоритм для обчислення z[i]= x[i]-y[i]. */

#define N 32768
int _tmain(int argc, _TCHAR* argv[])
{
	srand(std::time(0));
	__m128d a;
	double x[N], y[N], z[N];
	int i;
	for (i=0; i<N; i++){
		x[i]=rand();
		y[i]=rand();
	}

	__int64 start_s=__rdtsc();
	for (i=0; i<N; i++){
		z[i] = x[i] - y[i];
	}
	__int64 stop_s=__rdtsc();

	std::cout<<(stop_s -start_s)<<std::endl;

	__m128d* X = (__m128d*)x;
	__m128d* Y = (__m128d*)y;
	__m128d* Z = (__m128d*)z;
	__int64 start_s2=__rdtsc();
	for (i=0; i<N/2; ++i){
		Z[i] = _mm_sub_pd(X[i], Y[i]);
	}
	__int64 stop_s2=__rdtsc();
	std::cout<<stop_s2 -start_s2;
	getchar();
	return 0;
}

