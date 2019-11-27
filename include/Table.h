#ifndef TABLE_H
#define TABLE_H

#include <Matrix.h>

template <typename T>
class Table : public Matrix<T>
{
public:
   Table() :Matrix<T>::Matrix(){deneme1(10);}     //inheritance constructor
    Table(T _row,T _column,T _value):Matrix<T>::Matrix(_row,_column,_value) {} //inheritance constructor
    Table(T _row,T _column,char ch):Matrix<T>::Matrix(_row,_column,ch) {}  //inheritance constructor
    T itemAt(int r,int c);
    T deneme1(int c);
    T deneme2(int r);


    ~Table();


    Table(const Table& other);

protected:

private:
    string *colName;
    string *RowName;


};
template <typename T>
T Table<T>::deneme1(int c ){
//colName=new string[this->column,];
 string stringarray[18]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","R","S"};

           for(int i = 0; i <10 ; i++)
        {

            cout<<stringarray[i]<<"\t";

        }
        cout<<endl;
}
template <typename T>
T Table<T>::deneme2(int r ){
//colName=new string[this->column];
int stringarray[r];
           for(int i = 0; i <10 ; i++)
        {

            stringarray[i]=i;
            cout<<stringarray[i]<<endl;

        }
}
template <typename T>
 T Table<T>::itemAt(int r, int c) {

	return this->array[r-1][c-1];
}

#endif // TABLE_H
