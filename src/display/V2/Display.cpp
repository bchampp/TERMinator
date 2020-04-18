//
// Created by shayn on 2019-11-22.
//

#include "Display.h"
#include <cmath>
//namespace plt = matplotlibcpp;
//
//GOAL:
//2 + 3x = y
//x^2 + 1 = 5
//1 * 7 + 2^3 = x
display::display() {
    equ;
    size_t pos = 0;
    lhs;
    rhs;
    yVal;
    xVal;
    statement = "";
    updatelhs = lhs;
    updaterhs = rhs;
    vector<string> terms;
    vector<char> order;
    yVal;
    xVal;
    int add = 0;
    int sub = 0;
    int mult = 0;
    int div = 0;
    int exp = 0;
}

display::display(const string& equation) {
    equ = equation;
    statement = "";
    int add = 0;
    int sub = 0;
    int mult = 0;
    int div = 0;
    int exp = 0;
    vector<string> terms;
    vector<char> order;
    vector<string> steps;
    //unordered_multimap<char, string> terms;
    cout<<"we here"<<endl;
    int pos = 0;
    string delimiter = "=";
    pos = equ.find(delimiter);
    lhs = equ.substr(0, pos);
    rhs = equ;
    rhs.erase(0, pos + delimiter.length());
    cout<<lhs<< ", "<< rhs<< endl;
    updatelhs = lhs;
    updaterhs = rhs;
}

string display::getEquation(){
    return equ;
}
//split left and right side
string display::getLeft() const{
    return lhs;
}

string display::getRight() const{
    return rhs;
}
string display::getUpdatelhs() const{
    return updatelhs;
}


string display::getUpdaterhs() const{
    return updaterhs;
}
void display::setLeft( string& update){
    updatelhs = update;
}

void display::setXVal(vector<double>& x){
    xVal = x;
}
vector<double> display::getXVal(){
    return xVal;
}
void display::setYVal(vector<double>& y){
    yVal = y;
}
vector<double> display::getYVal(){
    return yVal;
}
void display::setRight(string& update){
    updaterhs = update;
}
void display::setStatement(string state){
    statement = state;
}
string display::getStatement() {
    return statement;
}

void display::printVector(vector<double> v){
    for (std::vector<double>::const_iterator i = v.begin(); i != v.end(); ++i)
        std::cout << *i <<endl;
}
void display::toAnswer(){
    cout<<this->getStatement()<<endl;
}

void display::split(const string& equ) {
    int pos = 0;

    string term;
    while (pos != equ.length()) {
        if (equ[pos] == '+') {
            if (!term.empty()) {
                //evaluate?
                terms.push_back(term);
                term.clear();
                order.push_back('t');
                //check type of term and push to queue
            }
            //order.push_back('a');
            terms.push_back("a");
            add++;
        } else if (equ[pos] == '-') {
            if (!term.empty()) {
                terms.push_back(term);
                term.clear();
                order.push_back('t');
            }
            //order.push_back('s');
            terms.push_back("s");
            sub++;
        } else if (equ[pos] == '*') {
            if (!term.empty()) {
                terms.push_back(term);
                term.clear();
                order.push_back('t');
            }
            //order.push_back('m');
            terms.push_back("a");
            mult++;
        } else if (equ[pos] == '/') {
            if (!term.empty()) {
                terms.push_back(term);
                term.clear();
                order.push_back('t');
            }
            //order.push_back('d');
            terms.push_back("d");
            div++;
        } else if (equ[pos] == '^') {
            if (!term.empty()) {
                terms.push_back(term);
                term.clear();
                order.push_back('t');
            }
            //order.push_back('e');
            terms.push_back("e");
            exp++;
        }
        else {
            term += (equ[pos]);
            cout<< term << endl;
        }
        pos++;
    }
    terms.push_back(term);
    for (std::vector<char>::const_iterator i = order.begin(); i != order.end(); ++i)
        std::cout << *i << ' ';
    cout<<endl;
    for (std::vector<string>::const_iterator j = terms.begin(); j != terms.end(); ++j)
        std::cout << *j << ' ';
}

