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

  // Comparator with eps. Cast every value 'Y' to 'T' before comparison.
  template <class Y>
  bool equal(const Matrix<Y>& mat_y, T eps = 0);

 private:
  std::vector<std::vector<T>> mat_;
};


} // namespace delgon
#include "matrix.h_inline"
#endif // MATRIX_H_
