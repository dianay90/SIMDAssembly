// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

//#include "simd.p5.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "simd.p5.h"
#include <iostream>

using namespace std;

//const int SIZE=12288;


float  ARRA[SIZE];
float  ARRB[SIZE];
float  ARRC[SIZE];

int workItems = 50;
//int size = 50;

//if not def size and work items 


 double getRandomDouble(double min, double max) {
		return min + ((double)rand() / RAND_MAX) * (max - min);
	}



double arrayMultiplication()
{

double startTime = omp_get_wtime();

//	double  sum = 0.0;

	for (int j = 0; j < SIZE; j++)
	{
//		sum += ARRA[j] * ARRB[j];
			ARRC[j] =ARRA[j] * ARRB[j];

	}
double endTime = omp_get_wtime();

//	return sum;
//return (double)SIZE/(endTime-startTime)/1000000.;
return endTime-startTime;
}

double arrayMultiplicationWReduc()
{
double startTime = omp_get_wtime();





float sum = 0.;

	for( int i = 0; i < SIZE; i++ ) {
		sum += ARRA[i] * ARRB[i];
	}

//	return sum;
//	return totalSum;
//return (double)SIZE/(endTime-startTime)/1000000.;
 double endTime = omp_get_wtime();

return endTime-startTime;

}




double simdMulMain()
{

	double startTime = omp_get_wtime();
	SimdMul(ARRA, ARRB, ARRC,SIZE );
	double endTime = omp_get_wtime();
//	fprintf(stderr, "SIMD_SSE_MUL MegaMults/sec = %10.2lf\n", (double)ARRAY_SIZE/(endTime-startTime)/1000000.);
//	return (double)SIZE/(endTime-startTime)/1000000.;
return endTime-startTime;

}




double simdMulReduc2()
{

double startTime = omp_get_wtime();
	SimdMulSum(ARRA, ARRB, SIZE);
	double endTime = omp_get_wtime();
	//fprintf(stderr, "SIMD_SSE_SUM MegaMults/sec = %10.2lf\n", (double)ARRAY_SIZE/(endTime-startTime)/1000000.);
//	return (double)SIZE/(endTime-startTime)/1000000.;

return endTime-startTime;


}







int main()
{

srand(static_cast<unsigned int>(time(NULL)));


 omp_set_num_threads(1);

for (int i=0; i<SIZE;i++)
{

ARRA[i]=getRandomDouble(0.0,345.90);

ARRB[i]=getRandomDouble(0.0,432.90);


}





double mulTime= arrayMultiplication()/simdMulMain();
double ReducTime= arrayMultiplicationWReduc()/simdMulReduc2(); 
//cout << "Array Normal" << " , " << arr << ",  Array with Reduc" << " , " << arrRed<< ",  simd Mul"<< " , "<< simdMul << ",  simdMulReduc" << " , "<< simdMulReduc <<endl;
//
 cout << "multTime" << mulTime <<endl;
cout<< "ReducTime" << ReducTime<<endl;  







    return 0;
}

