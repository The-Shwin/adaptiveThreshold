#include "imageManipulation.h"

Image* gaussianWeightedThreshold(Image *im) {
    Image *new = malloc(sizeof(Image));
    if (!new) {
        return NULL;
    }
    new->rows = im->rows;
    new->cols = im->cols;
    new->shades = im->shades;
    new->data =  malloc((new->rows * new->cols) * sizeof(Pixel));
    if (!new->data) {
        free(new);
        return NULL;
    }
    float gcurr = 0.25;
    float gup = 0.125;
    float gleft = 0.125;
    float gright = 0.125;
    float gdown = 0.125;
    float gur = 0.0625;
    float gul = 0.0625;
    float gdr = 0.0625;
    float gdl = 0.0625;
    unsigned char curr = 0;
    unsigned char up = 0;
    unsigned char left = 0;
    unsigned char right = 0;
    unsigned char down = 0;
    unsigned char ur = 0;
    unsigned char ul = 0;
    unsigned char dr = 0;
    unsigned char dl = 0;
    int rows = im->rows;
    int cols = im->cols;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          if (c - 1 >= 0) {
              left = gleft * im->data[(r*cols)+(c-1)].i;
              if (r - 1 >= 0) {
                  ul = gul * im->data[((r-1)*cols)+(c-1)].i;
              }
              if (r + 1 <= rows) {
                  dl = gdl * im->data[((r+1)*cols)+(c-1)].i;
              }
          }
          if (c + 1 <= cols) {
              right = gright * im->data[(r*cols)+(c+1)].i;
              if (r - 1 >= 0) {
                  ur = gur * im->data[((r-1)*cols)+(c+1)].i;
              }
              if (r + 1 <= rows) {
                  dr = gdr * im->data[((r+1)*cols)+(c+1)].i;
              }
          }
          if (r - 1 >= 0) {
            up = gup * im->data[((r-1)*cols)+c].i;
          }
          if (r + 1 <= rows) {
            down = gdown * im->data[((r+1)*cols)+c].i;
          }
          curr = gcurr * im->data[(r*cols)+c].i;
          unsigned char weightedAvg = down + up + left + right + curr + ul + ur + dl + dr;
          if (im->data[(r*cols)+c].i > weightedAvg) {
              new->data[(r*cols)+c].i = 0;
          } else {
              new->data[(r*cols)+c].i = 255;
          }
          curr = 0;
          up = 0;
          left = 0;
          right = 0;
          down = 0;
          ur = 0;
          ul = 0;
          dr = 0;
          dl = 0;
        }
    }
    return new;
}

Image* meanBasedThreshold(Image *im) {
    Image *new = malloc(sizeof(Image));
    if (!new) {
        return NULL;
    }
    new->rows = im->rows;
    new->cols = im->cols;
    new->shades = im->shades;
    new->data =  malloc((new->rows * new->cols) * sizeof(Pixel));
    if (!new->data) {
        free(new);
        return NULL;
    }
    unsigned char curr = 0;
    unsigned char up = 0;
    unsigned char left = 0;
    unsigned char right = 0;
    unsigned char down = 0;
    unsigned char ur = 0;
    unsigned char ul = 0;
    unsigned char dr = 0;
    unsigned char dl = 0;
    int rows = im->rows;
    int cols = im->cols;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
          if (c - 1 >= 0) {
              left = im->data[(r*cols)+(c-1)].i;
              if (r - 1 >= 0) {
                  ul = im->data[((r-1)*cols)+(c-1)].i;
              }
              if (r + 1 <= rows) {
                  dl = im->data[((r+1)*cols)+(c-1)].i;
              }
          }
          if (c + 1 <= cols) {
              right = im->data[(r*cols)+(c+1)].i;
              if (r - 1 >= 0) {
                  ur = im->data[((r-1)*cols)+(c+1)].i;
              }
              if (r + 1 <= rows) {
                  dr = im->data[((r+1)*cols)+(c+1)].i;
              }
          }
          if (r - 1 >= 0) {
            up = im->data[((r-1)*cols)+c].i;
          }
          if (r + 1 <= rows) {
            down = im->data[((r+1)*cols)+c].i;
          }
          curr = im->data[(r*cols)+c].i;
          unsigned char mean = (down + up + left + right + curr + ul + ur + dl + dr) / 9;
          if (im->data[(r*cols)+c].i >= mean) {
              new->data[(r*cols)+c].i = 0;
          } else {
              new->data[(r*cols)+c].i = 255;
          }
          curr = 0;
          up = 0;
          left = 0;
          right = 0;
          down = 0;
          ur = 0;
          ul = 0;
          dr = 0;
          dl = 0;
        }
    }
    return new;
}

Image* globalThreshold(Image *im) {
    Image *new = malloc(sizeof(Image));
    if (!new) {
        return NULL;
    }
    new->rows = im->rows;
    new->cols = im->cols;
    new->shades = im->shades;
    new->data =  malloc((new->rows * new->cols) * sizeof(Pixel));
    if (!new->data) {
        free(new);
        return NULL;
    }
    int rows = im->rows;
    int cols = im->cols;
    unsigned char curr = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            curr = im->data[(r*cols)+c].i;
            if (curr < 110) {
                new->data[(r*cols)+c].i = 0;
            } else {
                new->data[(r*cols)+c].i = 255;
            }
        }
    }
    return new;
}
