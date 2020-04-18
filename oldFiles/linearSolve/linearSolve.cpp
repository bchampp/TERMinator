#include "linearSolve.h"

using namespace std;

linearEquation::linearEquation(string filename){
    ifstream inFile;
    inFile.open(filename);

    if (!inFile) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop  
    }

    char term;

    while (inFile >>term) {
        eqn.push_back(term);
        cout<<term;
        }
    cout<<endl;
    inFile.close();
    splitEquation(eqn);

    
}

Fraction linearEquation::operate(char op, Fraction fracA,Fraction fracB){
    if(op == '+'){
        return fracA + fracB;
    }
    else if(op == '-'){
        return fracA - fracB;
    }
    else if(op == '/'){
        return fracA/fracB;
    }
    else if(op == '*'){
        return fracA*fracB;
    }
    else{
        Fraction err(0);
        cout<<"nooooo"<<endl;
        return err;

    }
}

void linearEquation::splitEquation(vector<char> eq){
      for(vector <char> :: iterator it = eq.begin(); it != eq.end(); ++it){
          if(*it == '='){
              vector<char> tempLHS;
              vector<char> tempRHS;
              vector<char>::iterator iR = eq.end();
              iR--;
              vector<char>::iterator iL = eq.begin();
              cout<<"left hand side"<<endl;
              while(iL < it){
                  tempLHS.push_back(*iL);
                  cout<<*iL<<endl;
                  iL++;
              }
              cout<<"right hand side"<<endl;
              while(iR > it){
                  tempRHS.push_back(*iR);
                  cout<<*iR<<endl;
                  iR--;
              }
              setLHS(tempLHS);
              setRHS(tempRHS);
              break;
          }
        
        }
}

Fraction linearEquation::simplify(vector<Fraction> nums,vector<char> ops){

    int size = static_cast<int>(nums.size());
    if(size>2){
        char t = ops.back();
        Fraction F = nums.back();
        nums.pop_back();
        ops.pop_back();
        return operate(t,simplify(nums,ops),F);

    }
    else
    {
       return operate(ops.front(), nums.front(),nums.back());
    }
    
}
void linearEquation::setLHS(vector<char> terms){
    for(vector<char>::iterator it = terms.begin();it!= terms.end();++it){
        char ct = *it;

        // check if its a number thats followed by a letter
        // code here
        if((int)ct > 96 && (int)ct <109){
            Fraction frac(1,1);
            lhsVars.push_back(frac);
        }
        if(((int)(ct+1) > 96 && (int)(ct+1) <109)&& ((int)ct > 47 && (int)ct < 58)){
            int num = (int)ct;
            Fraction frac(num,1);
            lhsVars.push_back(frac);
        }

        if((int)ct > 47 && (int)ct < 58 ){  // if its a number
            int temp = (int)ct -48;
            Fraction aNum(temp,1);
            lhsNums.push_back(aNum);
        }
        else if((int)ct == 43){ // plus
            lhsOps.push_back(ct);
        }
        else if((int)ct == 45){
            lhsOps.push_back(ct);
        }
        else if((int)ct == 47){ // divide
            lhsOps.push_back(ct);
        }
        else if((int)ct == 42){
            lhsOps.push_back(ct);
        }

    }

}

void linearEquation::setRHS(vector<char> terms){
    for(vector<char>::iterator it = terms.begin();it!= terms.end();++it){
        char ct = *it;
        if((int)ct > 47 && (int)ct < 58 ){  // if its a number
            int temp = (int)ct -48;
            Fraction aNum(temp,1);
            cout<<"number"<<endl;
            cout<<aNum;
            rhsVars.push_back(aNum); 
        }
        else if((int)ct == 43){ // plus
            cout<<"operator:"<<endl;
            cout<<ct<<endl;
            rhsOps.push_back(ct);
        }
        else if((int)ct == 45){
            cout<<"operator:"<<endl;
            cout<<ct<<endl; // minus
            rhsOps.push_back(ct);
        }
        else if((int)ct == 47){ // divide
            cout<<"operator:"<<endl;
            cout<<ct<<endl;
            rhsOps.push_back(ct);
        }
        else if((int)ct == 42){
            cout<<"operator:"<<endl;
            cout<<ct<<endl;
            rhsOps.push_back(ct);
        }

    }

}



int main(){
    cout<<"Equation Solver: Enter a filename: "<<endl;
    string filename;
    cin >> filename;
    linearEquation leq(filename);
    cout<<"the left hand simplified:"<<endl;
    cout<<leq.simplify(leq.lhsNums, leq.lhsOps)<<endl;
}


