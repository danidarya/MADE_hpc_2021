extern const size_t N;

void ZeroMatrix(int * A, size_t N);

void RandomMatrix(int * A, size_t N);

void MatrixPrint(int *A, size_t N);

void MatMul_kij_opt(int * A, int * B, int * C, size_t N);

void MatrixPower(int * A, int * B, size_t N, size_t power);
