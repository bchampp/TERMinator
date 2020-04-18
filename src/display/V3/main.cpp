#include <iostream>
#include "Display.h"
//#include<Python.h>
int main() {
   //Three Basic Cases
   string equation1 = "2^3+5-2/1=x";
   string equation2 = "2^3+2x/2+3-1=y";
   string equation3 = "1-4+3*x^2/1-6=1";
   string test1 = "2 + 4y/2 -6*3 = 2";
   display case1 = display(equation1);
   display case2 = display(equation2);
   display case3 = display(equation3);

   cout<<"Case1 Equation: "<<equation1<<endl;
   cout<<"_________________________________________"<<endl;
   cout<<"Show Steps:"<<endl;
   case1.showSteps();
   cout<<"\nAnswer Statement:"<<endl;
   case1.toAnswer();
    cout<<"_________________________________________"<<endl;
    cout<<"_________________________________________\n"<<endl;
    cout<<"Case2 Equation: "<<equation2<<endl;
    cout<<"_________________________________________"<<endl;
    cout<<"Show Steps:"<<endl;
    case2.showSteps();
    cout<<"\nAnswer Statement:"<<endl;
    case2.toAnswer();
    cout<<"_________________________________________"<<endl;
    cout<<"_________________________________________\n"<<endl;
    cout<<"x values"<<endl;
    case2.printVector(case2.getXVal());
    cout<<"y values"<<endl;
    //case2.printVector(case2.getYVal());
    cout<<"Case1 Equation: "<<equation3<<endl;
    cout<<"_________________________________________"<<endl;
    cout<<"Show Steps:"<<endl;
    case1.showSteps();
    cout<<"\nAnswer Statement:"<<endl;
    case1.toAnswer();
    cout<<"_________________________________________"<<endl;
    cout<<"_________________________________________\n"<<endl;

   //matplotlibcpp::plot(case2.getXVal(), case2.getYVal());


}