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
	if (poly.getOrder() == 0)
		out << poly.getCoefficient();
	else 
		out << poly.getCoefficient() << "x^" << poly.getOrder();
	return out;
}

