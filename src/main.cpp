#include <algorithm>
#include <iostream>
#include <vector>

#include "matrix/matrix.h"

template <class T>
void PrintMatrix(const delgon::Matrix<T>& mat) {
  std::cout << "Size: " << mat.num_rows() << " " << mat.num_columns() << '\n';
  for (const auto& row : mat) {
    for (const auto& v : row)
      std::cout << v << " ";
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  delgon::Matrix<double> mat_d(2, 3, 5);
  delgon::Matrix<float> mat_f(2, 3, 5);
  delgon::Matrix<float> mat_f2(4, 8, 5);
  delgon::Matrix<float> mat_f3(44, 21,123.123);

  PrintMatrix(mat_f2);
  mat_f2[0][1] = 2;
  PrintMatrix(mat_f2);

  if (mat_d.equal(mat_f))
    std::cout << "The same 1\n\n";

  mat_f[0][0] += 9.99e-6;
  if (mat_d.equal(mat_f))
    std::cout << "The same 2\n\n";

  if (mat_d.equal(mat_f, 1e-2))
    std::cout << "The same 3\n\n";

  mat_d = delgon::Matrix<float>(8, 3, 3);
  PrintMatrix(mat_d);

  mat_f = mat_f2;
  PrintMatrix(mat_f);

  if (mat_f == mat_f2)
    std::cout << "The same 4\n\n";

  if (mat_f.equal(mat_f2))
    std::cout << "The same 5\n\n";

  // Copy constructor + Copy
  mat_f = mat_f2;
  // Move
  mat_f = std::move(mat_f2);
  // Cast + Move
  mat_f = delgon::Matrix<float>(mat_d);
  // Cast + Move
  mat_f = mat_d;
  // Cast + Cast + Move
  mat_f = delgon::Matrix<double>(mat_f3);
  // Move Constructor + Move
  mat_f = delgon::Matrix<float>(std::move(mat_f3));

  // Basic operations
  delgon::Matrix<double> op_1(3, 6, 1);
  PrintMatrix(op_1);
  PrintMatrix(op_1 + delgon::Matrix<double>(3, 6, 2) + op_1);
  PrintMatrix(op_1 * 2.5);
  // TODO
  // PrintMatrix(2.5 * op_1);

  PrintMatrix(op_1.Transpose());
  PrintMatrix(op_1);
  PrintMatrix(op_1.TransposeInplace());
  PrintMatrix(op_1);
  PrintMatrix(delgon::Matrix<double>(3, 3, 2) *
              delgon::Matrix<double>(3, 3, 3));

  PrintMatrix(op_1.RowMultiplication(3, 4));
  PrintMatrix(op_1.RowAddition(2, 3));
  PrintMatrix(op_1.RowSwitch(2, 0));
  PrintMatrix(op_1.RowMultiplicationInplace(3, 4));
  PrintMatrix(op_1.RowAdditionInplace(2, 3));
  PrintMatrix(op_1.RowSwitchInplace(2, 0));
  op_1[1][1] = 9;
  PrintMatrix(op_1.Submatrix({0, 1}, {2, 0}));
  PrintMatrix(op_1.SubmatrixInplace({0, 1}, {2, 0}));
  PrintMatrix(op_1);

  return 0;
}
