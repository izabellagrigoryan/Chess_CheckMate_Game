#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix {
public:
    int size1;
    int size2;

    T** arr;
    Matrix(int size1, int size2);
    ~Matrix();
    Matrix(const Matrix<T>& matrix);
    Matrix<T>& operator=(const Matrix<T>& matrix);
    Matrix(Matrix<T>&& matrix);
    Matrix<T>& operator=(Matrix<T>&& matrix) noexcept;

};

#endif