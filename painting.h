#ifndef PAINTING_H
#define PAINTING_H

#include "types.h"
#include <stdio.h>
Image fill(Image picture, FILE* fileTXT, Pixel* currentColor);
Image clear(Image picture, FILE* fileTXT, Pixel* currentColor);


#endif
