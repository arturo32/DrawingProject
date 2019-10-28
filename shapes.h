#ifndef SHAPES_H
#define SHAPES_H

#include "types.h"
#include <stdio.h>

//circle();
Image polygon(Image picture, FILE *fileTXT, Pixel *current_color);
Image line(Image picture, FILE *fileTXT, Pixel *current_color);
Image line_after_read(Image picture, Line line, Pixel *current_color);

#endif
