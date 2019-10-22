#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>

class Matrix
{
private:
    T row, column, value;
    void createMatrix(T,T,T);
    void IdentityMatrix(T,T);
    void randomMatrix(T,T);



public:

    //constructor prototype
    Matrix();
    Matrix(T,T,T);
    Matrix(T,T,char);




    virtual ~Matrix();
    T getRow();
    T getColumn();
    T getValue();
    void setRow(T);
    void setColumn(T);
    void setValue(T);


};
//parametreli constructor
template <class T> Matrix <T>::Matrix(T r, T c,T v)
{
    this->column = c;
    this->row = r;
    this->value = v;
    createMatrix(r,c,v);

}
template <class T> Matrix <T>::Matrix(T r, T c,char v)
{
    this->column = c;
    this->row = r;
    this->value = v;

    if(v=='e')
        IdentityMatrix(r,c);
    else if(v=='r')
        randomMatrix(r,c);
    else
        cout<< "Gönderilen parametrelerde problem var "<< endl;
}
//parametresiz constructor
template <class T> Matrix<T>::Matrix()
{
    this->column = 10;
    this->row = 10;
    this->value = 0;
    createMatrix(this->column, this->row,  this->value);
}
template <class T> void Matrix <T>::IdentityMatrix(T r,T c)
{
    int i,j;
    T matris[r][c];
    for(i=0; i<r; i++)
    {
        for(j=0; j < c; j++)
        {
            if(i!=j)
                matris[i][j] = 0;
            else
                matris[i][j] = 1;
        }
    }


    for(i=0; i<r; i++)
    {
        for(j=0; j < c; j++)
        {
            cout<<matris[i][j] <<" ";
        }
        cout<<endl;
    }
}
template <class T>
void Matrix <T>::createMatrix(T r,T c, T v)
{
    int i,j;
    T matris[r][c];
    for(i=0; i<r; i++)
    {
        for(j=0; j < c; j++)
        {
            matris[i][j] = v;
        }
    }


    for(i=0; i<r; i++)
    {
        for(j=0; j < c; j++)
        {
            cout<<matris[i][j] <<" ";
        }
        cout<<endl;
    }
}
template <class T>
void Matrix <T>::randomMatrix(T r,T c)
{
    T matris[r][c];
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            matris[i][j]=rand() %255;
            cout<< matris[i][j]<<"\t";
        }
        cout<<endl;
    }
}
template <class T>
Matrix <T>::~Matrix()
{
    //dtor
}


int main()
{

    cout<<"1:Matrisleri goruntule"<<endl;
    cout<<"2:Toplama islemi"<<endl;
    int secenek;
    cin>>secenek;
    switch(secenek){
        case 1:Matrix<int> *m1 = new Matrix<int>();
               cout << endl;
               cout << endl;
               Matrix<int> *m2 = new Matrix<int>(3,2,1);
               cout << endl;
               cout << endl;
               Matrix<int> *m3 = new Matrix<int>(3,4,9);
               cout << endl;
               cout << endl;
               Matrix<int> *m4 = new Matrix<int>(5,5,'e');
               cout << endl;
               cout << endl;
               Matrix<int> *m5 = new Matrix<int>(15,15,'r');

    }

    return 0;
}
