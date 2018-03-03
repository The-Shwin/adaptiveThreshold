Name: Ashwin Bhat

I wrote this program via text editor and compiled it in command line.
pgmIO and imageManipulation are written in C while the main file is
a C++ file. Compiling and running them requires the instructions below.

Compiling/Running Instructions (via command line):
------
Run the following commands in order. <br>
`gcc -c -o pgmIO.o pgmIO.c` <br>
`gcc -c -o imageManipulation.o imageManipulation.c` <br>
`g++ -c -o main.o main.cpp` <br>
`g++ -o adapThresh pgmIO.o imageManipulation.o main.o` <br>

Now that it is compiled this program can be run via the following command: <br>
`./adapThresh`

This program has two image files code into the main.cpp. These are "testImage0.pgm"
and "testImage1.pgm".

In the imageManipulation files there are functions for thresholding via gaussian
weighted average, average, and a simple global threshold. All three of these
functions are called in main.cpp and the outputs of these functions on the two
test images are saved to the current directory.

Note: This code only works on .pgm image files that have "P5" coded on the first line.
Other images will not work, but the code can be easily modified for that purpose.
