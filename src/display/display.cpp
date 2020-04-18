#include <display.h>
//GOAL:
//2 + 3x = y
//x^2 + 1 = 5
//1 * 7 + 2^3 = x

display::display(const string& equation) {
    string equ = equation;
    size_t pos = 0;
    string lhs;
    string rhs;
    int add = 0;
    int sub = 0;
    int mult = 0;
    int div = 0;
    int exp = 0;
    split(equation);
}

//split left and right side

display::split(const string& equ){
    string delimiter = "=";
    pos = equ.find(delimiter);
    lhs = equ.substr(0, pos);
    rhs = equ;
    rhs.erase(0, pos + delimiter.length());

    pos = 0;
    queue <char> terms;
    string term;
    while (pos != equ.length()) {

        if (equ.at(pos) == "+") {
            if(!term.empty()) {
                //evaluate?
                //check type of term and push to queue
            }
            que.push("a");
            add++;
        } else if (equ.at(pos) == "-") {
            if(!term.empty()) {
                //evaluate?
                //check type of term and push type to queue and push term to terms queue
                //clear term for next
            }
            que.push("s");
            sub++;
        } else if (equ.at(pos) == "*") {
            if(!term.empty()) {
                //evaluate?
                //check type of term and push to queue
            }
            que.push("m");
            mult++;
        } else if (equ.at(pos) == "/") {
            if(!term.empty()) {
                //evaluate?
                //check type of term and push to queue
            }
            que.push("d");
            div++;
        } else if (equ.at(pos) == "^") {
            if(!term.empty()) {
                //evaluate?
                //check type of term and push to queue
            }
            que.push("e");
            exp++;
        }
        else{
            term << equ.at(pos);
            print term
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
            break;*/
        }

        term = equ.substr(prev, pos);
        if (term.find("x") || term.find("y")){
            int poly;//create a polynomial term
            queP.push(poly);

        }
        else

    }
}



    /*queue <Fraction> queF;
    queue <Polynomial> queP;
    pos = -1;
    int num, denom;
    int start = 0;
    int oper = -1;
    int prev = 0;
    //go through string separate term and operators*/



}

string display::toAnswer(){
    string answer = "The answer to " + lhs + "is equal to:\n" + rhs;
    return answer;
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

int main (){
    string equation = "1 * 7 + 2^3 = x";
    display test = display(equation);
    test.showAnswer
}