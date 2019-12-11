///SİBEL YILDIZ 330071
///



#ifndef OOP1_MATRIX_H
#define OOP1_MATRIX_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;
template <typename T> class Matrix
{
public:
    Matrix(); // varsayılan 10 * 10 luk içerisi 0 olan constructor
    Matrix(int,int,T); // satir * sutunluk değer içeren constructor
    Matrix(int,int,char);// satır * sutunluk random veya birim constructor
    Matrix<T> transpose();
    void printMatrix(); // Ekrana yazdirma
    void printMatrix(char *file); // Dosyaya yazdirma
    Matrix<T> emul(Matrix<T> const& matrix); // Eleman düzeyinde çarpma
    Matrix<T>  operator+ (Matrix<T> const& otherMatrix);//+ operatorü ile 2 matris toplamı
    Matrix<T> operator- (Matrix<T> const& otherMatrix);
    Matrix<T> operator* (Matrix<T> const& otherMatrix);
    Matrix<T>& operator+ (T); // matris ile bir sayının toplamı
    Matrix<T>& operator- (T);
    Matrix<T>& operator* (T);
    Matrix<T>& operator/ (T);
    Matrix<T>& operator% (T);
    Matrix<T>& operator^ (T);
    T det(); // Matris determinantı
    void inv(); // Matris tersi
    Matrix<T> resizeMatrix(int,int); // Gelen matrisi yeniden boyutlandırma
    ~Matrix();

protected:

    T **array;
    int  row, column;
    T value;
private:
    Matrix<T> *temp{}; // Ara işlemler için kullanılacak olan geçici matris
    void IdentityMatrix(int,int); // Birim matris fonksiyonu
    void randomMatrix(int,int); // Random matris fonksiyonu
    Matrix<T>& scalarOperations(T); // Skaler işlemler için geliştirilen fonksiyon
    T calculateDeterminant(Matrix<T> const&,T); // Determinant hesabı için yardımcı fonksiyon
    void createMatrix(int,int,T); // Matris oluşturma fonksiyonu
    void showErrorMessage(char *msg); // hata mesajı gösterme fonksiyonu
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
template<typename T>
void Matrix<T>::inv(){
    Matrix<T> temp(this->row,this->column,0);
    float d,k;
    for(int i=0;i<this->row;i++){
        d=this->array[i][i];
        for(int j=0;j<this->column;j++){
            this->array[i][j]=this->array[i][j]/d;
            temp.array[i][j]=temp.array[i][j]/d;
        }
        for(int x=0;x<this->row;x++){
            if(x!=i){
                k=this->array[x][i];
                for(int j=0;j<this->column;j++){
                    this->array[x][j]=this->array[x][j]-(this->array[i][j]*k);
                    temp.array[x][j]=temp.array[x][j]-(temp.array[i][j]*k);
                }
            }
        }
    }
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++){
            this->array[i][j]=temp.array[i][j];
        }
    }

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
    delete temp;
   // delete array;
}

#endif //OOP1_MATRIX_H


#ifndef TABLE_H
#define TABLE_H
//#include "Matrix.h"
#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;


template <typename T>
class Table : public Matrix<T>
{
public:
    Table() :Matrix<T>::Matrix() {}    //inheritance constructor

    Table(T _row,T _column,T _value):Matrix<T>::Matrix(_row,_column,_value) {} //inheritance constructor
    Table(T _row,T _column,char ch):Matrix<T>::Matrix(_row,_column,ch) {}  //inheritance constructor
    void printTable();
    T itemAt(int r,int c);
    T itemAt(string s);
    T itemAt(string rs,string cs);

    ~Table();


    Table(const Table& other);

protected:

private:
    string rowName = {"ABCDEFGHIJKLMNOPQRSTUVYXWZ"};
    int cName = 1;
};

