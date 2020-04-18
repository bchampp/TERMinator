#include <iostream>
#include <vector>
#include<fstream>
#include "fraction_16law13.h"

/*
Current Status:
- identifies numbers/operators
- stores numbers/operators in vectors
Next to do:
- implement simplify function that can be recursively called to simplify expressions (meh/10) (done without variables)
- need to modify functions to consider numbers and operators separately
- add in variables
- move across equals sign
- solve for x
in identify numbers, maybe it needs to look for multiplication and divison terms first before
it tries to simplify them
-function simplfify brackets that picks out brackets and identifies terms inside them using other simplify
- function simplify multiplication that does multiplication simplification
-function simplify addition subtraction already exists sort of
- finds brackets, calls all other simplify functions inside them

*/
using namespace std;

class linearEquation{
public:
linearEquation(string filename);


Fraction operate(char opr,Fraction fracA,Fraction fracB); // figures carries out add sub mult div based on the operator 
Fraction simplify(vector<Fraction> terms,vector<char> ops); // simplififes numbers down to basic form 
void identifyTerms(vector<char> terms,vector<char> opsOut,vector<Fraction> numsOut); // splits the equation into operators and numbers
void splitEquation(vector<char> eq);
void simplifyBrackets(vector<char> eqn);
void simplifyMultiplication();
void printEquation(); 

void setLHS(vector<char> terms);
void setRHS(vector<char> terms);

vector<char> eqn; // original character equation

vector<Fraction> rhsNums;
vector<Fraction> rhsVars;
vector<char> rhsOps;

vector<Fraction> lhsNums;
vector<Fraction> lhsVars;
vector<char> lhsOps;
};