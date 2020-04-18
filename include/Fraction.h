#pragma once
/*
 * fraction_16law13.h
 *
 *  Created on: Oct. 15, 2019
 *      Author: liama
 */
#include <iostream>

using namespace std;

class Fraction {
public:
	/*
	2 input constructor makes a/b, 1 input makes a/1 0 input makes 0/1

	*/
	Fraction(int a, int b);
	Fraction(int a);
	Fraction();
	//accessors
	int numerator() const;
	int denominator() const;

private:
	// reducing function
	int GCD(int num, int dem);
	//numerator and denominator attributes
	int num;
	int den;


};
// illegal fraction exceptions 
class FractionException {
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};


// operator non member overloading
// plus sign for all three cases(frac + frac, int + frac, frac + int)
Fraction operator+(const Fraction& fracOne, const Fraction& fracTwo);// done
Fraction operator+(const Fraction& fracOne, const int aNum);
Fraction operator+(const int aNum, const Fraction& fracOne);
// minus for the same three cases
Fraction operator-(const Fraction& fracOne, const Fraction& fracTwo);// done
Fraction operator-(const Fraction& fracOne, const int aNum);
Fraction operator-(const int aNum, const Fraction& fracOne);
//multiplication
Fraction operator*(const Fraction& fracOne, const Fraction& fracTwo);// done
Fraction operator*(const Fraction& fracOne, const int aNum);
Fraction operator*(const int aNum, const Fraction& fracOne);
//division
Fraction operator/(const Fraction& fracOne, const Fraction& frac);
Fraction operator/(const Fraction& fracOne, int aNum);
Fraction operator/(int aNum, const Fraction& frac);
// incrementation
Fraction operator++(Fraction& frac);
Fraction operator++(Fraction& frac, int aNum);
//negation
Fraction operator-(const Fraction& frac);
// add and assign to
Fraction operator+=(Fraction& fracOne, const Fraction& fracTwo);
Fraction operator+=(Fraction& frac, const int aNum);
Fraction operator+=(int aNum, const Fraction& frac);// done
//boolean/comparison operators
// less than
bool operator<(const Fraction& fracOne, const Fraction& fracTwo);
bool operator<(const int aNum, const Fraction& frac);
bool operator<(const Fraction& frac, const int aNum);
// greater than
bool operator>(const Fraction& fracOne, const Fraction& fracTwo); // done
bool operator>(const Fraction& frac, const int aNum);
bool operator>(const int aNum, const Fraction& frac);
//less than or equals to
bool operator<=(const Fraction& fracOne, const Fraction& fracTwo);
bool operator<=(const Fraction& frac, const int aNum);
bool operator<=(const int aNum, const Fraction& frac);
// equals
bool operator==(const Fraction& fracOne, const Fraction& fracTwo);
bool operator==(const Fraction& frac, const int aNum);
bool operator==(const int aNum, const Fraction& frac);
//greater than or equals to
bool operator>=(const Fraction& fracOne, const Fraction& fracTwo);
bool operator>=(const Fraction& frac, const int aNum);
bool operator>=(const int aNum, const Fraction& frac); // done
// not equals
bool operator!=(const Fraction& fracOne, const Fraction& fracTwo);
bool operator!=(const Fraction& frac, const int aNum);
bool operator!=(const int aNum, const Fraction& frac);// done
// outputting
ostream& operator<<(ostream& out, const Fraction& value);
// inputting -> this one doesn't really work
istream& operator>>(istream& in, Fraction& myF);