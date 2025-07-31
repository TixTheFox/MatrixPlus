#include "s21_matrix_oop.h"

/* CONSTRUCTORS */

/*
    Creates matrix with default values (rows = cols = 3)
*/
S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

/*
    Creates matrix with defined number of rows and cols
*/
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("Exception: rows and cols must be positive");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

/*
    Copies matrix obj into created matrix
*/
S21Matrix::S21Matrix(const S21Matrix& obj)
    : rows_(obj.rows_), cols_(obj.cols_) {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    memcpy(matrix_[i], obj.matrix_[i], sizeof(double) * cols_);
  }
}

/*
    Moves matrix obj into created matrix
*/
S21Matrix::S21Matrix(S21Matrix&& obj)
    : rows_(obj.rows_), cols_(obj.cols_), matrix_(obj.matrix_) {
  obj.rows_ = 0;
  obj.cols_ = 0;
  obj.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { CleanMatrix(); }

/* MUTATORS */

/*
    Sets rows attribute equal to val
    If val < rows, matrix size is decreased
    If val > rows, matrix size increases, new fileds initialized with 0
*/
void S21Matrix::SetRows(int val) {
  if (val <= 0) throw std::invalid_argument("Val must be positive value");

  if (val > rows_) {
    double** tmp = matrix_;

    matrix_ = new double*[val];
    memcpy(matrix_, tmp, sizeof(double*) * rows_);
    for (int i = rows_; i < val; i++) {
      matrix_[i] = new double[cols_]();
    }

    delete[] tmp;

  } else if (val < rows_) {
    for (int i = val; i < rows_; i++) {
      delete[] matrix_[i];
    }

    double** tmp = matrix_;
    matrix_ = new double*[val];
    memcpy(matrix_, tmp, sizeof(double*) * val);
    delete[] tmp;
  }

  rows_ = val;
}

/*
    Sets cols attribute equal to val
    If val < cols, matrix size is decreased
    If val > cols, matrix size increases, new fileds initialized with 0
*/
void S21Matrix::SetCols(int val) {
  if (val <= 0) throw std::invalid_argument("Val must be positive value");

  if (val > cols_) {
    for (int i = 0; i < rows_; i++) {
      double* tmp = matrix_[i];
      matrix_[i] = new double[val]();
      memcpy(matrix_[i], tmp, sizeof(double) * cols_);
      delete[] tmp;
    }

  } else if (val < cols_) {
    for (int i = 0; i < rows_; i++) {
      double* tmp = matrix_[i];
      matrix_[i] = new double[val];
      memcpy(matrix_[i], tmp, sizeof(double) * val);
      delete[] tmp;
    }
  }

  cols_ = val;
}

/*
    Deletes allocated memory in matrix_ attr
*/
void S21Matrix::CleanMatrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}