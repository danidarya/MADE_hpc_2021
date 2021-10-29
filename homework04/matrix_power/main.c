#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include "functions.h"



int main()
{
    
    int *A, *B;
    double start, end;
    size_t power = 3;
    A = (int *) malloc(N * N * sizeof(int));
    B = (int *) malloc(N * N * sizeof(int));
    
    omp_set_num_threads(4);
    RandomMatrix(&A[0], N);
    
    printf("Матрица смежности:\n");
    MatrixPrint(&A[0], N);
    
    start = omp_get_wtime();
    MatrixPower(&A[0],&B[0], N, power);
    end = omp_get_wtime();
    
    printf("Матрица маршрутов длины %zu: \n",power);
    MatrixPrint(&B[0], N);
   
    printf("Время выполнения %f секунд. \n", end-start);
    free(A); 
    free(B);
    return 0;
}

