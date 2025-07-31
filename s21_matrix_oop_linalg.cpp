#include "s21_matrix_oop.h"

/* LINALG OPERATIONS */

/*
    Checks, if matrix other is equal to this
    If sizes of matrixes are not equal, returns false,
    else check matrixes element-wise
*/
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  if (&other == this) return true;

  bool res = true;

  for (int i = 0; i < rows_ && res; i++) {
    for (int j = 0; j < cols_ && res; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) >= EPSILON) res = false;
    }
  }

  return res;
}

/*
    Adds other to current matrix
    If sizes of matrixes are not equal, throws out_of_range
*/
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::out_of_range("Matrxes must have the same size");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

/*
    Subtract other from current matrix
    If sizes of matrixes are not equal, throws out_of_range
*/
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::out_of_range("Matrxes must have the same size");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

/*
    Multiplicate matrix by number element-wise
*/
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

/*
    Multiplicate current and "other" matrixes
    If multiplication is impossible (current matrix rows num != other matrix
  columns num) throws out_of_range
*/
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Number of columns in left matrix must be equal to number of rows in "
        "right matrix");
  }

  if (this == &other) {
    S21Matrix tmp(*this);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        matrix_[i][j] = 0;
        for (int k = 0; k < cols_; k++) {
          matrix_[i][j] += tmp.matrix_[i][k] * tmp.matrix_[k][j];
        }
      }
    }

  } else {
    S21Matrix tmp(*this);

    SetCols(other.cols_);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        matrix_[i][j] = 0;
        for (int k = 0; k < cols_; k++) {
          matrix_[i][j] += tmp.matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
  }
}

/*
    Returns transposed matrix
*/
S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }

  return res;
}

/*
    Returns matrix of algebraic complements
    If calculation is impossible (matrix is not square-shaped), returns
   invalid_argument
*/
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix must be square (rows_ = cols_)");

  S21Matrix res(rows_, cols_);

  if (cols_ == 1) {
    res.matrix_[0][0] = 1;
  } else {
    S21Matrix minor;
    double minor_det;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        minor = GetMinor(i, j);
        minor_det = minor.Determinant();
        res.matrix_[i][j] = minor_det * pow(-1, i + j);
      }
    }
  }

  return res;
}
/*
    Returns determinant of current matrix
    If calculation is impossible (matrix is not square-shaped), returns
   invalid_argument
*/
double S21Matrix::Determinant() {
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix must be square (rows_ = cols_)");

  double res = 0;

  if (cols_ == 1) {
    return matrix_[0][0];
  } else {
    S21Matrix minor;
    double sign = 1.0, minor_det;

    for (int i = 0; i < cols_; i++) {
      minor = GetMinor(0, i);
      minor_det = minor.Determinant();
      res += sign * minor_det * matrix_[0][i];
      sign = -sign;
      // destructor for minor called, no memory leaks
    }
  }

  return res;
}

/*
    Returns inverse matrix of current one
    If calculation is impossible (matrix is not square-shaped), returns
   invalid_argument
*/
S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();

  S21Matrix res;

  if (fabs(det) < EPSILON)
    throw std::invalid_argument("Matrix determinant is 0");
  else {
    res = CalcComplements();
    res = res.Transpose();
    res *= 1.0 / det;
  }

  return res;
}

/*
    Returns minor of current matrix with where row with number row_exc
    and column with number col_exc are removed
*/
S21Matrix S21Matrix::GetMinor(int row_exc, int col_exc) {
  S21Matrix res(rows_ - 1, cols_ - 1);
  int i_res = 0, j_res = 0;

  for (int i = 0; i < rows_; i++) {
    if (i != row_exc) {
      for (int j = 0; j < cols_; j++) {
        if (j != col_exc) {
          res.matrix_[i_res][j_res] = matrix_[i][j];
          j_res++;
        }
      }
      i_res++;
    }
    j_res = 0;
  }

  return res;
}