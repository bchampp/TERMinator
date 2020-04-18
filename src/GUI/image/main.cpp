#include "image.h"

int main(){
    string file = "Sample1.png";
    Image test = Image(file);
    cout << "Text is: " << test.imageToText(file) << endl;
}