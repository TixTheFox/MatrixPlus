#include "s21_matrix_oop.h"

/* OPERATORS */

/*
    Returns reference to matrix element with index [i, j]
    If one of indexes is out of index range, throws out_of_range
*/
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
    throw std::out_of_range("Indeces not in matrix ranges");
  return matrix_[i][j];
}

/*
    Copies matrix "other" in current matrix using assignment operator
*/
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;

  CleanMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    memcpy(matrix_[i], other.matrix_[i], sizeof(double) * cols_);
  }

  return *this;
}

/*
    Moves matrix "obj" in current matrix using assignment operator
*/
S21Matrix& S21Matrix::operator=(S21Matrix&& obj) {
  if (this == &obj) return *this;

  this->CleanMatrix();
  rows_ = obj.rows_;
  cols_ = obj.cols_;
  matrix_ = obj.matrix_;

  obj.rows_ = 0;
  obj.cols_ = 0;
  obj.matrix_ = nullptr;

  return *this;
}

/*
    Adds current matrix and "other" and returns as result (current matrix isn't
   changed) If matrixes size aren't equal, throws invalid_argument
*/
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrixes must have the same size");

  S21Matrix res(*this);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[i][j] += other.matrix_[i][j];
    }
  }
  return res;
}

/*
    Substitudes "other" matrix from current one and returns as result (current
   matrix isn't changed) If matrixes size aren't equal, throws invalid_argument
*/
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrxes must have the same size");

  S21Matrix res(*this);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[i][j] -= other.matrix_[i][j];
    }
  }
  return res;
}

/*
    Multiplies current matrix with number num and returns as result (current
   matrix isn't changed)
*/
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[i][j] *= num;
    }
  }

  return res;
}

/*
    Multiplies current matrix with matrix "other" and returns as result (current
   matrix isn't changed) If multiplication is impossible (current matrix rows
   num != other matrix columns num) throws invalid_argument
*/
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "Number of columns in left matrix must be equal to number of rows in "
        "right matrix");

  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      res.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  return res;
}

/*
    Adds other to current matrix
    If sizes of matrixes are not equal, throws out_of_range
*/
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

/*
    Subtract other from current matrix
    If sizes of matrixes are not equal, throws out_of_range
*/
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

/*
    Multiplicate current and "other" matrixes
    If multiplication is impossible (current matrix rows num != other matrix
   columns num) throws out_of_range
*/
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

/*
    Multiplicate matrix by number element-wise
*/
S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}