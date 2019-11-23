#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(T,T);
    Matrix(T,T,T);
    Matrix(T,T,char);
    Matrix<T>& transpose();
    T determinant(Matrix<T>);
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

    T det();
    T inv();
    Matrix<T>& emul(Matrix<T> const& otherMatrix);
    T resize(int row, int column,int value);
    void createMatrix(T,T,T);




    virtual ~Matrix();
protected:
        T **array;
        T row, column, value;

    Matrix<int> *temp;

private:


    void IdentityMatrix(T,T);
    void randomMatrix(T,T);
    Matrix<T>& scalarOperations(T);

    T inv(const Matrix<T> m);



};

#endif // MATRIX_H
