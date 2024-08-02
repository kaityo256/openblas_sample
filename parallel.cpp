#include <algorithm>
#include <cblas.h>
#include <cstdio>
#include <random>

const int M = 2000;
const int N = 3000;
const int K = 2000;

double a[M][N];
double b[N][K];
double c[M][K];

void simple_dgemm(void) {
  const double alpha = 1.0;
  const double beta = 0.0;
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
              M, K, N, alpha, *a, N, *b, K, beta, *c, K);
  double sum = 0.0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      sum += c[i][j];
    }
  }
  printf("%f\n", sum);
}

template <size_t S1, size_t S2>
void initialize(double (&x)[S1][S2], std::mt19937 &mt) {
  std::uniform_real_distribution<> ud(-1.0, 1.0);
  for (int i = 0; i < S1; i++) {
    for (int j = 0; j < S2; j++) {
      x[i][j] = ud(mt);
    }
  }
}

int main() {
  std::mt19937 mt;
  initialize(a, mt);
  initialize(b, mt);
  initialize(c, mt);
  simple_dgemm();
}
