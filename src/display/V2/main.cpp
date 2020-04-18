#include <iostream>
#include "Display.h"

int main() {
   //Three Basic Cases
   string equation1 = "2^3+5-2/1=x";
   string equation2 = "2^3+2x/2+3-1=y";
   string equation3 = "1-4+3*x^2/1-6=1";
   display case1 = display(equation1);
   display case2 = display(equation2);

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
    case2.printVector(case2.getYVal());


//    xVal.push_back(1);
//    xVal.push_back(2);
//    xVal.push_back(3);
//    xVal.push_back(4);
//    xVal.push_back(5);
//    yVal.push_back(11);
//    yVal.push_back(12);
//    yVal.push_back(13);
//    yVal.push_back(14);
//    yVal.push_back(15);

    //matplotlibcpp::plot(xVal, yVal);
    //cout<<test1.getUpdatelhs();
   //test1.showSteps();
   //test1.toAnswer();
    //test1.printsteps();
   //string output = test.toAnswer();
   //cout<<test.toAnswer()<<endl;

  // test1.multiply(test1.getUpdatelhs());
   //cout<<test1.getLeft()<<endl;
   //test1.addSlash(test.getLeft());
   //cout<<test.getUpdatelhs()<<endl;
   //string out = test.removeSlash(test.getLeft());
   //cout<<out<<endl;
   //test.divideIso(test.getLeft());
  // test.split(test.getLeft());
   /* test.exponent(test.getUpdatelhs());
    test.divide(test.getUpdatelhs());
    test.multiply(test.getUpdatelhs());
    test.subtract(test.getUpdatelhs());
    test.addition(test.getUpdatelhs());
    cout<<"output"<<endl;
    test.showSteps();*/

}