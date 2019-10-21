#include "painting.h"
#include "types.h"
#include <stdio.h>

Image clear(Image picture, FILE *fileTXT){
    int i, j;
    Pixel pixel;

    fscanf(fileTXT, " %hhu %hhu %hhu\n", &pixel.R, &pixel.G, &pixel.B);
    
    for(i = 0; i < picture.height; i++){
    	for(j = 0; j < picture.width; j++){
	        picture.pixels[i][j] = pixel;
        }
    }
    return picture;
}

//fill(){}
