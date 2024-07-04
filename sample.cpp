#include <cblas.h>
#include <cstdio>

/*
  行列積のサンプル
  M行N列の行列aと、N行K列の行列bをかけてM行K列の行列cを得る

  CblasRowMajor 行優先(C/C++で使う。Fortranが列優先なので区別する必要がある。)
  CblasNoTrans 転置せずに使う。CblasTransを指定すると転置することができる
  double alpha スカラー係数。aとbにかけることができる。今回は不要なので1.0に。
  double beta スカラー係数。cにかけることができる。今回は不要なので0.0に。
*/
void simple_dgemm(void) {
  const int M = 2;
  const int N = 3;
  const int K = 2;
  double a[M][N] = {{1, 2, 3}, {3, 4, 5}};
  double b[N][K] = {{1, 2}, {3, 4}, {5, 6}};
  double c[M][K] = {};
  const double alpha = 1.0;
  const double beta = 0.0;
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
              M, K, N, alpha, *a, N, *b, K, beta, *c, K);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      printf("%f ", c[i][j]);
    }
    printf("\n");
  }
}

int main() {
  simple_dgemm();
}