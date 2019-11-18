#include "painting.h"
#include "types.h"
#include <stdio.h>

// "Clear" all the picture by setting its pixels with the current color.
Image clear(Image picture, FILE* fileTXT, Pixel currentColor){
    int i, j;
    Pixel pixel;

    fscanf(fileTXT, " %hhu %hhu %hhu\n", &pixel.R, &pixel.G, &pixel.B);
    
    for(i = 0; i < picture.height; i++){
    	for(j = 0; j < picture.width; j++){
	        picture.pixels[i][j] = pixel;
        }
    }

    currentColor = pixel;
    return picture;
}

// This fill function only read the info of the txt file and push their to recursiveFill function.
Image fill(Image picture, FILE* fileTXT, Pixel currentColor){
  int i, j, k, x, y;
  fscanf(fileTXT, "%d %d\n", &x, &y);
  Pixel pastColor = picture.pixels[y][x];
  recursiveFill(picture, currentColor, pastColor, x, y);
  return picture;
}

// Fill a space until find its edges or the end of the image.
void recursiveFill(Image picture, Pixel currentColor, Pixel pastColor, int x, int y){
  //If (x, y) is in the bounds of the image
  if(x < picture.width && y < picture.height && x >= 0 && y >= 0){

    //If (x, y) is in the area of same color from the starting pixel
    if(picture.pixels[y][x].R == pastColor.R &&
       picture.pixels[y][x].G == pastColor.G &&
       picture.pixels[y][x].B == pastColor.B){

      //If the function didn't alredy passed by (x, y) 
      if(picture.pixels[y][x].R != currentColor.R ||
         picture.pixels[y][x].G != currentColor.G ||
         picture.pixels[y][x].B != currentColor.B){
        
        //Painting the pixel
        picture.pixels[y][x] = currentColor; 

        recursiveFill(picture, currentColor, pastColor, x+1, y);
        recursiveFill(picture, currentColor, pastColor, x-1, y);
        recursiveFill(picture, currentColor, pastColor, x, y+1);
        recursiveFill(picture, currentColor, pastColor, x, y-1);
      }       
    }
  }
}

// Set the current color to be used.
Pixel color(FILE *fileTXT, Pixel currentColor){

    fscanf(fileTXT, " %hhu %hhu %hhu\n", &currentColor.R, &currentColor.G, &currentColor.B);
    return currentColor;
}

// Paints the corresponding points in all quadrants of a specific point in the first quadrant.
Image paintCirclePoints(int centerX, int centerY, int x, int y, Pixel currentColor, Image picture){
  picture.pixels[centerY+y][centerX+x] = currentColor;
  picture.pixels[centerY-x][centerX-y] = currentColor;
  picture.pixels[centerY-x][centerX+y] = currentColor;
  picture.pixels[centerY+x][centerX-y] = currentColor;
  picture.pixels[centerY+x][centerX+y] = currentColor;
  picture.pixels[centerY-y][centerX-x] = currentColor;
  picture.pixels[centerY-y][centerX+x] = currentColor;
  picture.pixels[centerY+y][centerX-x] = currentColor;

  return picture;
}
