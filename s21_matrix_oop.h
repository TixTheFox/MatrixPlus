#ifndef S21_MATRIX
#define S21_MATRIX

#include <cmath>
#include <iostream>
#include <string.h>

#define EPSILON 1e-7

class S21Matrix {
    private:
        int rows_, cols_;
        double** matrix_;

        S21Matrix GetMinor(int row_exc, int col_exc);
        void CleanMatrix();

    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& obj);
        S21Matrix(S21Matrix&& obj);
        ~S21Matrix();

        int GetRows() { return rows_; }
        int GetCols() { return cols_; }
        void SetRows(int val);
        void SetCols(int val);

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();

        bool operator==(const S21Matrix& other) { return this->EqMatrix(other); };
        double& operator()(int i, int j);
        S21Matrix& operator=(const S21Matrix& other);
        S21Matrix& operator=(S21Matrix&& obj);
        S21Matrix operator+(const S21Matrix& other);
        S21Matrix operator-(const S21Matrix& other);
        S21Matrix operator*(const double num);
        S21Matrix operator*(const S21Matrix& other);
        S21Matrix& operator+=(const S21Matrix& other);
        S21Matrix& operator-=(const S21Matrix& other);
        S21Matrix& operator*=(const S21Matrix& other);
        S21Matrix& operator*=(const double num);
};

#endif // S21_MATRIX