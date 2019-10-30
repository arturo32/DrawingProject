#ifndef TYPES_H
#define TYPES_H

typedef struct{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}Pixel;

typedef struct{
	Pixel **pixels;
	int height;
	int width;
}Image;

#endif
