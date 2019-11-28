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
    T itemAt(int r,int c);
    T itemAt(string s);
    T itemAt(string rs,string cs);

    ~Table();


    Table(const Table& other);

protected:

private:
    string *colName;
    string *RowName;
    string alphabet = {"ABCDEFGHIJKLMNOPQRSTUVYXWZ"};
};

template <typename T>
T Table<T>::itemAt(int r, int c)
{

    return this->array[r-1][c-1];
}
template <typename T>
T Table<T>::itemAt(string s)
{
    int index1=0,index2=0;
    for(int i=0; i<alphabet.size(); i++)
    {
        if (s[0]==alphabet[i])
        {
            index1 = i;
            break;
        }
    }

    index2 = s[1]-'0';  //s dizisinin 1. indisindeki elemaný integer'a cevirme
    if(index1<=this->column && index2<=this->row)
        return this->array[index2][index1];
    else
    {
        cout<<endl;
        cout<<"Dizi sinirlari asildi"<<endl;
        return 0;
    }
}
template <typename T>
T Table<T>::itemAt(string rs,string cs){
    int index1=0,index2=0;
    index1 = rs[0]-'0';  //s dizisinin 1. indisindeki elemaný integer'a cevirme
    for(int i=0; i<alphabet.size(); i++) //sutunu alfabede bulma
    {
        if (cs[0]==alphabet[i])
        {
            index2 = i;
            break;
        }
    }
     if(index1<=this->column && index2<=this->row)
     {cout<<index1<<"-"<<index2<<endl;
        return this->array[index1][index2];}
    else
    {
        cout<<endl;
        cout<<"Dizi sinirlari asildi"<<endl;
        return 0;
    }

}
#endif // TABLE_H
