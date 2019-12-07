#include <iostream>
#include "Matrix.h"
#include "Table.h"
using namespace std;

int main()
{
    //Matrix<int> *m1 = new Matrix<int>();  m1->printMatrix(); //pointer olarak tanimlam Matrix<int> m1(4,4,'r'); //nesne olarak tanimlama
    //Matrix<int> *m2 = new Matrix<int>(3,2,1);  m2->printMatrix();
    //Matrix<int> *m2 = new Matrix<int>(3,4,9);  m2->printMatrix();
    //Matrix<int> *m3 = new Matrix<int>(5,5,'e'); m3->printMatrix();
    //Matrix<int> *m4 = new Matrix<int>(5,5,'r'); m4->printMatrix();*m4 = *m4 + 3.0; m4->printMatrix();
    //Matrix<int> *m5 = new Matrix<int>(4,4,8);  m5->printMatrix(); //pointer olarak tanimlam Matrix<int> m1(4,4,'r'); //nesne olarak tanimlama
    //Matrix<int> *m6 = new Matrix<int>(4,4,'r'); m6->printMatrix();
    //Matrix<int> *m7 = new Matrix<int>(3,3,'r'); m7->printMatrix();
    //*m2 = (m2)->resizeMatrix(1,6);   m2->printMatrix();




    //(*m5)=(*m5)+(*m6);m5->printMatrix();
    //(*m5)=(*m5)-(*m6);m5->printMatrix();
    //(*m5)=(*m5)*(*m6);m5->printMatrix();
    //(*m5) = (*m5)+2; m5->printMatrix();
    //(*m5) = (*m5)-20; m5->printMatrix();
    //(*m5) = (*m5)*10; m5->printMatrix();
    //(*m5) = (*m5)/4; m5->printMatrix();
    //(*m5) = (*m5)%5; m5->printMatrix();
    //(*m5) = (*m5)^2; m5->printMatrix();

    //m2->printMatrix("deneme.txt");
    //*m6=m6->transpose(); m6->printMatrix();
    //(*m5)=m5->emul(*m6);   m5->printMatrix();
    //cout<<m7->det();





    //Table<int> *m8 = new Table<int>(); m8->printMatrix();
    //Table<int> *m9 = new Table<int>(3,4,5); m9->printMatrix();
    // Table<int> *m10 = new Table<int>(3,4,'r'); m10->printMatrix();


    //cout << m10->itemAt(2,2)<<endl;  // derived clas

    //cout<< m10->itemAt("2","B")<<endl;

    //cout<< m10->itemAt("B2");




    return 0;
}
