#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <Fraction.h>
#include <Equation.h>
#include <Polynomial.h>

using namespace std;
// up to date

class Equation {
public:
	Equation(string eqn, string type);
	Equation(string eqn, Fraction soln);
	Equation(string eqn);
	string getRHS() { return rhs; }
	string getLHS() { return lhs; }
	vector<Polynomial> getTermsLHS() { return termsLHS; }
	vector<Polynomial> getTermsRHS() { return termsRHS; }
	void printTermsLHS();
	void printTermsRHS();
	void printSimpLHS();
	void printSimpRHS();
	void solve();
private:
	void partition(string eqn);
	string eqnTxt;
	vector<char> numsEqn;
	vector<char> varsEqn;
	string lhs, rhs;
	vector<Polynomial> identifyTerms(string eqn);
	vector<Polynomial> simplify(vector<Polynomial> terms);
	vector<Polynomial> termsLHS, termsRHS, termsLSimp, termsRSimp;
	Fraction solution;
	int nthOrder;
	

};

class BadEquationException {

};

ostream& operator<<(ostream& out, const Equation& value);
