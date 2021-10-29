#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "functions.h"


void pageRank(double *A, double *B, size_t N) 
{
    size_t i, j;
    double *normedA, *V; 
    normedA = (double *) malloc(N * N * sizeof(double));
    V = (double *) malloc(N * sizeof(double));
    
    #pragma omp parallel for 
    for (i = 0; i < N; i++) 
    {
        V[i] = 1.0 / N;
    }
     
    normeMatrix(A, normedA, N);
    
    for (i = 0; i < ITERATIONS; i++) 
    {
    	MatrixMultVector(normedA, V, B, N);
    	for (j = 0; j < N; j++) 
    	{
    	    B[j] =  D * B[j] + (1 - D) / N;
    	}

    	if (NormL1(V, B, N) < EPS)
    		break;

    	#pragma omp parallel for 
        for (i = 0; i < N; i++) 
        {
            V[i] = B[i];
        }
    }
    free(normedA);
    free(V);
}


int main() {
	
    double *A, *rank, *rankNaive;
    A = (double *) malloc(N * N * sizeof(double));
    rank = (double *) malloc(N * sizeof(double));
    rankNaive = (double *) malloc(N * sizeof(double));

    omp_set_num_threads(8);
    printf("Матрица смежности: \n");
    RandomMatrix(&A[0], N);
    MatrixPrint(&A[0], N);
    
    pageRank(&A[0], &rank[0], N);
    naiveRank(&A[0], &rankNaive[0], N);

    printf("Page rank:\n");
    
    for (int i = 0; i < N; i++)
    {
        printf("%2d: %f", i, rank[i]);
    }
    printf("\n");
    printf("Naive rank: \n");

    for (int i = 0; i < N; i++)
    {
        printf("%2d: %f", i, rankNaive[i]);
    }
    
    printf("\n");
    free(A);
    free(rank);
    free(rankNaive);
    return 0;
}
