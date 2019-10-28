#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(T,T,T);
    Matrix(T,T,char);
    void transpose();
    void printMatrix();
    void printMatrix(char *file);
    Matrix<T> operator+ (const Matrix<T> otherMatrix);
    Matrix<T> operator= (const Matrix<T> otherMatrix);
    virtual ~Matrix();

    int determinant(T array, T n);
    void det();

private:
    T row, column, value;
    T **array;
    void createMatrix(T,T,T);
    void IdentityMatrix(T,T);
    void randomMatrix(T,T);
    void scalarOperations(T);

};

#endif // MATRIX_H
