#include "Board.h"

template class Matrix<int>; 
template class Matrix<Square>;

template <typename T>
Matrix<T>::Matrix(int size1, int size2)
{
    this->size1 = size1;
    this->size2 = size2;
    arr = new T*[size1];
    for (int i = 0; i < size1; i++)
        arr[i] = new T[size2];
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < size1; i++)
    {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;

}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
{
    size1 = matrix.size1;
    size2 = matrix.size2;
    arr = new T*[size1];
    for (int i = 0; i < size1; i++)
        arr[i] = new T[size2];

    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            arr[i][j] = matrix.arr[i][j];
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix)
{
    if (this != &matrix)
    {

        for (int i = 0; i < size1; i++)
        {
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;

        size1 = matrix.size1;
        size2 = matrix.size2;

        this->arr = new T * [size1];
        for (int i = 0; i < size1; i++)
            this->arr[i] = new T[size2];

        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size2; j++)
                this->arr[i][j] = matrix.arr[i][j];
    }
    return *this;
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& matrix)
{
    if (this != &matrix)
    {
        this->size1 = matrix.size1;
        this->size2 = matrix.size2;

        this->arr = matrix.arr;

        matrix.size1 = 0;
        matrix.size2 = 0;
        matrix.arr = nullptr;

    }
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& matrix) noexcept
{
    if (this != &matrix)
    {
        for (int i = 0; i < size1; i++)
        {
            delete[] arr[i];
            arr[i] = nullptr;
        }
        delete[] arr;
        arr = nullptr;

        size1 = matrix.size1;
        size2 = matrix.size2;

        arr = matrix.arr;

        matrix.size1 = 0;
        matrix.size2 = 0;
        matrix.arr = nullptr;

    }
    return *this;
}