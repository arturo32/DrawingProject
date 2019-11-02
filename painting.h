#ifndef PAINTING_H
#define PAINTING_H

#include "types.h"
#include <stdio.h>
Image clear(Image picture, FILE* fileTXT, Pixel* currentColor);
Image fill(Image picture, FILE* fileTXT, Pixel* currentColor);
Pixel color(FILE *fileTXT, Pixel currentColor);


#endif
