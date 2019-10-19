#include "IO.h"
#include "types.h"
#include <stdlib.h>

Pixel** newImage(int x, int y){
	Image picture;
	picture.x = x;
	picture.y = y;
	
	int i, j;
    
    image = (Pixel**)(malloc(x * sizeof(Pixel*)));
    if(image == NULL){
    	return NULL;
    }

    for(i = 0; i < x; i++){
    	image[i] = (Pixel*)(malloc(y * sizeof(Pixel)));
    	if(image[i] == NULL){
    		return NULL;
    	}
    }

    //Creating a white image
    Pixel p;
    p.R = 255;
    p.G = 255;
    p.B = 255;

    for (i = 0; i < x; ++i){
    	for (j = 0; j < y; ++j){
	        image[i][j] = p;
        }
    }

    return image;

}


//menu(){}?
//color(){}
//save(){}