void display::showSteps(){
    int leftVar = 0;
    int rightVar = 0;
    vector<double> x;
    vector<double> y;


    for(int i = 0; i < this->getLeft().length(); i ++) {
        if (isalpha(this->getLeft()[i])) {
            leftVar++;
            break;
            //not an expression
        }
    }
    for(int i = 0; i < this->getRight().length(); i ++){
        if(isalpha(this->getRight()[i])) {
            rightVar++;
            break;
            //could be an expression an expression
        }
        //could count number of operations as well if wanted
    }
    if(rightVar > 0 && leftVar > 0){
        cout<<"pair of points"<<endl;
        cout<<"Possible Solutions for y(x) = "<<this->getLeft()<<": "<<endl;

        for (int i = 1; i<=5;i++){
            this->solvePoint(i);
            if(i == 1){
                this->setStatement("One Possible Solution for "+this->getEquation() + " is if x = 1: \n"
                        +"y = " + this->getUpdatelhs());
            }
            cout<<"y("<<i<<") = "<<this->getUpdatelhs()<<endl;
        }
        for(int i = 0; i<100; i++){
           //cout<<"im in"<<endl;
            double ind = i*10;
            double val;
            x.push_back(ind);
            this->solvePoint(ind);
            stringstream str(this->getUpdatelhs());
            str>> val;
            y.push_back(val);
        }
        this->setXVal(x);
        this->setYVal(y);

        //two var expression
        //sub 1 for left side and solve for right
        //give pair as one solution
        //generate set of plot
    }
    else if(rightVar > 0){
        cout<<"To solve: "<<this->getEquation()<<endl;
        //follow simple bedmas
        exponent(this->getUpdatelhs());

        divide(this->getUpdatelhs());

        multiply(this->getUpdatelhs());
        addition(this->getUpdatelhs());
        subtract(this->getUpdatelhs());
        this->printsteps();
        this->setStatement("The answer to "+this->getEquation() + " is:\n"
                           + this->getRight() + " = " + this->getUpdatelhs());

    }
    else{
        cout<<"isolate the variable"<<endl;

        /*if(leftVar>1){
            //combine the variable coefficients
            //will try to integrate with liams code when finished
        }*/


        //solve for var on left
        //should insert brackets
    }
}

            /*else if(equ.at(pos) == "("){
                start = pos;
                while(equ.at(pos) != ")"){
                    pos++;
                }
                term = equ.substr(start, pos);
                start = equ.find("/");
                num = equ.substr(0, start);
                denom = term;
                term.erase(0, start + 1);
                Fracation frac = Fraction(num, denom);
                queF.push(frac);
                break;
        }

        term = equ.substr(prev, pos);
        if (term.find("x") || term.find("y")){
            int poly;//create a polynomial term
            queP.push(poly);

        }
        else

    }
}*/
/*
void display::walkThrough() {
    while (!terms.empty()){
        if()
    }
}
*/
void display::addSlash(string express) {
    string exp = express;
    size_t found = exp.find("+");
    while(1){
        if(found != string::npos){
            exp.replace(found - 1, 3, "|+|");
            found = exp.find("+");
        }
        else{
            break;
        }
    }
    this->updatelhs = exp;

}
string display::removeSlash(string express){
    cout<<"remove"<<endl;
    string exp = express;
    for (int i = 0; i<exp.length() -1; i++){
        if (exp[i] == '\\'){
            exp.replace(i, 1, " ");
        }
    }
    //this->setLeft(exp);
    return exp;
    //cout<<exp<<endl;
}
void display::exponent(string express){
    string exp = express;
    double ans ;
    int i = 0;
    int range1 =0;
    int range2 =0;
    double term1;
    double term2;
    int end;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("^");
    while(1) {
        out.str(string());
        streamStr.str("");
        roundAns.clear();
        if (found != string::npos) {

            i = found + 1;
            while(i <= exp.length()){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i++;
                    break;
                }
                else{
                    end = i;
                    i++;
                }
            }
            range2 = end - found +1;
            string term = exp.substr(found+1, range2);
            //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2>> term2;
            i = found-1;
            while(i >= 0){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i--;
                    break;
                }
                else{
                    end = i;
                    i--;
                }
            }
            range1 = found-end;
            term = exp.substr(end, range1);
            stringstream streamDou1(term);
            streamDou1>> term1;

            ans = pow(term1,term2);
            streamStr <<ans;
            roundAns = streamStr.str();
            exp.replace(end, range1+range2, roundAns);
            found = exp.find("^");
            step = "Reduce Exponents: " + exp + " = " + this->getRight();
            steps.push_back(step);
            //cout << step << endl;
        }
        else {
            break;
        }
        this->setLeft(exp);
    }

}


