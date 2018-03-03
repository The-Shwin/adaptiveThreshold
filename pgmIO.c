#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "pgmIO.h"

Image *readPGMImage(char *filename) {
  Image *im = malloc(sizeof(Image));
  if (im) {
    im->data = readPGM(&(im->rows), &(im->cols), &(im->shades), filename);
    if (!im->data) {
      free(im);
      im = NULL;
    }
  }
  return im;
}

Pixel *readPGM(int *rows, int *cols, int * shades, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp) {
    Pixel *im = readPGMFile(rows, cols, shades, fp);
    fclose(fp);
    return im;
  }

  fprintf(stderr, "Error:pgmIO - failed to open \"%s\" for reading\n", filename);
  return NULL;
}

int readNum(FILE *fp) {
  assert(fp);

  char ch;
  while((ch = fgetc(fp)) == '#') {
    while( ((ch=fgetc(fp)) != '\n') && ch != EOF ) {}
  }
  ungetc(ch, fp);

  int val;
  if (fscanf(fp, "%d", &val) == 1) {
    while(isspace(ch = fgetc(fp))) {
    }
    ungetc(ch, fp);
    return val;
  } else {
    fprintf(stderr, "Error:pgmIO - failed to read number from file\n");
    return -1;
  }
}

Pixel *readPGMFile(int *rows, int *cols, int * shades, FILE *fp) {
  *rows = *cols = *shades = -1;

  if (!fp) {
    fprintf(stderr, "Error:pgmIO - given a bad filehandle\n");
    return NULL;
  }

  char tag[20];
  tag[19]='\0';
  fscanf(fp, "%19s\n", tag);
  if (strncmp(tag, "P5", 20)) {
    fprintf(stderr, "Error:pgmIO - not a PGM (bad tag)\n");
    return NULL;
  }

  *cols = readNum(fp); // cols, then rows (i.e. X size followed by Y size)
  *rows = readNum(fp);
  *shades = readNum(fp);

  if (*cols > 0 && *rows > 0 && *shades == 255) {
    Pixel *image = malloc(sizeof(Pixel) * (*rows) * (*cols));
    if (image) {
      if (fread(image, sizeof(Pixel), (*rows) * (*cols), fp) != (size_t)((*rows) * (*cols))) {
        fprintf(stderr, "Error:pgmIO - failed to read data from file!\n");
        free(image);
        return NULL;
      }g
      return image;
    } else {
      fprintf(stderr, "Error:pgmIO - failed to allocate space for image!\n");
      return NULL;
    }
  } else {
    fprintf(stderr, "Error:pgmIO - bad dimensions for image\n");
    return NULL;
  }

  assert(0);
  return NULL;
}

int writePGMImage (Image *im, char *filename) {
  if (!filename || !im) {
    fprintf(stderr, "Error:pgmIO - null pointer passed to writePGMImage\n");
    return 0;
  }

  return writePGM(im->data, im->rows, im->cols, im->shades, filename);
}


int writePGM(Pixel *image, int rows, int cols, int shades, char *filename) {
  if (!filename || !image) {
    fprintf(stderr, "Error:pgmIO - null pointer passed to writePGM\n");
    return 0;
  }
  FILE *fp = fopen(filename, "w");
  int written = 0;
  if (fp) {
    written = writePGMFile(image, rows, cols, shades, fp);
    fclose(fp);
  } else {
    fprintf(stderr, "Error:pgmIO - failed to open \"%s\" for writing\n", filename);
  }
  return written;
}

int writePGMFile(Pixel *image, int rows, int cols, int shades, FILE *fp) {
  if (!fp) {
    fprintf(stderr, "Error:pgmIO - writePGM given a bad filehandle\n");
    return 0;
  }

  fprintf(fp, "P5\n");
  fprintf(fp, "%d %d\n%d\n", cols, rows, shades);
  int written = fwrite(image, sizeof(Pixel), rows * cols, fp);
  if (written != (rows * cols)) {
    fprintf(stderr, "Error:pgmIO - failed to write data to file!\n");
  }

  return written;
}

void freeImage(Image **im) {
  if (*im) {
    free((*im)->data);
  }
  free(*im);
  *im = NULL;
}

Image *makeImage (int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    return NULL;
  }

  Image *im = malloc(sizeof(Image));
  if (!im || rows <= 0 || cols <= 0) {
    return NULL;
  }

  im->rows = rows;
  im->cols = cols;
  im->shades = 255;

  im->data = malloc((im->rows * im->cols) * sizeof(Pixel));
  if (!im->data) {
    free(im);
    return NULL;
  }

  return im;
}

Image *makeCopy (Image *orig) {
  Image *copy = makeImage(orig->rows, orig->cols);
  if (copy) {
    memcpy(copy->data, orig->data, (copy->rows * copy->cols) * sizeof(Pixel));
  }

  return copy;
}
