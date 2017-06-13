#include "matrix.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
void print_mat(const Matrix<T>& mat) {
  printf("Size: %lu %lu\n", mat.rows(), mat.columns());
  for (auto& row : mat) {
    for (auto v : row)
      cout << v << " ";
    cout << '\n';
  }
  cout << '\n';
}

int main() {
  Matrix<double> mat_d(2, 3, 5);
  Matrix<float> mat_f(2, 3, 5);
  Matrix<float> mat_f2(4, 8, 5);

  print_mat(mat_f2);
  mat_f2[0][1] =  2;
  print_mat(mat_f2);

  if (mat_d.equal(mat_f))
    printf("The same 1\n\n");

  mat_f[0][0] += 9.99e-6;
  if (mat_d.equal(mat_f))
    printf("The same 2\n\n");

  if (mat_d.equal(mat_f, 1e-2))
    printf("The same 3\n\n");

  mat_d = Matrix<float>(8, 3, 3);
  print_mat(mat_d);

  mat_f = mat_f2;
  print_mat(mat_f);

  if (mat_f == mat_f2)
    printf("The same 4\n\n");

  if (mat_f.equal(mat_f2))
    printf("The same 5\n\n");

  return 0;
}
