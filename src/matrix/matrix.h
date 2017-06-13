#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

using std::vector;

template <class T>
class Matrix {
 public:
  // Constructors.
  Matrix(const T& mat);
  Matrix(size_t rows, size_t columns);
  Matrix(size_t rows, size_t columns, T base_value);

  // Getters
  size_t rows() const;
  size_t columns() const;
  const vector<vector<T>>& mat() const;

  // Iterators.
  typedef typename vector<T>::iterator iterator;
  typename vector<vector<T>>::iterator begin();
  typename vector<vector<T>>::iterator end();

  typedef typename vector<T>::const_iterator const_iterator;
  typename vector<vector<T>>::const_iterator begin() const;
  typename vector<vector<T>>::const_iterator end() const;

  // Operators.
  vector<T>& operator[] (size_t id);
  const vector<T>& operator[] (size_t id) const;
  bool operator== (const Matrix<T>& rhs) const;
  bool operator!= (const Matrix<T>& rhs) const;
  template <class Y> Matrix<T>& operator= (const Matrix<Y>& rhs);

  // Comparator with eps.
  template <class Y>
  bool equal(const Matrix<Y>& mat_y, T eps = 0);

 private:
  vector<vector<T>> mat_;
};


#include "matrix.h_inline"
#endif // MATRIX_H_
