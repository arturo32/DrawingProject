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

Image fill(Image picture, FILE* fileTXT, Pixel* currentColor){
  int i, j, k, x, y;
  fscanf(fileTXT, "%d %d\n", &x, &y);
  Pixel pastColor = picture.pixels[y][x];
  recursiveFill(picture, *currentColor, pastColor, x, y);
  return picture;
}

void recursiveFill(Image picture, Pixel currentColor, Pixel pastColor, int x, int y){
  if(x < picture.width && y < picture.height && x >= 0 && y >= 0){
    if(picture.pixels[y][x].R == pastColor.R &&
       picture.pixels[y][x].G == pastColor.G &&
       picture.pixels[y][x].B == pastColor.B){
      if(picture.pixels[y][x].R != currentColor.R ||
         picture.pixels[y][x].G != currentColor.G ||
         picture.pixels[y][x].B != currentColor.B){
      
        printf("%d %d\n", x, y);
        picture.pixels[y][x] = currentColor; 
        recursiveFill(picture, currentColor, pastColor, x+1, y);
        recursiveFill(picture, currentColor, pastColor, x-1, y);
        recursiveFill(picture, currentColor, pastColor, x, y+1);
        recursiveFill(picture, currentColor, pastColor, x, y-1);
      }       
    }
  }
}

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
