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
        cout << "Unable to open file";
}

template <typename T> void Matrix<T>::transpose()
{
    Matrix<int> *temp = new Matrix<int>(this->row,this->column,0);
    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->column; j++)
        {
            temp->array[i][j] = this->array[j][i];
        }
    }
    temp->printMatrix();
}

/*
template <typename T> void Matrix<T>::operator +(Matrix<T> x){
  Matrix<int> *mat = new Matrix<int>(this->row,this->column,0);
          for(int i=0; i<3; i++)
        {
                for(int j=0; j<3; j++)
                {
                        mat->array[i][j]= this->array[i][j]+x.array[i][j];
                }
        }
        mat->printMatrix();
}
*/

template<typename T> Matrix<T> Matrix<T>::operator+(const Matrix<T> otherMatrix)
{
    Matrix<int> *temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            temp->array[i][j] = this->array[i][j] + otherMatrix.array[i][j];
        }
    }




    cout<<"+ Operator Overloading"<<endl;
    temp->printMatrix();
    return (*temp);
}

template<typename T> Matrix<T> Matrix<T>::operator=(const Matrix<T> otherMatrix)
{
    // Matrix<int> *temp = new Matrix<int>(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            this->array[i][j] = otherMatrix.array[i][j];
        }
    }
   // cout<<" = Operator Overloading"<<endl;
    return *this;
}


template <typename T>int Matrix<T>::determinant(T array, T n)
{
    int det = 0;
    int submatrix[n][n];

    if (n == 2)
        return ((  this->array[0][0]* this->array[1][1]) - (this->array[1][0] * this->array[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = this->array[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * this->array[0][x] * determinant( submatrix[n][n], n - 1 ));
        }
    }
    return det;
}

/*
template <typename T> void Matrix<T>::det(){

    Matrix<int> *temp = new Matrix<int>(this->row,this->column,0);
  //  int determinant=0;

    //if (this->row==2 && this->column==2)
      // determinant= (( this->array[0][0] * this->array[1][1]) - (this->array[1][0] * this->array[0][1]));
       //cout<<determinant<<endl;
    // determinant(this->array,this->column);
}

*/






//Hata vermemesi icin
template class Matrix<int>;
//Yikici fonksiyon
template <typename T> Matrix<T>::~Matrix()
{
    delete array;
}
