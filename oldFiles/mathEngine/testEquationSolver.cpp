#include "Equation.h"
#include "Polynomial.h"
#include<vector>

using namespace std;

int main() {
	// doesn't recognize the term at the end, is having difficulty with this but isnt crashing ! YEAhhhH
	Equation eq("2x+3x+4x=3x+4x+5x");
	eq.solve();
	eq.printPoly(eq.termsLHS);



}