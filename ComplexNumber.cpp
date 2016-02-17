///////////////////////////////////////////////////////////////////////////////
// File:              ComplexNumber.cpp
// Semester:          CS368 Fall 2015
// Author:            Kartik Ayalasomayajula; ayalasomayaj@wisc.edu
// CS Login:          ayalasomayajula
// Lecturer's Name:   Okan Akalin
////////////////////////////////////////////////////////////////////////////
/**
 * The goal of Class: To provide for framework for the implementation of the functionality
 * for Complex Number computation.
 */

#include <iostream>
#include "ComplexNumber.h"
#include <string>
#include <stdlib.h>

using namespace std;

//Default 0-argument constructor.
ComplexNumber::ComplexNumber(){
	imag = 0.0;
	real = 0.0;
}

//Copy Constructor
ComplexNumber::ComplexNumber(double real_part, double imaginary_part){
	imag = imaginary_part;
	real = real_part;
}


ComplexNumber::ComplexNumber(const ComplexNumber & rhs) {
	real = rhs.real;
	imag = rhs.imag;
}

//Print function.
void ComplexNumber::print(ostream & out) const {
	cout << real;
	if(imag < 0) cout << " - " << imag*(-1) << "i" << endl;
	if(imag >= 0) cout << " + " << imag << "i" << endl;
}

//Checks if entities are equal.
bool ComplexNumber::equals(const ComplexNumber & rhs) const {
	if(imag == rhs.imag && real == rhs.real){
		return true;
	}else{
		return false;
	}
}
//Overloaded******************************************
//Equal Overloaded Function
const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs){
	imag = rhs.imag;
	real = rhs.real;
	return *this;
}

//+= overloaded function
const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs){
	imag += rhs.imag;
	real += rhs.real;
	return *this;
}

//-= overloaded function
const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs){
	imag -= (rhs.imag);
	real -= (rhs.real);
	return *this;
}

//*= overloaded function
const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs){
	double temp = real*rhs.real - imag*rhs.imag;
	imag = real*rhs.imag + imag*rhs.real;
	real = temp;
	return *this;
}
//Overloaded/////////////////////////////////////////////////*^^

//Arithmetic Operators******************************************
//Addition
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber temp(lhs);
	return temp+=rhs;
}
//Subtraction
ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber temp(lhs);
	return temp-=rhs;
}
//Multiplication
ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber temp(lhs);
	return temp*=rhs;
}
//Arithmetic Operations///////////////////////////////////////////*^^

//Relational Operators**********************************************
//Checking if Equal
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
	if(lhs.equals(rhs))return true;
	return false;
}

// Checking if not Equal
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
	if(lhs.equals(rhs)) return false;
	return true;
}
//Relational Operators///////////////////////////////////////////*^^

//I/O Operators*****************************************************
// <<
ostream & operator<<(ostream & out, const ComplexNumber & n){
	n.print(out);
	return out;
}

// >>
istream & operator>>(istream & in, ComplexNumber & n){
	double realNum;double imagNum;char buffer; int sign; string temp;
    //Get rid of pre-existing white-spaces
	in.get(buffer);
	while (buffer == ' ' || buffer == '\n' || buffer== '\t') {
		in.get(buffer);
	}
	in.putback(buffer); // Puts back recently looked-at item

	//Input the realnumbers
	in >> realNum;
//	cout << realNum<<endl;

	//Parse through white-spaces
	in.get(buffer);
	while(buffer == ' ' || buffer == '\n' || buffer == '\t') in.get(buffer);
	//Check for Signs
	if(buffer == '-'){
		sign = -1;
	}else if (buffer == '+'){
		sign = 1;
	}else{
		cout << "Invalid input"<<endl;
		in.setstate(ios::failbit);
		return in;
	}
//	//imagNum*=sign;
	//Take care of white spacing, again.
	in.get(buffer);
	while(buffer == ' ' || buffer == '\n' || buffer == '\t'){
		in.get(buffer);
	}
	in.putback(buffer);

	//TODO: Insert checks for if the user entered i or not.
	//Get the imaginary number portion.
	in >> temp;
	temp = temp.substr(0, temp.size()-1);
	imagNum = atof(temp.c_str());
	imagNum = imagNum * sign;

	n = ComplexNumber(realNum,imagNum);
	return in;

}
//I/O Operators//////////////////////////////////////////////////*^^
