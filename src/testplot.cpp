
#include "matplotlibcpp.h"
#include <cmath>

using namespace std;
namespace plt = matplotlibcpp;

int main() 
{
    // Prepare data.
   int n = 1000;
    std::vector<double> x(n), y(n);
    for(int i = 0; i < n; ++i){
        x.at(i) = i;
        y.at(i) = (3*i)/4 + 7/4;
    }
    plt::figure_size(1200, 780);
    plt::named_plot("y = 3x/4 + 7/4", x, y);
    plt::xlim(0, 1000);
    plt::title("Output Plot");
    plt::legend();
    string plotFile = "plot.png";
    plt::save(plotFile);
    plt::save("./basic.png");
}