#ifndef PAINTING_H
#define PAINTING_H

#include "types.h"
#include <stdio.h>
Image clear(Image picture, FILE* fileTXT, Pixel currentColor);
Image fill(Image picture, FILE* fileTXT, Pixel currentColor);
void recursiveFill(Image picture, Pixel currentColor, Pixel pastColor, int x, int y);
Pixel color(FILE *fileTXT, Pixel currentColor);
Image paintCirclePoints(int centerX, int centerY, int x, int y, Pixel currentColor, Image picture);

#endif