void display::divide(string express){
    string exp = express;
    double ans ;
    int i = 0;
    int range1 =0;
    int range2 =0;
    double term1;
    double term2;
    int end;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("/");
    while(1) {
        out.str(string());
        streamStr.str("");
        roundAns.clear();
        if (found != string::npos) {

            i = found + 1;
            while(i <= exp.length()){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i++;
                    break;
                }
                else{
                    end = i;
                    i++;
                }
            }
            range2 = end - found +1;
            string term = exp.substr(found+1, range2);
            //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2>> term2;
            i = found-1;
            while(i >= 0){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i--;
                    break;
                }
                else{
                    end = i;
                    i--;
                }
            }
            range1 = found-end;
            term = exp.substr(end, range1);
            stringstream streamDou1(term);
            streamDou1>> term1;

            ans = term1/term2;
            streamStr <<ans;
            roundAns = streamStr.str();
            exp.replace(end, range1+range2, roundAns);
            found = exp.find("/");
            step = "Divide Terms: " + exp + " = " + this->getRight();
            steps.push_back(step);
            //cout << step << endl;
        }
        else {
            break;
        }
        this->setLeft(exp);
    }

}

void display::multiply(string express){
    string exp = express;
    double ans ;
    int i = 0;
    int range1 =0;
    int range2 =0;
    double term1;
    double term2;
    int end;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("*");
    while(1) {
        out.str(string());
        streamStr.str("");
        roundAns.clear();

        if (found != string::npos) {

            i = found + 1;
            while(i <= exp.length()){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i++;
                    break;
                }
                else{
                    end = i;
                    i++;
                }
            }
            range2 = end - found +1;
            string term = exp.substr(found+1, range2);
            //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2>> term2;
            i = found-1;
            while(i >= 0){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i--;
                    break;
                }
                else{
                    end = i;
                    i--;
                }
            }
            range1 = found-end;
            term = exp.substr(end, range1);
            stringstream streamDou1(term);
            streamDou1>> term1;

            ans = term1*term2;
            streamStr <<ans;
            roundAns = streamStr.str();
            exp.replace(end, range1+range2, roundAns);
            found = exp.find("*");
            step = "Multiply Terms: " + exp + " = " + this->getRight();
            steps.push_back(step);
            //cout << step << endl;
        }
        else {
            break;
        }
        this->setLeft(exp);
    }
}
void display::addition(string express){
    string exp = express;
    double ans ;
    int i = 0;
    int range1 =0;
    int range2 =0;
    double term1;
    double term2;
    int end;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("+");
    while(1) {
        out.str(string());
        streamStr.str("");
        roundAns.clear();
        if (found != string::npos) {

            i = found + 1;
            while(i <= exp.length()){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i++;
                    break;
                }
                else{
                    end = i;
                    i++;
                }
            }
            range2 = end - found +1;
            string term = exp.substr(found+1, range2);
            //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2>> term2;
            i = found-1;
            while(i >= 0){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i--;
                    break;
                }
                else{
                    end = i;
                    i--;
                }
            }
            range1 = found-end;
            term = exp.substr(end, range1);
            stringstream streamDou1(term);
            streamDou1>> term1;

            ans = term1+term2;
            streamStr <<ans;
            roundAns = streamStr.str();
            exp.replace(end, range1+range2, roundAns);
            found = exp.find("+");
            step = "Add Terms: " + exp + " = " + this->getRight();
            steps.push_back(step);
            //cout << step << endl;
        }
        else {
            break;
        }
        this->setLeft(exp);
    }

}
void display::subtract(string express){
    string exp = express;
    double ans ;
    int i = 0;
    int range1 =0;
    int range2 =0;
    double term1;
    double term2;
    int end;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("-");
    while(1) {
        out.str(string());
        streamStr.str("");
        roundAns.clear();
        if (found != string::npos) {

            i = found + 1;
            while(i <= exp.length()){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i++;
                    break;
                }
                else{
                    end = i;
                    i++;
                }
            }
            range2 = end - found +1;
            string term = exp.substr(found+1, range2);
            //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2>> term2;
            i = found-1;
            while(i >= 0){
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                    i--;
                    break;
                }
                else{
                    end = i;
                    i--;
                }
            }
            range1 = found-end;
            term = exp.substr(end, range1);
            stringstream streamDou1(term);
            streamDou1>> term1;

            ans = term1-term2;
            streamStr <<ans;
            roundAns = streamStr.str();
            exp.replace(end, range1+range2, roundAns);
            found = exp.find("-");
            step = "Subtract Terms: " + exp + " = " + this->getRight();
            steps.push_back(step);
            //cout << step << endl;
        }
        else {
            break;
        }
        this->setLeft(exp);
    }

}

