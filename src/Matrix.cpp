#include "Matrix.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream>  //file
#include <math.h>
using namespace std;

/************************************************************************************/
//                      KURUCU FONKSIYONLAR
/************************************************************************************/
//parametresiz kurucu
template <typename T> Matrix<T>::Matrix()
{
    this->column = 10;
    this->row = 10;
    this->value = 0;
    createMatrix(this->column, this->row,  this->value);


}
// parametreli kurucu
template <typename T> Matrix<T>::Matrix(T r,T c, T v)
{
    this->row = r;
    this->column = c;
    this->value = v;
    createMatrix(r,c,v);

}
// Birim matris veya random matris icin kurucu fonksiyon
template <typename T> Matrix <T>::Matrix(T r, T c,char v)
{

    this->column = c;
    this->row = r;
    this->value = v;

    if(v=='e')
        IdentityMatrix(r,c);
    else if(v=='r')
        randomMatrix(r,c);
    else
        cout<< "Gonderilen parametrelerde problem var "<< endl;
}

/**********************************************************************/
//                  PRIVATE FONKSIYONLAR
/**********************************************************************/

// Matris olusturma fonksiyonu
template <typename T> void Matrix <T>::createMatrix(T r,T c, T v)
{
    this->array = new T*[row];
    for (int i=0; i<row; i++)
    {
        array[i] = new T[column];
    }


    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            array[i][j] = this->value;
        }
    }
}

// Birim matris
template <typename T> void Matrix <T>::IdentityMatrix(T r,T c)
{
    this->array = new T*[row];
    for (int i=0; i<row; i++)
    {
        array[i] = new T[column];
    }

    for(int i = 0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(i==j)
                array[i][j] = 1;
            else
                array[i][j] = 0;
        }
    }
}

// Random Matris
template <typename T> void Matrix <T>::randomMatrix(T r,T c)
{

    this->array = new T*[row];
    for (int i=0; i<row; i++)
    {
        array[i] = new T[column];
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            array[i][j]=rand() %255;
        }
    }
}

template <typename T> Matrix<T>& Matrix<T>::scalarOperations(T productValue)
{
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

/***********************************************************/
//                   PUBLIC FONKSIYONLAR
/***********************************************************/
// Matris yazdirma islemi
template <typename T> void Matrix<T>::printMatrix()
{
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
template <typename T> void Matrix<T>::printMatrix(char *file)
{
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

template <typename T> Matrix<T>& Matrix<T>::transpose()
{
    temp = new Matrix<int>(this->row,this->column,0);
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->column; j++)
        {
            temp->array[i][j] = this->array[j][i];
        }
    }
    return *temp;
}

template<typename T> Matrix<T>& Matrix<T>::operator+(Matrix<T> const& otherMatrix)
{
    temp = new Matrix<int>(this->row,this->column,0);
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            temp->array[i][j] = this->array[i][j] + otherMatrix.array[i][j];
        }
    }
    return (*temp);
}

template<typename T> Matrix<T>& Matrix<T>::operator+(T sumValue)
{
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            this->array[i][j] = this->array[i][j] + (scalarOperations(sumValue)).array[i][j];
        }
    }
    return (*this);
}

template<typename T> Matrix<T>& Matrix<T>::operator-(Matrix<T> const& otherMatrix)
{
    temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            temp->array[i][j] = this->array[i][j] - otherMatrix.array[i][j];
        }
    }
    return (*temp);
}

template<typename T> Matrix<T>& Matrix<T>::operator-(T subValue)
{
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            this->array[i][j] = this->array[i][j] - (scalarOperations(subValue)).array[i][j];
        }
    }
    return (*this);
}

template<typename T> Matrix<T>& Matrix<T>::operator*(Matrix<T> const& otherMatrix)
{
    temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            for (int k = 0; k < this->column; k++)
            {
                temp->array[i][j] += this->array[i][k] * otherMatrix.array[k][j];
            }
        }
    }
    return (*temp);
}
template<typename T> Matrix<T>& Matrix<T>::operator*(T productValue)
{

    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            this->array[i][j]=this->array[i][j]*productValue;
        }
    }
    return (*this);

}
template<typename T> Matrix<T>& Matrix<T>::operator/(T divValue)
{
    if(divValue==0)
    {
        cout<< "*******************\nSifira bolme hatasi alindi\nOrjinal matris tekrar gonderildi...\n*******************" << endl;
    }

    else
    {
        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->column; ++j)
            {
                this->array[i][j]=this->array[i][j]/divValue;
            }
        }
    }
    return (*this);
}
template<typename T> Matrix<T>& Matrix<T>::operator%(T modValue)
{
    if(modValue==0)
    {
        cout<< "*******************\nSifira bolme hatasi alindi\nOrjinal matris tekrar gonderildi...\n*******************" << endl;
    }

    else
    {
        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->column; ++j)
            {
                this->array[i][j]=this->array[i][j]%modValue;
            }
        }
    }
    return (*this);
}
template<typename T> Matrix<T>& Matrix<T>::operator^(T upValue)
{



        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->column; ++j)
            {
                this->array[i][j]=pow(this->array[i][j],upValue);
            }
        }

    return (*this);
}

//Hata vermemesi icin
template class Matrix<int>;
//Yikici fonksiyon
template <typename T> Matrix<T>::~Matrix()
{
    delete array;
    delete temp;
}