template<typename T>
void Table<T>::printTable()
{
    cout<<" ********* PRINT TABLE ********** " <<endl;
    cout<<"  ";
    for(int i=0; i<this->column; i++)


        cout<<cName++<<" \t";

    cout<<endl;
    for(int i=0; i<this->row; i++)
    {
        cout<<rowName[i]<<" ";

        for(int j=0; j<this->column; j++)
        {


            cout<< this->array[i][j]<<"\t";
        }
        cout<<endl;
    }
}
template <typename T>
T Table<T>::itemAt(int r, int c)
{

    return this->array[r][c];
}
template <typename T>
T Table<T>::itemAt(string s) //  D4
{
    int index1=0,index2=0;
    for(int i=0; i<rowName.size(); i++)
    {
        if (s[0]==rowName[i])
        {
            index1 = i;
            break;
        }
    }

    index2 = (s[1]-'0')-1;  //s dizisinin 1. indisindeki elemaný integer'a cevirme
    if(index1<=this->column+1 && index2<=this->row+1)  // sütun 0dan başladıgı için kontrol ederken +1 verdik.aksi alde dizinin son sütununa erişemezdik
        return this->array[index1][index2];
    else
    {
        cout<<endl;
        cout<<"Dizi sinirlari asildi"<<endl;
        return 0;
    }
}
template <typename T>
T Table<T>::itemAt(string rs,string cs)
{
    int index1=0,index2=0;
    index1 = rs[0]-'0';  //s dizisinin 0. indisindeki elemaný integer'a cevirme
    for(int i=0; i<rowName.size(); i++) //sutunu rowNamede bulma
    {
        if (cs[0]==rowName[i])
        {
            index2 = i;
            break;
        }
    }
    if(index1<=this->column+1 && index2<=this->row+1)
    {
        return this->array[index2][index1-1];
    }
    else
    {
        cout<<endl;
        cout<<"Dizi sinirlari asildi"<<endl;
        return 0;
    }
}


#endif // TABLE_H

//#include "Matrix.h"
//#include "Table.h"
#include <iostream>
using namespace std;

int main()
{
    //Matrix<int> *m1 = new Matrix<int>();  m1->printMatrix(); //pointer olarak tanimlam Matrix<int> m1(4,4,'r'); //nesne olarak tanimlama
    //Matrix<int> *m2 = new Matrix<int>(3,2,1);  m2->printMatrix();
    //Matrix<int> *m2 = new Matrix<int>(3,4,9);  m2->printMatrix();
    //Matrix<int> *m3 = new Matrix<int>(5,5,'e'); m3->printMatrix();
    //Matrix<int> *m4 = new Matrix<int>(5,5,'r'); m4->printMatrix();*m4 = *m4 + 3.0; m4->printMatrix();
     // Matrix<int> *m5 = new Matrix<int>(4,4,8);  m5->printMatrix();// Matrix<int> m1(4,4,'r'); //nesne olarak tanimlama
   // Matrix<int> *m6 = new Matrix<int>(4,4,'r'); m6->printMatrix();
    //Matrix<int> *m7 = new Matrix<int>(3,3,'r'); m7->printMatrix();
    //*m2 = (m2)->resizeMatrix(1,6);   m2->printMatrix();




  //  (*m6)=(*m6)+(*m6);m6->printMatrix();
    //(*m5)=(*m5)-(*m6);m5->printMatrix();
    //(*m5)=(*m5)*(*m6);m5->printMatrix();
    //(*m5) = (*m5)+2; m5->printMatrix();
    //(*m5) = (*m5)-20; m5->printMatrix();
    //(*m5) = (*m5)*10; m5->printMatrix();
    //(*m5) = (*m5)/4; m5->printMatrix();
    //(*m5) = (*m5)%5; m5->printMatrix();
    //(*m5) = (*m5)^2; m5->printMatrix();

    //m2->printMatrix("deneme.txt");
    //*m6=m6->transpose(); m6->printMatrix();
    //(*m5)=m5->emul(*m6);   m5->printMatrix();
    //cout<<m7->det();
   //m6->inv(); m6->printMatrix();



  //  Table<int> *m8 = new Table<int>(); m8->printMatrix();
  //  Table<int> *m9 = new Table<int>(3,4,5); m9->printTable();
     Table<int> *m10 = new Table<int>(3,4,'r'); m10->printTable();


    //cout << m10->itemAt(2,2)<<endl;  // derived clas

    //cout<< m10->itemAt("1","A")<<endl;

    cout<< m10->itemAt("B4");




    return 0;
}
