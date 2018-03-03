#ifndef IMAGE_MANIPULATION
#define IMAGE_MANIPULATION

#include "pgmIO.h"

/* Performs a gaussian weighted average thresholding on the image.*/
Image* gaussianWeightedThreshold(Image *im);
/*Performs an average based thresholding.*/
Image* meanBasedThreshold(Image *im);
/*Performs thresholding via minmax averaging*/
Image* minmaxThreshold(Image *im);
/*Uses a constant threshold for global thresholding.*/
Image* globalThreshold(Image *im);

#endif
