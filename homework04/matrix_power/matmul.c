#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <inttypes.h>
#include <omp.h>
#include "functions.h"

const size_t N = 5;


void ZeroMatrix(int * A, size_t N)
{   
    #pragma omp parallel for 
    for(size_t i = 0; i < N; i++)
    {
        for(size_t j = 0; j < N; j++)
        {
            A[i * N + j] = 0;
        }
    }
}

void RandomMatrix(int * A, size_t N)
{
    unsigned int seed = (unsigned) time(NULL);
    srand(seed);   
    #pragma omp parallel for
    for (size_t i = 0; i < N; i++)
    {   
        for (size_t j = 0; j < N; j++)
        {
            A[i * N + j] = rand_r(&seed) % 2;
        }
    }
}

void MatrixPrint(int * A, size_t N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i * N + j]);
        }
        printf("\n");
    }
}

void MatMul_kij_opt(int * A, int * B, int * C, size_t N)
{
    size_t dummy_k, dummy_i;
    ZeroMatrix(&C[0], N);
    
    #pragma omp parallel for private(dummy_i, dummy_k)\
                             reduction (+: C[:N*N])
    for (size_t k = 0; k < N; k++)
    {
        dummy_k = k * N;
        for (size_t i = 0; i < N; i++)
        {
            dummy_i = i * N;
            for (size_t j = 0; j < N; j++)
            {
                C[dummy_i + j] = C[dummy_i + j] + A[dummy_i + k] * B[dummy_k + j];
            }
        }
    }     
}


void MatrixPower(int * A, int * B, size_t N, size_t power)
{  
    if (power == 0)
    {   
        ZeroMatrix(&B[0], N);
        for (size_t i = 0; i < N; i++)
    	{    
            B[i * N + i] = 1;
        }
        return;
     }

     int * tmp = (int *) malloc(N * N * sizeof(int));
     ZeroMatrix(&tmp[0], N);
     
     if (power % 2 == 0)
     {
         MatrixPower(&A[0], &tmp[0], N, power / 2);    
         MatMul_kij_opt(&tmp[0], &tmp[0], &B[0], N);
     } 
     else
     {
         MatrixPower(&A[0], &tmp[0], N, power - 1);
         MatMul_kij_opt(&A[0], &tmp[0], &B[0], N);
     }
     free(tmp);
     
}


