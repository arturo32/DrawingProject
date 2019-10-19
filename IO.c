#include "IO.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Image newImage(int x, int y){
	
	int i, j;	
	Image picture;
	picture.height = x;
	picture.width = y;
    
    picture.pixels = (Pixel**)(malloc(x * sizeof(Pixel*)));
    if(picture.pixels == NULL){
    	printf("Error in creating matrix\n");
    	exit(EXIT_FAILURE);
    }

    for(i = 0; i < x; i++){
    	picture.pixels[i] = (Pixel*)(malloc(y * sizeof(Pixel)));
    	if(picture.pixels[i] == NULL){
			printf("Error in creating matrix\n");
    		exit(EXIT_FAILURE);
    	}
    }

    //Creating a white image   
    Pixel p;
    p.R = 255;
    p.G = 255;
    p.B = 255;

    for(i = 0; i < x; i++){
    	for(j = 0; j < y; j++){
	        picture.pixels[i][j] = p;
        }
    }
   
    return picture;

}


//menu(){}?
//color(){}
//save(){}
