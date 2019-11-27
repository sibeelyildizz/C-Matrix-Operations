#include <iostream>
#include <stdlib.h>
#include <fstream>

#ifndef OOP1_MATRIX_H
#define OOP1_MATRIX_H

using namespace std;
template <typename T> class Matrix {
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

    // T det();
    // T inv();
    // T resize(int row, int column,int value);
    Matrix<T>& emul(Matrix<T> const& otherMatrix);
    void createMatrix(T,T,T);


protected:

     T **array;
    T row, column, value;



private:
    Matrix<int> *temp{};
    void IdentityMatrix(T,T);
    void randomMatrix(T,T);
    Matrix<T>& scalarOperations(T);
};


/************************************************************************************/
//                            KURUCU FONKSIYONLAR
/************************************************************************************/
//Parametresiz Kurucu
template<typename T>
Matrix<T>::Matrix() {
    this->column = 10;
    this->row = 10;
    this->value = 0;
    createMatrix(this->row,this->column,this->value);
}

// Parametreli Kurucu
template<typename T>
Matrix<T>::Matrix(T _row, T _column, T _value) {
    this->row = _row;
    this->column = _column;
    this->value = _value;
    createMatrix(_row,_column,_value);
}

// Birim matris veya random matris icin kurucu fonksiyon
template<typename T>
Matrix<T>::Matrix(T _row, T _column, char _value) {
    this->row = _row;
    this->column = _column;
    this->value = _value;

    if(_value=='e')
        IdentityMatrix(_row,_column);
    else if(_value=='r')
        randomMatrix(_row,_column);
    else
        cout<< "Gonderilen parametrelerde problem var "<< endl;
}


/**********************************************************************/
//                 PRIVATE  FONKSIYONLAR
/**********************************************************************/

// Matris Olusturma
template<typename T>
void Matrix<T>::createMatrix(T r, T c, T v) {
    this->array = new T*[r];

    for (int i=0; i < r; i++)
        array[i] = new T[c];

    for (int i=0; i < r; i++)
        for (int j=0; j < c; j++)
            array[i][j] = this->value;

}


template<typename T>
void Matrix<T>::IdentityMatrix(T r, T c) {
    this->array = new T*[row];
    for (int i=0; i<row; i++)
        array[i] = new T[column];

    for(int i = 0; i<row; i++)
        for(int j=0; j<column; j++)
        {
            if(i==j)
                array[i][j] = 1;
            else
                array[i][j] = 0;
        }
}

template<typename T>
void Matrix<T>::randomMatrix(T r, T c) {

    this->array = new T*[row];
    for (int i=0; i<row; i++)
        array[i] = new T[column];


    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            array[i][j]=rand() % 5;
}

template<typename T>
Matrix<T> &Matrix<T>::scalarOperations(T productValue) {
    temp = new Matrix<int>(this->row,this->column,1);

    for(int i = 0; i<this->row; i++)
        for(int j = 0; j<this->column; j++)
        {
            if(i==j)
                temp->array[i][j] = temp->array[i][j] * productValue;

            else
                temp->array[i][j] = 0;
        }
    return *temp;
}

/**********************************************************************/
//                 PUBLIC  FONKSIYONLAR
/**********************************************************************/

//Matris Yazdirma
template<typename T>
void Matrix<T>::printMatrix() {
    cout<<" ********* PRINT MATRIX ********** " <<endl;
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->column; j++)
        {
            cout<< this->array[i][j]<<"\t";
        }
        cout<<endl;
    }
}

// Dosyaya yazdirma fonksiyonu
template<typename T>
void Matrix<T>::printMatrix(char *file) {
    ofstream myfile (file);
    if (myfile.is_open())
    {
        myfile<<" ********* PRINT MATRIX ********** " <<endl;
        for(int i=0; i<this->row; i++)
        {
            for(int j=0; j<this->column; j++)
            {
                myfile<< this->array[i][j]<<"\t";
            }
            myfile<<"\n";
        }
        myfile.close();
    }
    else
        cout << "Dosya islemlerinde problem oldu.";
}

template<typename T>
Matrix<T> &Matrix<T>::operator+(const Matrix<T> &otherMatrix) {
    temp = new Matrix<int>(this->row,this->column,0);
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            temp->array[i][j] = this->array[i][j] + otherMatrix.array[i][j];
        }
    }

    this->array = temp->array;
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+(T sumValue) {
// ornek gonderim sekli  =>  (*m1) = (*m1) + 12;

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j] = this->array[i][j] + (scalarOperations(sumValue)).array[i][j];

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-(const Matrix<T> &otherMatrix) {
    temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            temp->array[i][j] = this->array[i][j] - otherMatrix.array[i][j];

    this->array = temp->array;
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-(T subValue) {
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j] = this->array[i][j] - (scalarOperations(subValue)).array[i][j];

    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*(const Matrix<T> &otherMatrix) {
    temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            for (int k = 0; k < this->column; k++)
                temp->array[i][j] += this->array[i][k] * otherMatrix.array[k][j];

    this->array = temp->array;
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*(T productValue) {

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j]=this->array[i][j]*productValue;

    return (*this);
}

template<typename T>
Matrix<T> &Matrix<T>::operator/(T divValue) {

    if(divValue==0)
        cout<< "*******************\nSifira bolme hatasi alindi\nOrjinal matris tekrar gonderildi...\n*******************" << endl;
    else
    {
        for (int i = 0; i < this->row; ++i)
            for (int j = 0; j < this->column; ++j)
                this->array[i][j]=this->array[i][j]/divValue;
    }
    return (*this);

}

template<typename T>
Matrix<T> &Matrix<T>::operator%(T modValue) {
    if(modValue==0)
        cout<< "*******************\nSifira bolme hatasi alindi\nOrjinal matris tekrar gonderildi...\n*******************" << endl;
    else
    {
        for (int i = 0; i < this->row; ++i)
            for (int j = 0; j < this->column; ++j)
                this->array[i][j]=this->array[i][j]%modValue;
    }
    return (*this);
}

template<typename T>
Matrix<T> &Matrix<T>::operator^(T upValue) {
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j]=pow(this->array[i][j],upValue);

    return (*this);
}

template<typename T>
Matrix<T> &Matrix<T>::transpose() {
    temp = new Matrix<int>(this->row,this->column,0);

    for(int i=0; i<this->row; i++)
        for(int j=0; j<this->column; j++)
            temp->array[i][j] = this->array[j][i];


    this->array = temp->array;
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::emul(const Matrix<T> &otherMatrix) {
    temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            temp->array[i][j] = this->array[i][j] * otherMatrix.array[i][j];

    this->array = temp->array;
    return *this;

}

#endif //OOP1_MATRIX_H
