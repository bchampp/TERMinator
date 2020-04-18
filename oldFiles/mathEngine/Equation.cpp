#include "Equation.h"
// up to date
using namespace std;

Equation::Equation(string eqn) {
	eqnTxt = eqn;
	partition(eqn);

}

Equation::Equation(string eqn, string type) {
	eqnTxt = eqn;
	partition(eqn);
	initialSimplify(rhs, termsRHS);

}

Equation::Equation(string eqn, Fraction soln) {
	eqnTxt = eqn;
	partition(eqn);
	solution = soln;
}

void Equation::solve() {
	initialSimplify(lhs, termsLHS);
	initialSimplify(rhs, termsRHS);
}

//WORKS! -> need to add exception class to thing though
void Equation::partition(string eqn) {
	string delimiter = "=";
	size_t pos = 0;
	string token;
	if (eqn.find(delimiter) != string::npos) {
		pos = eqn.find(delimiter);
		lhs = eqn.substr(0, pos);
		eqn.erase(0, pos + delimiter.length());
		rhs = eqn;
	}
	// else , throw exception
}
// for now, assume brackets arent a thing, we can add these in later
// also assumes minus signs arent a thing
// also assumes none of the numbers are larger than single digit 

void Equation::initialSimplify(string lhs, vector<Polynomial> terms) {
	// cases: it finds an x -> makes a variable with that
	//        it finds a lone number (ie; and x is not the next term
	// move through entire string
	int i = 0;
	const int j = lhs.length() - 1;
	for (std::string::iterator it = lhs.begin(); it != lhs.end(); ++it) {
		char c = *it;

		if (*it == 'x') {
			// if we're not at the first or last position
			int coef = 0, ord = 0;
			if (i > 0 && i < j) {
				// if there's a number coefficient
				if ((((int) * (it - 1)) > 47) && (((int) * (it - 1)) < 58))
					coef = (int) * (it - 1) - 48;
				else coef = 1;
				// if there's a number exponent
				if ((((int) * (it + 1)) > 47) && (((int) * (it + 1)) < 58))
					ord = (int) * (it + 1);
				else ord = 1;


			}
			// if we're at the last position
			else if (i == j) {
				// check for number exponent
				if ((((int) * (it - 1)) > 47) && (((int) * (it - 1)) < 58))
					coef = (int) * (it - 1) - 48;
				ord = 1;
			}
			// if we're at the starting position
			else {
				// if there's a number exponent
				if ((((int) * (it + 1)) > 47) && (((int) * (it + 1)) < 58))
					ord = (int) * (it + 1);
				coef = 1;
			}

			Fraction frac(coef);
			Polynomial pl(coef, ord);
			cout << pl << endl;
			terms.push_back(pl);

		}



		i++;
	}

}

ostream& operator<<(ostream& out, const Equation& eq) {
	vector<Polynomial> tLHS = eq.termsLHS;
	vector<Polynomial> tRHS = eq.termsRHS;
	for (int i = 0; i < tLHS.size();i++) {
		out << tLHS[i];
	}
	out << "=";
	for (int i = 0; i < tRHS.size();i++) {
		out << tLHS[i];
	}
	return out;
}

void Equation::printPoly(vector<Polynomial> vec) {
	int N = vec.size();
	for (int i = 0; i < N; i++) {
		cout << vec[i] << endl;
	}
}

