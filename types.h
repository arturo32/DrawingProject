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

typedef struct{
    int x0, y0;
    int x1, y1;
}Line;


#endif
