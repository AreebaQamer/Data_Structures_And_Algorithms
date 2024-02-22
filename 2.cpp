//#include<iostream>
//#include"Polynomial.h"
//using namespace std;
//int main()
//{
//	polynomial p1;
//	p1.addTerm(3, 8);//add term
//	//p1.display();
//	p1.addTerm(-7, 7);
//	p1.addTerm(14, 1);
//	p1.addTerm(19, 3);
//	p1.addTerm(56, 0);
//	p1.display();//display
//	cout << endl;
//	cout << p1.getDegree() << endl;//getdegree()
//	cout << "COEFFICIENTS ARE" << endl;
//	cout << p1.getCoefficient(-2) << endl;//getcoefficient
//	cout << p1.getCoefficient(1) << endl;//getcoefficient
//	cout << "EVALUATION:" << endl;
//	p1.evaluate(2);//evaluate at some x
//	cout << endl;
//	cout << "the coefficients after adding is(14 to 3):" << endl;
//	p1.addToCoefficient(14, 3); //add to coefficient
//	p1.display();
//	cout << endl;
//	cout << "the derivative 1 is:" << endl;
//	p1.Derivative();          //derivative of polynomial
//	cout << endl;
//	polynomial p2;
//	p2.addTerm(4, 2);
//	p2.addTerm(6, 1);
//	p2.display();
//	cout << endl;
//	cout << "the derivative 2 is:" << endl;
//	p2.Derivative();
//	cout << endl;
//	polynomial p5;
//	p5.addTerm(3, 2);
//	p5.addTerm(-2, 1);
//	p5.addTerm(5, 0);
//	p5.display();
//	cout << endl;
//	cout << "the derivative 3 is:" << endl;
//	p5.Derivative();
//	cout << endl;
//	cout << "the addition is:" << endl;
//	polynomial p4 = p2 + p1;
//	p4.display();
//	cout << endl;
//	cout << "the subtraction is:" << endl;
//
//	polynomial p6 = p1 - p2;  //try operator+ or operator
//	p6.display();
//	cout << endl;
//	cout << "clear is:" << endl;
//	p1.clear();
//	p1.display();//clear
//
//}