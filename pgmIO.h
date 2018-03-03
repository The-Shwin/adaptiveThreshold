#ifndef PGM_IO
#define PGM_IO

#include <stdio.h>
#include <iostream>

typedef struct _point {
    int r;
    int y;
} Point;

typedef struct _pixel {
    unsigned char i;
} Pixel;

typedef struct _image {
    Pixel *data;
    int rows;
    int cols;
    int shades;
} Image;

/* Read PGM image from a file */
Pixel *readPGMFile(int *rows, int *cols, int * shades, FILE *fp);
/* Reads PGM formatted image from filenam */
Pixel *readPGM(int *rows, int *cols, int * shades, char *filename);
/* Read PGM image, and allocates and returns image.*/
Image *readPGMImage(char *filename);

/*Write a PGM formatted image file.*/
int writePGMFile(Pixel *image, int rows, int cols, int shades, FILE *fp);
/*Write a PGM formatted file via file name.*/
int writePGM(Pixel *image, int rows, int cols, int shades, char *filename);
/*Write an Image.*/
int writePGMImage(Image *image, char *filename);

/* Utility function: frees pointers.*/
void freeImage(Image **im);

/* allocates a new image of the given size.*/
Image *makeImage(int rows, int cols);

/* allocate and fill new image to make copy.*/
Image *makeCopy(Image *original);

#endif
