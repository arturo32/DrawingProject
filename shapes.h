#ifndef SHAPES_H
#define SHAPES_H

#include "types.h"
#include <stdio.h>

Image polygon(Image picture, FILE *fileTXT, Pixel *currentColor);
Image line2(Image picture, Pixel* currentColor, int x0, int y0, int x1, int y1);
Image line(Image picture, Pixel* currentColor, FILE* fileTXT);

Image paintMatchingPoints(int centerX, int centerY, int x, int y, Pixel* currentColor, Image picture);
Image circle(Image picture, Pixel* currentColor, FILE* fileTXT);
Image rect(Image picture, Pixel* currentColor, FILE* fileTXT);

#endif
