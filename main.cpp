#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat testImage0 = imread("testImage0.pgm", CV_LOAD_IMAGE_GRAYSCALE);
    Mat testImage1 = imread("testImage1.pgm", CV_LOAD_IMAGE_GRAYSCALE);
    namedWindow("Display window 1", WINDOW_AUTOSIZE);
    imshow("Display window 1", testImage0);
    waitKey(0);
    namedWindow("Display window 2", WINDOW_AUTOSIZE);
    imshow("Display window 2", testImage1);
    waitKey(0);


    return 0;
}
