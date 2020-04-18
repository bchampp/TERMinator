#pragma once
#include <string>
#include<iostream>
#include <vector>
#include "Fraction.h"
using namespace std;

using namespace std;

class Polynomial {
public:
	Polynomial(Fraction coeff, int ord);
	Polynomial(Fraction coeff);
	int getOrder();
	Fraction getCoefficient();
private:
	Fraction coefficient;
	int order;

};

ostream& operator<<(ostream& out, const Polynomial poly);