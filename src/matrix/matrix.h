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
  Matrix<T>& operator+= (const Matrix<T>& rhs);
  Matrix<T> operator+ (T rhs) const;
  Matrix<T>& operator+= (T rhs);

  // Matrix scalars
  Matrix<T> operator* (T rhs) const;
  Matrix<T>& operator*= (T rhs);

  Matrix<T> operator/ (T rhs) const;
  Matrix<T>& operator/= (T rhs);

  // Matrix multiplication
  Matrix<T> operator* (const Matrix<T>& rhs) const;
  Matrix<T>& operator*= (const Matrix<T>& rhs);

  // Transposition
  Matrix<T>& Transpose();

  // Row Operations
  // TODO
  // Add Row / Column for these types of operations
  // for more clarity
  Matrix<T>& RowAddition(size_t add_to, size_t add_from);
  Matrix<T>& RowMultiplication(size_t row, T value);
  Matrix<T>& RowSwitch(size_t row1, size_t row2);

  // Comparator with eps. Cast every value 'Y' to 'T' before comparison.
  template <class Y>
  bool equal(const Matrix<Y>& mat_y, T eps = -1);

 private:
  std::vector<std::vector<T>> mat_;
};


// Functions for not in place changes.
template <class T>
Matrix<T> Transpose(const Matrix<T>& matrix);
template <class T>
Matrix<T> RowAddition(const Matrix<T>& matrix, size_t add_to, size_t add_from);
template <class T>
Matrix<T> RowMultiplication(const Matrix<T>& matrix, size_t row, T value);
template <class T>
Matrix<T> RowSwitch(const Matrix<T>& matrix, size_t row1, size_t row2);

} // namespace delgon
#include "matrix.h_inline"
#endif // MATRIX_H_
