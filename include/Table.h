#ifndef TABLE_H
#define TABLE_H

#include <Matrix.h>
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

        //cout<<colName[i]<<" \t";
        cout<<cName++<<" \t";
    // cout<<endl;
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
T Table<T>::itemAt(string s)
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

    index2 = s[1]-'0';  //s dizisinin 1. indisindeki elemaný integer'a cevirme
    if(index1<=this->column+1 && index2<=this->row+1)
        return this->array[index1][index2-1];
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
    index1 = rs[0]-'0';  //s dizisinin 1. indisindeki elemaný integer'a cevirme
    for(int i=0; i<rowName.size(); i++) //sutunu alfabede bulma
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