void display::subLeft(string express, double n){
    string exp = express;
    int range1 =0;
    int range2 =0;
    double term1 = 1;
    double term2 = 1;
    int end;
    double ans ;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;
    streamStr<<fixed<<setprecision(2);
    int i = 0;
    //string exp = this->getUpdatelhs();
    size_t found = exp.find("x");
    //while(1) {
        if(found != string::npos) {
            //cout<<"foundx at"<<found<<endl;


            i = found + 1;
            if(exp[i] == '/'){
                //cout<<"foundDivision"<<endl;
                i++;
                while(i <= exp.length()){
                    if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||exp[i] == '/'){
                        i++;
                        break;
                    }
                    else{
                        end = i;
                        i++;
                    }
                }
                range2 = end - found-1;

                string term = exp.substr(found+2, range2);
                //cout<<"end"<<end<<"range"<<range2<<"term"<<term<<endl;

                //if term contains variable could remove and compute and then add back in
                stringstream streamDou2(term);
                streamDou2>> term2;
                i = found-1;
                if(isdigit(exp[i])){
                    //cout<<"found coeff"<<endl;
                    while (i >= 0) {
                        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                            i--;
                            break;
                        } else {
                            end = i;
                            i--;
                        }
                    }

                    range1 = found - end;
                    string term = exp.substr(end, range1);
                    stringstream streamDou1(term);
                    streamDou1 >> term1;
                    //cout<<"end"<<end<<"range"<<range1<<"term"<<term<<endl;
                }
                ans = term1/term2;
                streamStr <<ans;
                roundAns = streamStr.str() + 'x';
                //cout<<range1<<range2<<endl;
                //cout<<"before"<<exp<<"end"<<end<<"range"<<range1+range2<<endl;
                exp.replace(end, range1 + range2 + 2, roundAns);
                //cout<<"divisor"<<term2<<", "<<range2<<endl;
                //cout<<"answer"<<roundAns<<endl;
                found = exp.find("x");
                //cout<<"gotnothing"<<endl;
                exp.replace(found, 1, "*"+ to_string(n));

            }
            else{
                found = exp.find("x");
                exp.replace(found, 1, to_string(n));
            }
                //cout<<"replace"<<exp<<endl;

        //}
        //else{
        //    break;
        //}

    }

    this->setLeft(exp);
    //cout<<exp<<endl;

}



void display::printsteps(){

    for (unsigned n=0; n<steps.size(); ++n) {
        cout << steps.at( n ) << "\n";
    }

}

void display::divideIso(string express){
    string exp = express;
    int ans;
    string step;
    size_t num = count(exp.begin(), exp.end(), '/');
    size_t found = exp.find("/");
    int rounds = 0;
    while(rounds <= num){
        rounds++;
        if (found != string::npos) {
            char termx = equ.at(found - 1);
            char termy = equ.at(found + 1);
            cout << "terms :" << termx << ", " << termy << endl;
            //ans = (termx - '0')/(termy - '0');
            //exp.replace(found - 1, 3, to_string(ans));
            found = exp.find("/");

            step = "Multiply: " + exp + " * " + termy +" = " + this->getRight()+ " * " + termy;
            steps.push_back(step);
            cout << step << endl;
        }
        else {
            break;
        }
    }
    this->setLeft(exp);

}



/*void plotAndSave()
{
    //create linearEquation object

    // Prepare data.
    int n = 500;
    std::vector<double> x(n), y(n);
    for(int i=0; i<n; i++) {
        x.at(i) = i*10;
        y.at(i) = function(i+10);

    }
    // Plot line from given x and y data. Color is selected automatically.
    //plt::plot(x, y);
    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot("print fraction from equ object", x, z);

    // Set x-axis to interval
    plt::xlim(0, 500*10);

    // Save the image (file format is determined by the extension)
    plt::save("./graphout.png");
}*/

//string Display::showSteps(){
//print original statement
//cout<< equ<< endl;
//check if ^ is after a varaible or number
//if number compute
//if not wait
//search vector for + or -
//get value that follows
//do opposite of the sign on both sides
//print
//search vector for * or
//get value that follows
//do opposite of the sign on both sides
//print
//if still ^ with var square root both sides

//}

//generate plot for single point
void display::solvePoint(double n){
    this->subLeft(this->getLeft(),n);
    exponent(this->getUpdatelhs());
    divide(this->getUpdatelhs());
    multiply(this->getUpdatelhs());
    addition(this->getUpdatelhs());
    subtract(this->getUpdatelhs());
    //this->printsteps();
}

/*void plot(vector<double> x, vector<double> y){
    plt::figure();
    plt::plot(x,y, "b");
    plt::xlim (0, 100*100);
    plt::title("test");
    plt::legend();
    plt::save("./test.png");
}*/