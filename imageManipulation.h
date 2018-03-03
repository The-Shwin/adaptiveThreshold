#ifndef IMAGE_MANIPULATION
#define IMAGE_MANIPULATION

#include "pgmIO.h"

/* Performs a gaussian blur on the image.*/
Image* gaussianWeightedThreshold(Image *im);

Image* meanBasedThreshold(Image *im);

#endif
