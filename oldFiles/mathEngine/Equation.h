#pragma once
#include <iostream>
#include <vector>
#include<fstream>
#include "Fraction.h"
#include "Polynomial.h"
using namespace std;
// up to date

class Equation {
public:
	Equation(string eqn, string type);
	Equation(string eqn, Fraction soln);
	Equation(string eqn);
	void partition(string eqn);
	string eqnTxt;
	vector<char> numsEqn;
	vector<char> varsEqn;
	string lhs, rhs;
	void initialSimplify(string eqn, vector<Polynomial> terms);
	void solve();
	vector<Polynomial> termsLHS, termsRHS;
	void printPoly(vector<Polynomial> vec);
	Fraction solution;
	string getRHS() { return rhs; }
	string getLHS() { return lhs; }

};

class BadEquationException {

};

ostream& operator<<(ostream& out, const Equation& value);
