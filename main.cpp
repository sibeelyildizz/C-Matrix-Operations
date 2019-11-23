#include <iostream>
#include "Matrix.h"
#include "Table.h"
using namespace std;

int main()
{
    Matrix<int> *m4 = new Matrix<int>();
    Matrix<int> *m1 = new Matrix<int>(3,3,2);
    Matrix<int> *m2 = new Matrix<int>(3,3,3);
    Matrix<int> *m5 = new Matrix<int>(2,2,'r');





     m5->printMatrix();
     (*m5).det();


    //  m1->printMatrix("deneme.txt");
   // m2->printMatrix();
 //  m3->printMatrix();

   // Matrix<int> *m2 = new Matrix<int>(3,3,'r'); m2->printMatrix();
    // m2->transpose().printMatrix();
     //

    //(*m2) = (*m2)+(*m1);
   // (*m3) = (*m3) * (*m1);
   // (*m2) = (*m2)^2;
 //    (*m3).det();
  // (*m3).inv();

   //(*m1)=m1->emul(*m2);

    //m1->printMatrix();

    //m1->printMatrix();

    return 0;
}
