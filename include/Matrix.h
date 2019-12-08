#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <time.h>

#ifndef OOP1_MATRIX_H
#define OOP1_MATRIX_H


using namespace std;
template <typename T> class Matrix
{
public:
    Matrix();
    Matrix(int,int,T);
    Matrix(int,int,char);
    Matrix<T> transpose();
    void printMatrix();
    void printMatrix(char *file);
    Matrix<T> emul(Matrix<T> const& matrix);
    Matrix<T>  operator+ (Matrix<T> const& otherMatrix);
    Matrix<T> operator- (Matrix<T> const& otherMatrix);
    Matrix<T> operator* (Matrix<T> const& otherMatrix);
    Matrix<T>& operator+ (T);
    Matrix<T>& operator- (T);
    Matrix<T>& operator* (T);
    Matrix<T>& operator/ (T);
    Matrix<T>& operator% (T);
    Matrix<T>& operator^ (T);
    T det();
    T inv();
    Matrix<T> resizeMatrix(int,int);

    ~Matrix();



protected:

    T **array;
    int  row, column;
    T value;
private:
    Matrix<T> *temp{};
    void IdentityMatrix(int,int);
    void randomMatrix(int,int);
    Matrix<T>& scalarOperations(T);
    T calculateDeterminant(Matrix<T> const&,T);
    T calculateInverse(Matrix<T> const&);
    void createMatrix(int,int,T);
    void showErrorMessage(char *msg);
};

/************************************************************************************/
//                            KURUCU FONKSIYONLAR
/************************************************************************************/
//Parametresiz Kurucu
template<typename T>
Matrix<T>::Matrix()
{
    this->column = 10;
    this->row = 10;
    this->value = 0;
    createMatrix(this->row,this->column,this->value);
}

// Parametreli Kurucu
template<typename T>
Matrix<T>::Matrix(int _row, int _column, T _value)
{
    this->row = _row;
    this->column = _column;
    this->value = _value;
    createMatrix(_row,_column,_value);
}

// Birim matris veya random matris icin kurucu fonksiyon
template<typename T>
Matrix<T>::Matrix(int _row, int _column, char _value)
{
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
void Matrix<T>::createMatrix(int r, int c, T v)
{
    this->array = new T*[r];

    for (int i=0; i < r; i++)
        array[i] = new T[c];

    for (int i=0; i < r; i++)
        for (int j=0; j < c; j++)
            array[i][j] = this->value;

}

template<typename T>
void Matrix<T>::IdentityMatrix(int r, int c)
{
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
void Matrix<T>::randomMatrix(int r, int c)
{

    this->array = new T*[row];
    for (int i=0; i<row; i++)
        array[i] = new T[column];

    srand(time(NULL));

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            array[i][j]= rand() % 255;
}

template<typename T>
Matrix<T> &Matrix<T>::scalarOperations(T productValue)
{
    temp = new Matrix<T>(this->row,this->column,1);  // int
    //temp = new Matrix<T>(this->row,this->column,1.0);  // double



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


template<typename T>
T Matrix<T>::calculateDeterminant(Matrix<T> const & mtrx, T size)
{
    if (mtrx.row == mtrx.column)
    {
        int determinant = 0;
        temp = new Matrix<int>(this->row, this->column, 1);
        if (size == 2)
        {
            return (mtrx.array[0][0] * mtrx.array[1][1]) - (mtrx.array[1][0] * mtrx.array[0][1]);
        }
        else
        {
            for (int x = 0; x < size; x++)
            {
                int subi = 0;
                for (int i = 1; i < size; i++)
                {
                    int subj = 0;
                    for (int j = 0; j < size; j++)
                    {
                        if (j == x)
                            continue;
                        temp->array[subi][subj] = mtrx.array[i][j];
                        subj++;
                    }
                    subi++;
                }
                determinant = determinant + (pow(-1, x) * mtrx.array[0][x] * calculateDeterminant(*temp, size - 1));
            }
            return determinant;
        }
    }
    else
    {
        cout << "Lutfen Kare Matris Giriniz!" << endl;
        return 0;
    }
}
template<typename T>
void Matrix<T>:: showErrorMessage(char *msg)
{
    cout<<msg<< endl;
}

/**********************************************************************/
//                 PUBLIC  FONKSIYONLAR
/**********************************************************************/


template<typename T>
Matrix<T> Matrix<T>::resizeMatrix(int r,int c )
{
    int a = this->row;
    int b = this->column;

    if ((a*b)==(r*c))
    {
        Matrix<int> outMatrix(r,c,0);
        T *dizi = new T[a*b];
        int counter =0 ;
        for(int i = 0; i<this->row; i++)
        {
            for(int j = 0; j<this->column; j++)
            {
                dizi[counter] = this->array[i][j];
                counter++;
            }
        }

        counter = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                outMatrix.array[i][j]= dizi[counter];
                counter++;
            }
        }
        return outMatrix;
    }
    else
    {
        showErrorMessage("Dizi Boyutlari Farkli");
    }
}


template<typename T>
T Matrix<T>::det()
{
    return calculateDeterminant((*this),this->row);
}

//Matris Yazdirma
template<typename T>
void Matrix<T>::printMatrix()
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
template<typename T>
void Matrix<T>::printMatrix(char *file)
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
        showErrorMessage("Dosya islemlerinde problem oldu.");
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &otherMatrix)
{
    if(this->row==otherMatrix.row && this->column==otherMatrix.column)
    {
        Matrix<T> temp(this->row, this->column,0);

        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->column; ++j)
            {
                temp.array[i][j] = this->array[i][j] + otherMatrix.array[i][j];
            }
        }
        return temp;
    }
    else
    {
        showErrorMessage("Matris boyutlari farkli!");
    }
}


