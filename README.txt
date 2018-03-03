Name: Ashwin Bhat

I wrote this program via text editor and compiled it in command line.
pgmIO and imageManipulation are written in C while the main file is
a C++ file. Compiling and running them requires the instructions below.

Compiling/Running Instructions (via command line):
Run the following commands in order.
gcc -c -o pgmIO.o pgmIO.c
gcc -c -o imageManipulation.o imageManipulation.c
g++ -w -c -o main.o main.cpp
g++ -o adapThresh pgmIO.o imageManipulation.o main.o

Now that it is compiled this program can be run via the following command:
./adapThresh

This program has two image files code into the main.cpp. These are "testImage0.pgm"
and "testImage1.pgm".

In the imageManipulation files there are functions for thresholding via gaussian
weighted average, average, and a simple global threshold. All three of these
functions are called in main.cpp and the outputs of these functions on the two
test images are saved to the current directory.

Note: This code only works on .pgm image files that have "P5" coded on the first line.
Other images will not work, but the code can be easily modified for that purpose.

Functions
------
The Gaussian Weighted Average thresholding uses a 3x3 Gaussian Kernel and the
sums the values in each window. It uses this weighted average as the threshold.
This works fairly well for testImage0 but it does get rid of a lot of the pixels
in testImage1.

The average method simple takes an average of the values of the 3x3 pixel
neighborhood of the current pixel when iterating through the image. Any pixels
beyond the edges of the image in this method are simply considered black pixels.
This average is then used as a threshold for the current pixel.

The minmax averaging method finds the minimum and maximum pixel intensities and
averages them together. This average is uses as the threshold value.

Finally, the simple thresholding uses the constant threshold intensity of 90 to
binarize the image. 

Outputs:
------
Gaussian Weighted Average Thresholds
"gaussianOutputImage0.pgm"
"gaussianOutputImage1.pgm"

Average Based Thresholds
"avgOutputImage0.pgm"
"avgOutputImage1.pgm"

MinMax Average Threshold
"minmaxOutImage0.pgm"
"minmaxOutImage1.pgm"

Simple Global Thresholds
"simpleOutImage0.pgm"
"simpleOutImage1.pgm"
