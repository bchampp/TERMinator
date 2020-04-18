#include <terminator.h>

using namespace std;
using namespace cv;

string File = "../res/openCV/colorEquation.jpg";

int main(){
    Mat Image = imread(File); // Open Image
    Mat edges;
	Mat grayImage = imread(File, 0); //Open Image in grayscale
    // Put image on the screen
    namedWindow("Initial Image", WINDOW_AUTOSIZE);
    imshow("Initial Image", Image);
	imshow("Gray Image", grayImage);
    // Extract Edges from image
    edges.create(grayImage.size(), grayImage.type());
    blur(grayImage, grayImage, Size(3, 3));
    Canny(grayImage, edges, 50, 75*3, 3);
    namedWindow("Edges extracted", WINDOW_AUTOSIZE);
    imshow("Edges extracted", edges);
	imwrite("imgEdges.jpg", edges);
	imwrite("imgGray.jpg", grayImage);

    waitKey(0); // So that program doesn't end instantly
	Image.release();
	grayImage.release();
	edges.release();
    cout << "Worked succesfully" << endl;
}
