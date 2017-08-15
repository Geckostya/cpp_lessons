#include "matrix.h"

Matrix::Matrix(size_t r, size_t c) {
    
}

Matrix::~Matrix() {

}

size_t Matrix::get_rows() { return 0; }
size_t Matrix::get_cols() { return 0; }

void Matrix::set(size_t i, size_t j, int value) {
}

int Matrix::get(size_t i, size_t j) {
    return 0;
}

void Matrix::print(FILE* f) {
}

bool Matrix::operator==(Matrix& m) {
    return true;
}

bool Matrix::operator!=(Matrix& m) {
    return false;
}

Matrix& Matrix::operator+=(Matrix& m) {
    return *this;
}

Matrix& Matrix::operator-=(Matrix& m) {
    return *this;
}

Matrix& Matrix::operator*=(Matrix& m) {
    return *this;
}


Matrix operator+(Matrix& left, Matrix& right) {

}
Matrix operator-(Matrix& left, Matrix& right) {

}
Matrix operator*(Matrix& left, Matrix& right) {

}

// ??? operator[](size_t ind) {}