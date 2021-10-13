#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "functions.h"



int main()
{
    
    int NRuns = 5;
   // size_t i, j, k;
    double average_runtime = 0.0;
    double *runtimes;
    double *A, *B, *C, *D;
    
    A = (double *) malloc(N * N * sizeof(double));
    B = (double *) malloc(N * N * sizeof(double));
    C = (double *) malloc(N * N * sizeof(double));
    D = (double *) malloc(N * sizeof(double));
    
    runtimes = (double *) malloc(NRuns * sizeof(double));

    RandomMatrix(&A[0], N);
    RandomMatrix(&B[0], N);
    RandomVector(&D[0], N);

    printf("N = %zu \n", N);
// kij ordering naive optimization (useless for -O3)
    average_runtime = 0.0;
    for(int n=0; n<NRuns; n++)
    {
        runtimes[n]=CalcMatMulTime_kij_opt(&A[0], &B[0], &C[0], N);
        printf("runtime %lf seconds\n", runtimes[n]);
        average_runtime += runtimes[n]/NRuns;
    }
    printf("average runtime kij opt %lf seconds\n", average_runtime);
    printf("---------------------------------\n");

    
// matrix vector multiplication
    average_runtime = 0.0;
    for(int n=0; n<NRuns; n++)
    {
        runtimes[n]=CalcMatMulVecTime_ij(&A[0], &D[0], &C[0], N);
        printf("runtime %lf seconds\n", runtimes[n]);
        average_runtime += runtimes[n]/NRuns;
    }
    printf("average runtime matrix vector multiplication %lf seconds\n", average_runtime);
    printf("---------------------------------\n");


    free(A); 
    free(B);
    free(C);
    free(D);
    return 0;
}

