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

Outputs:
------
Gaussian Weighted Average Thresholds
"gaussianOutputImage0.pgm"
"gaussianOutputImage1.pgm"

Average Based Thresholds
"avgOutputImage0.pgm"
"avgOutputImage1.pgm"

Simple Global Thresholds
"simpleOutImage0.pgm"
"simpleOutImage1.pgm"
