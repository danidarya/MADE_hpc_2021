#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>



void seedThreads(const size_t nThreads, unsigned int* seeds) {
    int my_thread_id;
    unsigned int seed;
    #pragma omp parallel private (seed, my_thread_id)
    {
        my_thread_id = omp_get_thread_num();
        unsigned int seed = (unsigned) time(NULL);
        seeds[my_thread_id] = (seed & 0xFFFFFFF0) | (my_thread_id + 1);
    }
    return;
}

int main(int argc, char *argv[])
{
    int n_points = 200000;
    const int nThreads = 4;
    unsigned int seeds[nThreads];
    int points_in_circle = 0;
    double start, end, pi, x, y;
    int tid, seed;
    
    omp_set_num_threads(nThreads);
    seedThreads(nThreads, seeds);
    
    if (argc > 1) 
    {
        n_points = atoi(argv[1]);
    }
    start = omp_get_wtime();
    
    #pragma omp parallel num_threads(nThreads) \
		 private(tid, seed, x, y) \
		 reduction(+: points_in_circle)
    {
	tid = omp_get_thread_num();
	seed = seeds[tid];
	srand(seed);
        #pragma omp for
        for (int i = 0; i < n_points; i += 1) 
        {
             x = (double) rand_r(&seed) / RAND_MAX;
	     y = (double) rand_r(&seed) / RAND_MAX;    
	     if (x * x + y * y <= 1) 
	     {
	          points_in_circle += 1;
	     }
        }
    }
    
    pi = 4.0 * points_in_circle / n_points;
    end = omp_get_wtime();
    printf("number of points = %d\n", n_points);
    printf("Pi = %f\n", pi);
    printf("time of calculation=%f\n", end - start);
    return 0;
}
