#include <iostream>

extern "C" {
  #include "pgmIO.h"
  #include "imageManipulation.h"
}

using namespace std;

int main(int argc, char** argv) {
    char *fileName1 = "testImage0.pgm";
    char *fileName2 = "testImage1.pgm";
    Image *testImage0 = readPGMImage(fileName1);
    Image *testImage1 = readPGMImage(fileName2);

    char *outFile1 = "outputImage0.pgm";
    char *outFile2 = "outputImage1.pgm";

    Image *output1 = adaptiveThreshold(testImage0);
    writePGMImage(output1, outFile1);
    Image *output2 = adaptiveThreshold(testImage1);
    writePGMImage(output2, outFile2);

    return 0;
}
