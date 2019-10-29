#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    // Matrix<int> *m1 = new Matrix<int>();
   // Matrix<int> *m1 = new Matrix<int>(3,3,7);
    Matrix<int> *m2 = new Matrix<int>(3,3,7);
   // Matrix<int> *m3 = new Matrix<int>(3,3,'r');
   //m1->printMatrix();
    //m3->printMatrix();


   // m1->printMatrix();
    //  m1->printMatrix("deneme.txt");
   // m2->printMatrix();
   // m3->printMatrix();
   // Matrix<int> *m2 = new Matrix<int>(3,3,'r'); m2->printMatrix();
    // m2->transpose().printMatrix();
     // m3->det();
    //(*m2) = (*m2)+(*m1);
   // (*m3) = (*m3) * (*m1);
    (*m2) = (*m2)^2;
    m2->printMatrix();


  //  m1->printMatrix();

    return 0;
}
