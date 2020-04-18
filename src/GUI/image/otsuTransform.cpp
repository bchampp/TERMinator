#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void otsuTransform(string input, Mat& output);

int main(){
    string img = "blah.jpg";
    Mat output;
    otsuTransform(img, output);

    imshow("Initial Image", imread(img));
    imshow("output extracted", output);
    waitKey(0);
}

void otsuTransform(string input, Mat& output){

    Mat grayImage = imread(input, 0); //Open Image in grayscale
    // Put image on the screen
    // namedWindow("Initial Image", WINDOW_AUTOSIZE);
    // imshow("Initial Image", Image);
	// imshow("Gray Image", grayImage);
    // Extract output from image
    output.create(grayImage.size(), grayImage.type());
    cv::threshold(grayImage, output, 0, 255, THRESH_BINARY | THRESH_OTSU);
    // blur(grayImage, grayImage, Size(3, 3));
    // Canny(grayImage, output, 50, 75*5, 3);
}