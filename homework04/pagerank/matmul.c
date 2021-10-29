#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include "functions.h"

const double EPS = 1e-3;
const double D = 0.85;
const int ITERATIONS = 100;
const size_t N = 10;

void RandomMatrix(double * A, size_t N)
{
    unsigned int seed = (unsigned) time(NULL);
    srand(seed);   
    #pragma omp parallel for
    for (size_t i = 0; i < N; i++)
    {   
        for (size_t j = 0; j < N; j++)
        {
            A[i * N + j] = rand_r(&seed) % 5;
        }
    }
}

void MatrixMultVector(double *A, double *V, double *C, size_t N) 
{
    #pragma omp parallel for 
    for (size_t i = 0; i < N; i++) 
    {
        C[i] = 0;
        for (size_t j = 0; j < N; j++)
            C[i] += A[i * N + j] * V[j];
    }
}


void ZeroVector(double * A, size_t N)
{   
    #pragma omp parallel for 
    for(size_t i = 0; i < N; i++)
    {
         A[i] = 0;  
    }
}

void MatrixPrint(double * A, size_t N)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            printf("%f ", A[i * N + j]);
        }
        printf("\n");
    }
}

double NormL1(double *A, double *B, size_t N) 
{
    double norm = 0.0;
    #pragma omp parallel for reduction(+:norm) 
    for (int i = 0; i < N; ++i)
        norm += fabs(A[i] - B[i]);
    return norm;
}



void naiveRank(double *A, double *rank, size_t N) 
{
  ZeroVector(&rank[0], N);
  #pragma omp parallel for
  for (size_t j = 0; j < N; j++) {
    for (size_t i = 0; i < N; i++) {
      rank[j] += A[i * N + j];
    }
  }
}

void normeMatrix(double *A, double * normedA, size_t N) 
{
    double sumCol;
    size_t i,j;
    //#pragma omp parallel for
    for (i = 0; i < N; i++) {
    	sumCol = 0;
    	for (j = 0; j < N; j++) {
    	    sumCol += A[j * N + i];
    	}
    	for (j = 0; j < N; j++) {
    	    if (sumCol != 0)
    		normedA[j * N + i] = A[j * N + i] / sumCol;
    	    else 
    		normedA[j * N + i] = 0;
    	}
    }
}
