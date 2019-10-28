#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    // Matrix<int> *m1 = new Matrix<int>();
    Matrix<int> *m1 = new Matrix<int>(3,3,5);
    Matrix<int> *m2 = new Matrix<int>(3,3,9);
    Matrix<int> *m3 = new Matrix<int>(2,2,'e');

    m1->printMatrix();
    //  m1->printMatrix("deneme.txt");
    m2->printMatrix();
    m3->printMatrix();
    //Matrix<int> *m2 = new Matrix<int>(2,2,'r'); m2->printMatrix();
//    m3->det();
    (*m2) = (*m2)+(*m1);
    m2->printMatrix();

    return 0;
}
