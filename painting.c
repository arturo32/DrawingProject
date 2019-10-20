#include "painting.h"
#include "types.h"

Image clear(Image picture, Pixel pixel){
    int i, j;
    //Creating a image with the specific pixel

    for(i = 0; i < picture.height; i++){
    	for(j = 0; j < picture.width; j++){
	        picture.pixels[i][j] = pixel;
        }
    }
    return picture;
}
//fill(){}
