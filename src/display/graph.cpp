#include "matplotlibcpp.h"
#include <cmath>

namespace plt = matplotlibcpp;

int main() 
{
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
    plt::named_plot("your function", x, z);

    // Set x-axis to interval
    plt::xlim(0, 500*10);
  
    // Save the image (file format is determined by the extension)
    plt::save("./graphout.png");
}

// g++ graph.cpp -lpython2.7