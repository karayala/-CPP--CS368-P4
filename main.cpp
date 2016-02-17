///////////////////////////////////////////////////////////////////////////////
// File:              main.cpp
// Semester:          CS368 Fall 2015
// Author:            Kartik Ayalasomayajula; ayalasomayaj@wisc.edu
// CS Login:          ayalasomayajula
// Lecturer's Name:   Okan Akalin
////////////////////////////////////////////////////////////////////////////
/**
 * The goal of Class:
 * **(A) To provide a framework to test out the implementation of ComplexNumber.cpp
 * **(B) To include User Interface for users to be able to perform calculations using the implementation of ComplexNumber.cpp
 */

#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main() {
//Initial Declarations
ComplexNumber C1;
ComplexNumber C2;
//Obtaining Input
cout << "Enter a complex number C1: ";
cin >> C1;
cin.clear();
cout << "Enter a complex number C2: ";
cin >> C2;
cin.clear();

//Printing out results
cout <<"For C1 = " << C1<< "And C2 = " << C2<<endl;
cout << "C1 + C2 = " << (C1 + C2);
cout << "C1 - C2 = " << (C1 - C2);
cout << "C1 * C2 = " << (C1 * C2);
if((C1==C2) == 0){
	cout << "C1 == C2 is False"<< endl;
}else{
	cout << "C1 == C2 is True"<< endl;
}

if((C1!=C2) == 0){
	cout << "C1 != C2 is False" << endl;
}else{
	cout << "C1 != C2 is True" << endl;
}
cout << "After C1 += C2, C1 = " << (C1 += C2);
cout << "After C1 -= C2, C1 = " << (C1 -= C2);
cout << "After C1 *= C2, C1 = " << (C1 *= C2);

return 0;
}

