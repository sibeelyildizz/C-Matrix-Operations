#include <iostream>
#include "Matrix.h"
#include "Table.h"
using namespace std;

int main()
{
     Matrix<int> *m4 = new Matrix<int>();
    //Matrix<int> *m1 = new Matrix<int>(3,3,2);
    //Matrix<int> *m2 = new Matrix<int>(3,3,'r');
    // Matrix<int> *m5 = new Matrix<int>(3,3,'r');
   //Table<int> *m4 = new Table<int>();

    Table<int>* m1 = new Table<int>();

	(*m1).printMatrix(); // base class
	cout << m1->itemAt(1,1);  // derived class
    //m5->printMatrix();


    //  m1->printMatrix("deneme.txt");
  //  m2->printMatrix();
//  m3->printMatrix();

    // Matrix<int> *m2 = new Matrix<int>(3,3,'r'); m2->printMatrix();
   // m2->transpose();
    //m2->printMatrix();
    //

    //(*m2) = (*m2)+(*m1);
    // (*m3) = (*m3) * (*m1);
    // (*m2) = (*m2)*2;
//    (*m3).det();
    // (*m3).inv();

    //(*m1)=m1->emul(*m2);

    // m2->printMatrix();

    //m1->printMatrix();

    return 0;
}
