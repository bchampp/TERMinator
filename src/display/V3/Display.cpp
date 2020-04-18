//
// Created by shayn on 2019-11-22.
//

#include <Display.h>
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
    steps;

}

display::display(const string& equation) {
    equ = stringPrep(equation);
    //equ = equation;
    statement = "";
    steps;
    //unordered_multimap<char, string> terms;

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

//code that adds '^' and removes spaces

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


void display::showSteps(){
    int leftVar = 0;
    int rightVar = 0;
    vector<double> x;
    vector<double> y;
    string var = "";

    for(int i = 0; i < this->getLeft().length(); i ++) {
        if (isalpha(this->getLeft()[i])) {
            leftVar++;
            var = this->getLeft()[i];
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
        reduceVar(this->getLeft(), var);
        exponent(this->getUpdatelhs());
        divide(this->getUpdatelhs());
        multiply(this->getUpdatelhs());
        addition(this->getUpdatelhs());
        subtract(this->getUpdatelhs());
        addSubIso(this->getUpdatelhs());
        multDivIso(this->getUpdatelhs());



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
    int pos = 0;
    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("^", pos);
    while(1) {
        out.str(string());
        streamStr.str("");
        roundAns.clear();
        if(isalpha(exp[found-1])){
            pos = found+ 1;
            found = exp.find("^", pos);
        }
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
            found = exp.find("^", pos);
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
    int pos = 0;
    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("/", pos);
    while(1) {
        if(isalpha(exp[found-1])){
            pos = found+1;
        }
        found = exp.find("/", pos);
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
            found = exp.find("/", pos);
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
    int pos = 0;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("*", pos);
    while(1) {
        if(isalpha(exp[found+1])){
            pos = found+2;
        }
        found = exp.find("*", pos);
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
    int pos = 0;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("+");
    while(1) {
        if(isalpha(exp[found-1])){
            pos = found+1;
        }
        if (isalpha(exp[found+1])) {
            pos = found + 2;
        }
        found = exp.find("+", pos);
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
            found = exp.find("+", pos);
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
    int pos = 0;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;

    streamStr<<fixed<<setprecision(2);
    size_t found = exp.find("-", pos);
    while(1) {
        if(isalpha(exp[found-1])){
            pos = found+1;
        }
        if (isalpha(exp[found+1])) {
            pos = found + 2;
        }
        found = exp.find("-", pos);
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
            found = exp.find("-", pos);
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
void display::reduceVar(string express, string var) {
    string exp = express;
    int range1 = 0;
    int range2 = 0;
    double term1 = 1;
    double term2 = 1;
    int end;
    double ans;
    string roundAns;
    stringstream out;
    string step;
    ostringstream streamStr;
    streamStr << fixed << setprecision(2);
    int i = 0;
    //string exp = this->getUpdatelhs();
    size_t found = exp.find(var);

    int size = 0;
    //while(1) {
    if (found != string::npos) {

        cout<<"foundx at"<<found<<endl;
        size++;

        i = found + 1;
        if (exp[i] == '/') {
            //cout<<"foundDivision"<<endl;
            i++;
            while (i <= exp.length()) {
                if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                    i++;
                    break;
                } else {
                    end = i;
                    i++;
                }
            }
            range2 = end - found - 1;

            string term = exp.substr(found + 2, range2);
            size += term.length();
            size++;
            //cout<<"end"<<end<<"range"<<range2<<"term"<<term<<endl;

            stringstream streamDou2(term);
            streamDou2 >> term2;
            i = found - 1;
            if (exp[i] =='*') {
                     i--;
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
                size+=term.length();
                stringstream streamDou1(term);
                streamDou1 >> term1;
                //cout<<"end"<<end<<"range"<<range1<<"term"<<term<<endl;
            }
            ans = term1 / term2;
            streamStr << ans;
            roundAns = streamStr.str();
            //cout<<range1<<range2<<endl;
            cout<<"before"<<exp<<"end"<<end<<"range"<<size<<endl;
            exp.replace(end, size, roundAns + "*" + var);
            //cout<<"divisor"<<term2<<", "<<range2<<endl;
            //cout<<"answer"<<roundAns<<endl;

        }
        cout<<exp<<endl;
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
    /* if(found != string::npos) {
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
         else{*/
                found = exp.find("x");
                if (found == string::npos){
                    found = exp.find("y");
                }
                exp.replace(found, 1, to_string(n));
            //}
                //cout<<"replace"<<exp<<endl;

        //}
        //else{
        //    break;
        //}

    //}

    this->setLeft(exp);
    //cout<<exp<<endl;

}



void display::printsteps(){

    for (unsigned n=0; n<steps.size(); ++n) {
        cout << steps.at( n ) << "\n";
    }

}

void display::addSubIso(string express){
    ostringstream streamStr;
    string exp = express;
    size_t found_s = 0;
    size_t found_p = 0;
    string right;
    double right_num;
    int end;
    double term_;
    int i = 0;
    string step;
    while (1){
        if(found_s == string::npos && found_p == string::npos){
            break;
        }
   // handles first term if positive constant
        if ( exp[i] && isdigit(exp[i]) && i == 0){
            while(i <= exp.length()){
                //should check if it contains a var
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] =='/'){
                    i++;
                    break;
                }
                else if(isalpha(exp[i])){
                    i++;
                    break;
                }
                else{
                    end = i;
                    i++;
                }
            }
            if(exp[i] == '*' || exp[i] =='/'){
                i++;
                break;
            }
            string term = exp.substr(0, end+1);
            //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2>> term_;
            step = "Subtract off Addition: " + this->getUpdatelhs() + "-" + term + " = " + this->getUpdaterhs() + "-" + term;
            steps.push_back(step);
            //cout<<step<<endl;
            exp.erase(0, end+1);
            if(exp[0]== '+'){
                exp.erase(0, 1);
            }

            right = this->getUpdaterhs();
            //cout<< right << " right"<<endl;
            stringstream streamR(right);
            streamR>> right_num;
            //cout<<"term"<<term<< " - " << right_num;
            right_num = right_num - term_;
            //cout<<" = "<< right_num<<endl;
            streamStr.str("");
            streamStr <<right_num;

            right = streamStr.str();
            this->setLeft(exp);
            this->setRight(right);
            step = "Reduce: "+ this->getUpdatelhs() + " = " + this->getUpdaterhs();
            //cout<<step<<endl;
            steps.push_back(step);
        }

         found_p = exp.find('+');
         found_s = exp.find('-');
        //cout<<found_p<<endl;
        //cout<<found_s<<endl;
            if(found_p < found_s){
                //cout<<"+ found"<<endl;
                i = found_p + 1;
                //cout<<"+ foind at "<<i -1<<endl;
                while(1) {
                    if(i == exp.length()){
                        //cout<<"here"<<endl;
                        break;
                    }
                    //should check if it contains a var
                    if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                        break;
                    } else if (isalpha(exp[i])) {

                        continue;
                    } else {
                        end = i;
                        i++;
                    }
                }
                //cout<< "i i s: "<<i<<endl;
                int range_p = end - found_p;
                //cout<<"got out at "<< end<< "range" << range_p<<endl;

                string term = exp.substr(found_p + 1, range_p);                //if term contains variable could remove and compute and then add back in
                stringstream streamDou2(term);
                streamDou2>> term_;

                step = "Subtract Opposite of Addition: " + this->getUpdatelhs() + "-" + term + " = " + this->getUpdaterhs() + "-" + term;
                steps.push_back(step);
                //cout<<step<<endl;
                exp.erase(found_p, range_p + 1);

                right = this->getUpdaterhs();
                //cout<< right << " right"<<endl;
                stringstream streamR(right);
                streamR>> right_num;
                //cout<<"term"<<term<< " - " << right_num;
                right_num = right_num - term_;
                //cout<<" = "<< right_num<<endl;
                streamStr.str("");
                streamStr <<right_num;
                right = streamStr.str();
                //cout<<"right = "<<right<<endl;
                this->setLeft(exp);
                this->setRight(right);
                step = "Reduce: "+ this->getUpdatelhs() + " = " + this->getUpdaterhs();
                //cout<<step<<endl;
                steps.push_back(step);
                found_p = exp.find('+');
                found_s = exp.find('-');
                }
            else if(found_p > found_s){

                i = found_s + 1;
                //cout<<"- foind at "<<i -1<<endl;
                while(1) {
                    if(i == exp.length()){
                        //cout<<"here"<<endl;
                        break;
                    }
                    //should check if it contains a var
                    if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                        break;
                    } else if (isalpha(exp[i])) {
                        break;
                    } else {
                        end = i;
                        i++;
                    }
                }
                //cout<< "i i s: "<<i<<endl;
                int range_s = end - found_s;
                //cout<<"got out at "<< end<< "range" << range_s<<endl;

                string term = exp.substr(found_s + 1, range_s);                //if term contains variable could remove and compute and then add back in
                stringstream streamDou2(term);
                streamDou2>> term_;

                step = "Add Opposite of Subtraction: " + this->getUpdatelhs() + "+" + term + " = " + this->getUpdaterhs() + "+" + term;
                steps.push_back(step);
                //cout<<step<<endl;
                exp.erase(found_s, range_s + 1);

                right = this->getUpdaterhs();
                //cout<< right << " right"<<endl;
                stringstream streamR(right);
                streamR>> right_num;
                //cout<<"term"<<term<< " + " << right_num;
                right_num = right_num + term_;
               // cout<<" = "<< right_num<<endl;
                streamStr.str("");
                streamStr <<right_num;
                right = streamStr.str();
                //cout<<"right = "<<right<<endl;
                if (exp[0] == '+'){
                    exp.erase(0, 1);
                }
                this->setLeft(exp);
                this->setRight(right);
                step = "Reduce: "+ this->getUpdatelhs() + " = " + this->getUpdaterhs();
                //cout<<step<<endl;
                steps.push_back(step);


                found_p = exp.find('+');
                found_s = exp.find('-');
            }
            else{
                cout<<"done"<<endl;
                break;
                //can't be equal so until end so much be done
            }

        }

    for (vector<string>::iterator i = this->steps.begin(); i != this->steps.end(); i++)
        std::cout << *i <<endl;
    }

    //same as above for * and /

    //reducing to solve for x
    //exponents

void display::multDivIso(string express){
    ostringstream streamStr;
    string exp = express;
    size_t found_s = 0;
    size_t found_p = 0;
    string right;
    double right_num;
    int end;
    int pos_m = 0;
    int pos_d = 0;
    double term_;
    int i = 0;
    string step;
    found_p = exp.find('*', pos_m);
    found_s = exp.find('/', pos_d);
    cout<< "mult at "<< found_p<<endl;
    if(isalpha(exp[found_p + 1])){
        pos_m = found_p+2;
        found_p = exp.find('*', pos_m);

    }
    if(isalpha(exp[found_p - 1]) ){

        pos_m = found_p +1;
        found_p = exp.find('*', pos_m);

    }
    if(isalpha(exp[found_s + 1])){
        pos_d = found_s +2;
        found_s = exp.find('/', pos_d);
    }
    if(isalpha(exp[found_s - 1]) ){
        pos_d = found_s +1;
        found_s = exp.find('/', pos_d);
    }


    while (1) {

        cout<< "mult at "<< found_p<<endl;
        if (found_s == string::npos && found_p == string::npos) {
            break;
        }
        // handles first term if positive constant

        //cout<<found_p<<endl;
        //cout<<found_s<<endl;
        if (found_p < found_s) {
            //cout<<"+ found"<<endl;
            i = found_p + 1;
            //cout<<"+ foind at "<<i -1<<endl;
            while (1) {
                if (i == exp.length()) {
                    //cout<<"here"<<endl;
                    break;
                }
                //should check if it contains a var
                if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                    break;
                } else if (isalpha(exp[i])) {

                    continue;
                } else {
                    end = i;
                    i++;
                }
            }
            //cout<< "i i s: "<<i<<endl;
            int range_p = end - found_p;
            //cout<<"got out at "<< end<< "range" << range_p<<endl;

            string term = exp.substr(found_p + 1,
                                     range_p);                //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2 >> term_;

            step = "Divide Term: " + this->getUpdatelhs() + "/" + term + " = " +
                   this->getUpdaterhs() + "/" + term;
            steps.push_back(step);
            cout<<step<<endl;
            exp.erase(found_p, range_p + 1);

            right = this->getUpdaterhs();
            //cout<< right << " right"<<endl;
            stringstream streamR(right);
            streamR >> right_num;
            //cout<<"term"<<term<< " - " << right_num;
            right_num = right_num / term_;
            //cout<<" = "<< right_num<<endl;
            streamStr.str("");
            streamStr << right_num;
            right = streamStr.str();
            //cout<<"right = "<<right<<endl;
            this->setLeft(exp);
            this->setRight(right);
            step = "Reduce: " + this->getUpdatelhs() + " = " + this->getUpdaterhs();
            cout<<step<<endl;
            steps.push_back(step);
            found_p = exp.find('*', pos_m);
            found_s = exp.find('/', pos_d);
        } else if (found_p > found_s) {

            i = found_s + 1;
            //cout<<"- foind at "<<i -1<<endl;
            while (1) {
                if (i == exp.length()) {
                    //cout<<"here"<<endl;
                    break;
                }
                //should check if it contains a var
                if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                    break;
                } else if (isalpha(exp[i])) {
                    break;
                } else {
                    end = i;
                    i++;
                }
            }
            //cout<< "i i s: "<<i<<endl;
            int range_s = end - found_s;
            //cout<<"got out at "<< end<< "range" << range_s<<endl;

            string term = exp.substr(found_s + 1,
                                     range_s);                //if term contains variable could remove and compute and then add back in
            stringstream streamDou2(term);
            streamDou2 >> term_;

            step = "Multiply: " + this->getUpdatelhs() + "*" + term + " = " + this->getUpdaterhs() +
                   "*" + term;
            steps.push_back(step);
            cout<<step<<endl;
            exp.erase(found_s, range_s + 1);

            right = this->getUpdaterhs();
            //cout<< right << " right"<<endl;
            stringstream streamR(right);
            streamR >> right_num;
            //cout<<"term"<<term<< " + " << right_num;
            right_num = right_num * term_;
            // cout<<" = "<< right_num<<endl;
            streamStr.str("");
            streamStr << right_num;
            right = streamStr.str();
            //cout<<"right = "<<right<<endl;

            this->setLeft(exp);
            this->setRight(right);
            step = "Reduce: " + this->getUpdatelhs() + " = " + this->getUpdaterhs();
            cout<<step<<endl;
            steps.push_back(step);

        } else {
            cout << "done" << endl;
            break;
            //can't be equal so until end so much be done
        }
        found_p = exp.find('*', pos_m);
        found_s = exp.find('/', pos_d);

    }
}



void display::varIso(string express){
    string exp = express;
    int i = 0;
    double term_;
    string right;
    double right_num;
    ostringstream streamStr;
    int end = exp.length() - 1;
    if(exp.length() ==1){
        //done
        return;
    }
    //two cases
    //multiply or exponent
    //divison is already reduced to multiplication by a decimal
    while(i < exp.length()){
        if(isalpha(exp[i])) {
            i++;
            break;
        }
    }
    if (i>0){
        if(exp[i] == '*'){
            string term = exp.substr(0, i-1);
            stringstream streamDou2(term);
            streamDou2 >> term_;
            string step = "Divide: " + this->getUpdatelhs() +"/"+ term + " = " + this->getUpdaterhs() + "/"+ term;
            //cout<<step<<endl;
            steps.push_back(step);
            right = this->getUpdaterhs();
            //cout<< right << " right"<<endl;
            stringstream streamR(right);
            streamR >> right_num;
            //cout<<"term"<<term<< " + " << right_num;
            right_num = right_num / term_;
            // cout<<" = "<< right_num<<endl;
            streamStr.str("");
            streamStr << right_num;
            right = streamStr.str();
            //cout<<"right = "<<right<<endl;
            exp.erase(0, i);
            this->setLeft(exp);
            this->setRight(right);
            step = "Reduce: " + this->getUpdatelhs() + " = " + this->getUpdaterhs();
            cout<<step<<endl;
            steps.push_back(step);



            //divide right hand side by val

        }
    }
    if(i<exp.length()){
        if(exp[i+1] == '^'){
            //square root rhs
            int range = end - i;
            string term = exp.substr(i+1, range);
            stringstream streamDou2(term);
            streamDou2 >> term_;
            string step = "Take root: " + this->getUpdatelhs() +"root:"+ term + " = " + this->getUpdaterhs() + "root:"+ term;
            //cout<<step<<endl;
            steps.push_back(step);
            right = this->getUpdaterhs();
            //cout<< right << " right"<<endl;
            stringstream streamR(right);
            streamR >> right_num;
            //cout<<"term"<<term<< " + " << right_num;
            right_num = pow(right_num, 1/ term_);
            // cout<<" = "<< right_num<<endl;
            streamStr.str("");
            streamStr << right_num;
            right = streamStr.str();
            //cout<<"right = "<<right<<endl;
            exp.erase(i, end);
            this->setLeft(exp);
            this->setRight(right);
            step = "Reduce: " + this->getUpdatelhs() + " = " + this->getUpdaterhs();
            cout<<step<<endl;
            steps.push_back(step);
        }
    }
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
//I'm going to add in the carrot thing for variables, but there is no way to tell if 22 is twenty-two or 2^2 so kind of faulty
string stringPrep(string exp){
    int i;
    for(i = 0; i < exp.length(); i++){
        if(isalpha(exp[i])){
            //cout<<"found var"<<endl;
            //cout<<"alpha at "<<i<<exp[i]<<endl;
            if(isdigit(exp[i+1])){
                //cout<<"number at "<<i+1<<endl;
                exp.insert(i+1, "^");
            }
            if(isdigit(exp[i-1])){
                exp.insert(i, "*");
                i = i +1;
            }
        }
        if (exp[i] ==' '){
            //cout<<"space at "<<i<<endl;
            exp.erase(i, 1);
            i--;
        }


    }
    size_t found = exp.find("--");
    while(found != string::npos){
        exp.replace(found, 2, "+");
        found = exp.find("--");
    }
    if(exp[0] == '+'){
        exp.erase(0, 1);
    }
    //cout<<"final"<<exp<<endl;
    return exp;
}
/*
void plot(vector<double> x, vector<double> y){
    plt::figure();
    plt::plot(x,y, "b");
    plt::xlim (0, 100*100);
    plt::title("test");
    plt::legend();
    plt::save("./test.png");
}
*/
