//
// Created by shayn on 2019-11-22.
//

#ifndef DISPLAYV2_DISPLAY_H
#define DISPLAYV2_DISPLAY_H
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include "../matplotlib-cpp-master/matplotlibcpp.h"


using namespace std;

class display{
//friend class of linearSolve
private:
    string equ;
    string lhs;
    string rhs;
    int add = 0;
    int sub = 0;
    int mult = 0;
    int div = 0;
    int exp = 0;

    vector<string> terms;
    vector<char> order;
    vector <string> steps;
    string updatelhs;
    string updaterhs;
    void exponent(string exp);
    void divide(string express);
    void multiply(string express);
    void addition(string express);
    void subtract(string express);
    void solvePoint(double n);
    void printsteps();
    string statement;
    vector<double> yVal;
    vector<double>xVal;



public:
    display(const string& equ);
    display();
    void split(const string& equ);
    void toAnswer();
    string getEquation();
    string getLeft() const;
    string getRight() const;
    void walkThrough();
    void removeSpaces(char *str);
    void setStatement(string state);
    string getStatement();

    void divideIso(string express);

    void setLeft( string& update);
    void setRight( string& update);
    string getUpdatelhs() const;
    string getUpdaterhs() const;
    void addSlash(string express);
    string removeSlash(string express);
    void subLeft(string express, double n);
    void setXVal(vector<double>& x);
    void setYVal(vector<double>& y);
    vector<double> getXVal();
    vector<double> getYVal();
    void printVector(vector<double> v);
    //void plotAndSave() const;
    void showSteps();
};
#endif //DISPLAYV2_DISPLAY_H
