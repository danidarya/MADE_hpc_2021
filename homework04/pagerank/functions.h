extern const double EPS;
extern const double D;
extern const int ITERATIONS;
extern const size_t N;

void RandomMatrix(double * A, size_t N);

void MatrixMultVector(double *A, double *V, double *C, size_t N);

void ZeroVector(double * A, size_t N);

void MatrixPrint(double * A, size_t N);

double NormL1(double *A, double *B, size_t N);

void naiveRank(double *A, double *rank, size_t N);

void normeMatrix(double *A, double * normedA, size_t N);
