#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

namespace delgon {

template <class T>
class Matrix {
 public:
  // Constructors.
  Matrix(Matrix<T>&& matrix);
  Matrix(const Matrix<T>& matrix);
  Matrix(size_t rows, size_t columns);
  Matrix(size_t rows, size_t columns, T base_value);

  // Cast constructor.
  template <class Y> Matrix(const Matrix<Y>& matrix);

  // Getters
  size_t num_rows() const;
  size_t num_columns() const;

  // Iterators - iterates over rows in the matrix.
  typename std::vector<std::vector<T>>::iterator begin();
  typename std::vector<std::vector<T>>::iterator end();

  typename std::vector<std::vector<T>>::const_iterator begin() const;
  typename std::vector<std::vector<T>>::const_iterator end() const;

  // Operators.
  // Returns a whole row.
  std::vector<T>& operator[] (size_t id);
  const std::vector<T>& operator[] (size_t id) const;

  bool operator== (const Matrix<T>& rhs) const;
  bool operator!= (const Matrix<T>& rhs) const;
  Matrix<T>& operator= (const Matrix<T>& rhs);
  Matrix<T>& operator= (Matrix<T>&& rhs);

  // Basic Operations
  // Addition
  Matrix<T> operator+ (const Matrix<T>& rhs) const;

  // Scalar multiplication
  Matrix<T> operator* (const T& rhs) const;

  // Matrix multiplication
  Matrix<T> operator* (const Matrix<T>& rhs) const;

  // Transposition
  Matrix<T> Transpose() const;
  Matrix<T>& TransposeInplace();

  // Row Operations
  Matrix<T> RowAddition(size_t add_to, size_t add_from) const;
  Matrix<T>& RowAdditionInplace(size_t add_to, size_t add_from);
  Matrix<T> RowMultiplication(size_t row, const T& value) const;
  Matrix<T>& RowMultiplicationInplace(size_t row, const T& value);
  Matrix<T> RowSwitch(size_t row1, size_t row2) const;
  Matrix<T>& RowSwitchInplace(size_t row1, size_t row2);

  // Submatrix
  // rows: Selected rows id's
  // columns: Selected columns id's
  Matrix<T> Submatrix(const std::vector<size_t>& rows,
                      const std::vector<size_t>& columns) const;
  Matrix<T>& SubmatrixInplace(std::vector<size_t> rows,
                              std::vector<size_t> columns);

  // Comparator with eps. Cast every value 'Y' to 'T' before comparison.
  template <class Y>
  bool equal(const Matrix<Y>& mat_y, T eps = -1);

 private:
  std::vector<std::vector<T>> mat_;
};


} // namespace delgon
#include "matrix.h_inline"
#endif // MATRIX_H_
