#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(T,T,T);
    Matrix(T,T,char);
    Matrix<T>& transpose();
    void printMatrix();
    void printMatrix(char *file);
    Matrix<T>& operator+ (Matrix<T> const& otherMatrix);
    Matrix<T>& operator- (Matrix<T> const& otherMatrix);
    Matrix<T>& operator* (Matrix<T> const& otherMatrix);
    Matrix<T>& operator+ (T);
    Matrix<T>& operator- (T);
    Matrix<T>& operator* (T);
    Matrix<T>& operator/ (T);
    Matrix<T>& operator% (T);
    Matrix<T>& operator^ (T);

    virtual ~Matrix();

    int determinant(T array, T n);
    void det();

private:
    T row, column, value;
    T **array;
    Matrix<int> *temp;
    void createMatrix(T,T,T);
    void IdentityMatrix(T,T);
    void randomMatrix(T,T);
    Matrix<T>& scalarOperations(T);

};

#endif // MATRIX_H
