#include <iostream>

extern "C" {
  #include "pgmIO.h"
  #include "imageManipulation.h"
}

int main(int argc, char** argv) {
    char *fileName1 = "testImage0.pgm";
    char *fileName2 = "testImage1.pgm";
    Image *testImage0 = readPGMImage(fileName1);
    Image *testImage1 = readPGMImage(fileName2);

    char *gaussOutFile1 = "gaussianOutputImage0.pgm";
    char *gaussOutFile2 = "gaussianOutputImage1.pgm";

    Image *output1 = gaussianWeightedThreshold(testImage0);
    writePGMImage(output1, gaussOutFile1);
    Image *output2 = gaussianWeightedThreshold(testImage1);
    writePGMImage(output2, gaussOutFile2);

    char *avgOutFile1 = "avgOutputImage0.pgm";
    char *avgOutFile2 = "avgOutputImage1.pgm";
    Image *output3 = meanBasedThreshold(testImage0);
    Image *output4 = meanBasedThreshold(testImage1);

    writePGMImage(output3, avgOutFile1);
    writePGMImage(output4, avgOutFile2);

    char *simpleOutFile1 = "simpleOutImage0.pgm";
    char *simpleOutFile2 = "simpleOutImage1.pgm";
    Image *output5 = globalThreshold(testImage0);
    Image *output6 = globalThreshold(testImage1);

    writePGMImage(output5, simpleOutFile1);
    writePGMImage(output6, simpleOutFile2);

    return 0;
}
