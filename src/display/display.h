#pragma once

#include <iostream>
#include <string>
#include <matlpotlib-cpp.h>
//#include <EquationSolverV2.h>
#include <vector>

using namespace std;

class display{
//friend class of linearSolve
private:
	string equation;
	string lhs;
	string rhs;
    int add = 0;
    int sub = 0;
    int mult = 0;
    int div = 0;
    int exp = 0;

public:
    display();
    display split(const string& equ);
	string toAnswer() const;
	//void plotAndSave() const;
	//string showSteps();
}