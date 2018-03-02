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

extern const Pixel black;
extern const Pixel white;
extern const Pixel gray;

/* Read PGM image from a file */
Pixel *readPGMFile(int *rows, int *cols, int * shades, FILE *fp);
/* Reads PGM formatted image from filenam */
Pixel *readPGM(int *rows, int *cols, int * shades, char *fileName);
/* Read PGM image, and allocates and returns image.*/
Pixel *readPGMImage(FILE *imfile);

/*Write a PGM formatted image file.*/
int writePGMFile(Pixel *image, int rows, int cols, int shades, FILE *fp);
/*Write a PGM formatted file via file name.*/
int writePGM(Pixel *image, int rows, int cols, int shades, char *fileName);
/*Write an Image.*/
int writePGMImage(Image *image, char *fileName);

/* Utility function: frees pointers.*/
void freeImage(Image **im);

/* allocates a new image of the given size.*/
Image *makeImage(int rows, int cols);

/* allocate and fill new image to make copy.*/
Image *makeCopy(Image *original);

#endif
