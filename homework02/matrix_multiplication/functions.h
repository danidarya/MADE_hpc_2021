extern const size_t N;

void ZeroMatrix(double * A, size_t N);

void RandomMatrix(double * A, size_t N);

void RandomVector(double * B, size_t N);

double CalcMatMulTime_kij_opt(double * A, double * B, double * C, size_t N);

double CalcMatMulVecTime_ij(double * A, double * B, double * C, size_t N);
