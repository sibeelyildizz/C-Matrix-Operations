#include "Matrix.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string.h>
#include <fstream>  //file
#include <math.h>
#include <algorithm>


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
            array[i][j]=rand() %5;
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
template<typename T> T Matrix<T>::det()
{
    return Matrix<T>::determinant(*this);
}
template<typename T> T  Matrix<T>::determinant(Matrix<T> matrix)
{

    int c, subi, i, j, subj, d=0;

    temp = new Matrix<int>(this->row,this->column,0);
    if (this->column == 2)
    {
        d= (this->array[0][0] * this->array[1][1]) - (this->array[1][0] * this->array[0][1]);
        cout<<d<<endl;
    }
    else
    {
        for(c = 0; c < this->column; c++)
        {
            subi = 0;
            for(i = 1; i < this->column; i++)
            {
                subj = 0;
                for(j = 0; j < this->column; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    temp->array[subi][subj] = this->array[i][j];
                    subj++;

                }
                subi++;
            }
            d = d + (pow(-1,c) * this->array[0][c] * determinant(*temp));

        }

        cout<<d<<endl;
    }

    return d;
}




template<typename T> T Matrix<T>::inv()
{
    return Matrix<T>::inv(*this);
}
template<typename T> T Matrix<T>::inv(const Matrix<T> m)
{
    //determinant hesabý

    double kof[3][3],ters[3][3],ters1[2][2],a[2][2];
    int det;

    if(this->column==2 && this->row==2)
    {
        det=this->array[0][0]*this->array[1][1]-this->array[0][1]*this->array[1][0];

        if (det!=0)
        {
            a[0][0]=this->array[1][1];
            a[0][1]=this->array[0][1]*(-1);
            a[1][0]=this->array[1][0]*(-1);
            a[1][1]=this->array[0][0];
            for(int i=0; i<2; i++)
            {
                for(int j=0; j<2; j++)
                {
                    ters1[i][j] = a[i][j]/det;//tersinin alýnma iþlemi
                }
            }

            for(int i=0; i<=1; i++)
            {
                for(int j=0; j<=1; j++)
                {
                    cout<<ters1[i][j]<<"   ";
                }
                cout<<endl;
            }

        }
        else
            cout<<"matrisin tersi yoktur "<<endl;


    }
    else
    {
        int determinant=0;
        determinant = (this->array[0][0]*((this->array[1][1]*this->array[2][2])-(this->array[1][2]*this->array[2][1]))-this->array[0][1]*((this->array[1][0]*this->array[2][2])-(this->array[1][2]*this->array[2][0]))+this->array[0][2]*((this->array[1][0]*this->array[2][1]-this->array[1][1]*this->array[2][0])));



        if (determinant!=0)
        {
//kofaktör matrisi oluþturulmasý
            kof[0][0]= (this->array[1][1]*this->array[2][2]-this->array[1][2]*this->array[2][1]);
            kof[0][1]= -(this->array[1][0]*this->array[2][2]-this->array[1][2]*this->array[2][0]);
            kof[0][2]= (this->array[1][0]*this->array[2][1]-this->array[1][1]*this->array[2][0]);
            kof[1][0]= -(this->array[0][1]*this->array[2][2]-this->array[0][2]*this->array[2][1]);
            kof[1][1]= (this->array[0][0]*this->array[2][2]-this->array[0][2]*this->array[2][0]);
            kof[1][2]= -(this->array[0][0]*this->array[2][1]-this->array[0][1]*this->array[2][0]);
            kof[2][0]= (this->array[0][1]*this->array[1][2]-this->array[1][1]*this->array[0][2]);
            kof[2][1]= -(this->array[0][0]*this->array[1][2]-this->array[1][0]*this->array[0][2]);
            kof[2][2]= (this->array[0][0]*this->array[1][1]-this->array[1][0]*this->array[0][1]);

            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    ters[i][j] = kof[i][j]/determinant;//tersinin alýnma iþlemi
                }
            }

            for(int j=0; j<=2; j++)
            {
                for(int i=0; i<=2; i++)
                {
                    cout<<ters[i][j]<<"      ";
                    cout<<ters[i][j]<<"      ";
                }
                cout<<endl;
            }
        }
        else
            cout<<"matrisin tersi yoktur "<<endl;
    }
}

template<typename T> Matrix<T>& Matrix<T>::emul(Matrix<T> const& otherMatrix)
{
    temp = new Matrix<int>(this->row,this->column,0);
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->column; ++j)
        {
            temp->array[i][j] = this->array[i][j] * otherMatrix.array[i][j];


        }
    }
    return (*temp);
}
template<typename T> T Matrix<T>::resize(int row, int column,int value)
{
    if (row < 0 || column < 0)
    {
        cout << "Invalid resize";
        return 0;
    }

    //  int newsize = row * column;
    temp = new Matrix<int>(this->row,this->column,0);


    // for(int i=0; i<newsize; i += 1) {
    //   temp->array[i] = 0;
    //}
    for(int i=0; i<row; i += 1)
    {
        for(int j=0; j<column; j += 1)
        {
            temp->array[j+i*column] = array[j+i*this->column];
        }
    }
    delete [] array;
    array = temp->array;
    //  size = newsize;
    this->row = row;
    this->column = column;
    this->value=value;

}
//Hata vermemesi icin
template class Matrix<int>;
//Yikici fonksiyon
template <typename T> Matrix<T>::~Matrix()
{
    delete array;
    delete temp;
}
