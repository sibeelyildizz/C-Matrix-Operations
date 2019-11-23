#ifndef TABLE_H
#define TABLE_H

#include <Matrix.h>

template <typename T>
class Table : public Matrix<T>
{
    public:
        Table();
        ~Table();
        Table(const Table& other);

    protected:

    private:

};

#endif // TABLE_H
