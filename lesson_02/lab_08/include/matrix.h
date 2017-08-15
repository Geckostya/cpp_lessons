#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include <cstdio>

class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    ~Matrix();

    size_t get_rows();
    size_t get_cols();
    void set(size_t i, size_t j, int value);
    int get(size_t i, size_t j);
    void print(FILE *file);

    friend Matrix operator+(Matrix& left, Matrix& right);
    friend Matrix operator-(Matrix& left, Matrix& right);
    friend Matrix operator*(Matrix& left, Matrix& right);

    Matrix& operator+=(Matrix& m);
    Matrix& operator-=(Matrix& m);
    Matrix& operator*=(Matrix& m);

    // ??? operator[](size_t ind); не забудь про проблему с константной матрицей

    bool operator==(Matrix& m);
    bool operator!=(Matrix& m);
private:
    size_t _rows;
    size_t _cols;
    int **_data;
};

#endif
