const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply
   const double* __restrict Ax = A;
   const double* __restrict X  = x;
   double*       __restrict Y  = y;

   for (int i = 0; i < n; ++i) {
      const double* __restrict row = Ax + (long long)i * n;
      double sum = 0.0;

      #pragma GCC ivdep
      for (int j = 0; j < n; ++j) {
         sum += row[j] * X[j];
      }

      Y[i] += sum;
    }
}
