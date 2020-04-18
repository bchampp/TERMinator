#include <Equation.h>
// up to date
// changed
using namespace std;

Equation::Equation(string eqn) {
	eqnTxt = eqn;
	partition(eqn);
	termsLHS = identifyTerms(lhs);
	termsRHS = identifyTerms(rhs);
	printTermsLHS();
	printTermsRHS();
	termsLSimp = simplify(termsLHS);
	termsRSimp = simplify(termsRHS);
	printSimpLHS();
	printSimpRHS();
}

Equation::Equation(string eqn, string type) {
	eqnTxt = eqn;
	partition(eqn);

}

Equation::Equation(string eqn, Fraction soln) {
	eqnTxt = eqn;
	partition(eqn);
	termsLHS = identifyTerms(lhs);
	termsRHS = identifyTerms(rhs);
}

void Equation::solve() {
	// linear
	if (nthOrder == 1) {
		// move all of the variables to left hand side
		Fraction XCoeff = termsLSimp[1].getCoefficient() - termsRSimp[1].getCoefficient();
		Fraction constants = termsRSimp[0].getCoefficient() - termsLSimp[0].getCoefficient();
		Fraction solution = constants / XCoeff;
		cout << "X = " << solution << endl;
// move all constants to the right hand side
	}
	//nonlinear 
	//else
		// list of x values -5,-4.99,-4.98...5
		// Fvals = sum(coeff*xVals^order)
		// iterate through a list of xValues, set a threshold for root (ie 0.001)
		// if it satisfies this
		// 
		

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

vector<Polynomial> Equation::identifyTerms(string side) {
	// cases: it finds an x -> makes a variable with that
	//        it finds a lone number (ie; and x is not the next term
	// move through entire string
	vector<Polynomial> terms;
	int i = 0;
	const int j = side.length()- 1;
	int termsAdded = 0;
	for (std::string::iterator it = side.begin(); it != side.end(); ++it) {
		char c = *it;
		int asc = (int)c;

		if (*it == 'x') {
			// if we're not at the first or last position
			int coef =0, ord=0;
			if (i > 0 && i < j) {
				// if there's a number coefficient
				if ((((int) * (it - 1)) > 47) && (((int) * (it - 1)) < 58))
					coef = (int) * (it - 1) - 48;
				else coef = 1;
				// if there's a number exponent
				if ((((int) * (it + 1)) > 47) && (((int) * (it + 1)) < 58))
					ord = (int) * (it + 1) - 48;
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
			termsAdded++;
			
		}
		// if theres a constant in the middle 
		 if ((i != j) && (i != 0)) {
			if ((c > 47 && c < 58) && (*(it + 1) != 'x') && (*(it - 1) != 'x')) {
				int coeff = (int)c - 48;
				Fraction newFrac(coeff);
				int order = 0;
				Polynomial cnst(coeff, order);
				terms.push_back(cnst);
				termsAdded++;

			}

		}
		// if there are constants at beginning or end
		 if (i == 0) {
			if ((c > 47 && c < 58) && (*(it + 1) != 'x')) {
				int coeff = c -48;
				Fraction newFrac(coeff);
				int order = 0;
				Polynomial cnst(coeff, order);
				terms.push_back(cnst);
				termsAdded++;

			}
		}

		 if (i == j) {
			if ((c > 47 && c < 58) && (*(it - 1) != 'x')) {
				int coeff = (int)c - 48;
				Fraction newFrac(coeff);
				Polynomial cnst(coeff);
				terms.push_back(cnst);
				termsAdded++;

			}
		}


		i++;
	}
	return terms;

}

vector<Polynomial> Equation::simplify(vector<Polynomial> terms) {
	// iterate through the terms, find which ones have the same exponent and add coefficients

	// find highest coefficient
	vector<Polynomial> ret;
	int highestExp = 0;
	for (int i = 0; i < terms.size();i++) {
		int exp = terms[i].getOrder();
		if (exp > highestExp)
			highestExp = exp;
	}
	nthOrder = highestExp;

	for (int i = 0; i <= highestExp;i++) {
		Fraction newCoeff(0);
		for (int j = 0; j < terms.size();j++) {
			if (terms[j].getOrder() == i) {
				newCoeff = newCoeff + terms[j].getCoefficient();
			}

		}
		Polynomial pl(newCoeff, i);
		ret.push_back(pl);
	}
	return ret;
}


void Equation::printTermsLHS() {
	vector<Polynomial> plVec = termsLHS;
	cout<<"Number of terms on the left hand side:" << termsLHS.size() << endl;
	for (int i = 0; i < plVec.size();i++) {
		cout << plVec[i] << endl;
	}
}

void Equation::printTermsRHS() {
	vector<Polynomial> plVec = termsRHS;
	cout << "Number of terms on the right hand side:" << termsRHS.size() << endl;
	for (int i = 0; i < plVec.size();i++) {
		cout << plVec[i] << endl;
	}
}

void Equation::printSimpLHS() {
	vector<Polynomial> plVec = termsLSimp;
	cout << "number of simplified terms on the left: " << plVec.size() << endl;
	for (int i = 0; i < plVec.size();i++) {
		cout << plVec[i] << endl;
	}
}

void Equation::printSimpRHS() {
	vector<Polynomial> plVec = termsRSimp;
	cout << "number of simplified terms on the right: " << plVec.size() << endl;
	for (int i = 0; i < plVec.size();i++) {
		cout << plVec[i] << endl;
	}
}