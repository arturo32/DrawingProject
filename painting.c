#include "painting.h"
#include "types.h"
#include <stdio.h>

Image clear(Image picture, FILE* fileTXT, Pixel* currentColor){
    int i, j;
    Pixel pixel;

    fscanf(fileTXT, " %hhu %hhu %hhu\n", &pixel.R, &pixel.G, &pixel.B);
    
    for(i = 0; i < picture.height; i++){
    	for(j = 0; j < picture.width; j++){
	        picture.pixels[i][j] = pixel;
        }
    }

    *currentColor = pixel;
    return picture;
}

Image fill(Image picture, FILE* fileTXT, Pixel* currentColor){}

Pixel color(FILE *fileTXT, Pixel currentColor){

    fscanf(fileTXT, " %hhu %hhu %hhu\n", &currentColor.R, &currentColor.G, &currentColor.B);
    return currentColor;
}

Image paintPointsInAllOctants(int centerX, int centerY, int x, int y, Pixel* currentColor, Image picture){
  picture.pixels[centerY+y][centerX+x] = *currentColor;
  picture.pixels[centerY-x][centerX-y] = *currentColor;
  picture.pixels[centerY-x][centerX+y] = *currentColor;
  picture.pixels[centerY+x][centerX-y] = *currentColor;
  picture.pixels[centerY+x][centerX+y] = *currentColor;
  picture.pixels[centerY-y][centerX-x] = *currentColor;
  picture.pixels[centerY-y][centerX+x] = *currentColor;
  picture.pixels[centerY+y][centerX-x] = *currentColor;

  return picture;
}
