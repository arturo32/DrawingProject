#ifndef TYPES_H
#define TYPES_H

/*Type used to make a matrix of pixel that represents the image and
to store the current color through out the entire code each value for
a color is of the type unsigned char that have the same size of the
maximum value for a color: 255*/
typedef struct{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}Pixel;

/*Type used to store a image formed by a matrix of Pixels and with
height and width information*/
typedef struct{
	Pixel **pixels;
	int height;
	int width;
}Image;

#endif
