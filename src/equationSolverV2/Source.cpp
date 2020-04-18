#include <iostream>
#include <math.h>
#include "Equation.h"
using namespace std;
static double function(double x);
static double functionDerivative(double x);
int main() {
	double prevX;
	double x;
	double precision;
	x = 1;
	prevX = x;
	precision = 0.00000001;
	while (abs(function(x)) > precision) {
		x = prevX - (function(prevX) / functionDerivative(prevX));
		prevX = x;
	}
	cout << "X: " << x << endl;
	int a;
	cin >> a; //Wait before exiting
	return 0;
}
static double function(double x)
{
	return x * (x + 2) + 1;
	//x^2 + 2x + 1
	 // return c0 + c1*x + c2*x2

}
static double functionDerivative(double x)
{
	return 2 * x + 2;
}