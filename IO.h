#ifndef IO_H
#define IO_H

#include "types.h"
#include <stdio.h>

Image newImage(FILE *fileTXT);
void save(Image picture, FILE *fileTXT);
Pixel color(FILE *fileTXT, Pixel currentColor);


#endif