template<typename T>
Matrix<T> &Matrix<T>::operator+(T sumValue)
{

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j] = this->array[i][j] + (scalarOperations(sumValue)).array[i][j];

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &otherMatrix)
{
    if(this->row==otherMatrix.row && this->column==otherMatrix.column)
    {
        Matrix<T> temp(this->row,this->column,0);

        for (int i = 0; i < this->row; ++i)
            for (int j = 0; j < this->column; ++j)
                temp.array[i][j] = this->array[i][j] - otherMatrix.array[i][j];


        return temp;
    }
    else
          showErrorMessage("Matris boyutlari farkli!");
}

template<typename T>
Matrix<T> &Matrix<T>::operator-(T subValue)
{
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j] = this->array[i][j] - (scalarOperations(subValue)).array[i][j];

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &otherMatrix)
{

    Matrix<T> temp(this->row,this->column,0);

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            for (int k = 0; k < this->column; k++)
                temp.array[i][j] += this->array[i][k] * otherMatrix.array[k][j];


    return temp;

}

template<typename T>
Matrix<T> &Matrix<T>::operator*(T productValue)
{

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j]=this->array[i][j]*productValue;

    return (*this);
}

template<typename T>
Matrix<T> &Matrix<T>::operator/(T divValue)
{

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
Matrix<T> &Matrix<T>::operator%(T modValue)
{
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
Matrix<T> &Matrix<T>::operator^(T upValue)
{
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            this->array[i][j]=pow(this->array[i][j],upValue);

    return (*this);
}

template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    temp = new Matrix<int>(this->column,this->row,0);
    for(int i=0; i<this->row; i++)
        for(int j=0; j<this->column; j++)
            temp->array[j][i] = this->array[i][j];

    return *temp;
}

template<typename T>
Matrix<T> Matrix<T>::emul(const Matrix<T> &otherMatrix)
{
    Matrix<T> temp(this->row,this->column,0);
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->column; ++j)
            temp.array[i][j] = this->array[i][j] * otherMatrix.array[i][j];


    return temp;

}
template<typename T>
Matrix<T>::~Matrix(){
    delete [] *temp;
    delete [] **array;
}

#endif OOP1_MATRIX_H
