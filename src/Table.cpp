#include "Table.h"

template<typename T>Table<T>::Table()
{
    Matrix<T>::Matrix();
}
template<typename T>Table<T>::~Table()
{
    //dtor
}

template<typename T>Table<T>::Table(const Table& other)
{
    //copy ctor
}
