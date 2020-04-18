#pragma once 
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(Fraction coeff, int ord) {
	coefficient = coeff;
	order = ord;
}

Polynomial::Polynomial(Fraction coeff) {
	coefficient = coeff;
	order = 0;
}

Fraction Polynomial::getCoefficient() {
	return coefficient;
}

int Polynomial::getOrder() {
	return order;
}

ostream& operator<<(ostream& out, Polynomial poly) {
		out << poly.getCoefficient() << "x^" << poly.getOrder();
	return out;
}
