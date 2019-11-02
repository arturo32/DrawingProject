#include "shapes.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

//Image rect(Image picture, Pixel* currentColor, FILE* fileTXT){}
//Image circle(Image picture, Pixel* currentColor, FILE* fileTXT){}

//Line function to be used directly from the polygon function
Image line2(Image picture, Pixel* currentColor, int x0, int y0, int x1, int y1){

    int x, y, e, k, dx, dy, sx, sy;
  
    /*Calculating the differences between the x's and y's
    (they will tell the slope of the line) and checking if the line
    is going from the left to the right (add 1 to x0) or from the right to
    the left (add -1 to x0) and if it is going from the top to the bottom
    (add 1 to y0) or from the bottom to the top (add -1 to y0). All of this
    is to find the octant that the line is placed to follow the Bresenham's
    Algorithm*/
    dx = abs(x1-x0);
    dy = abs(y1-y0);
    sx = x0 < x1 ? 1 : -1; 
    sy = y0 < y1 ? 1 : -1;

    /*e represents the difference in hight(if dx > dy) or width (if dx < dy) 
    from the real line to the point below / in the left of it*/
    e = 0;
    y = y0;
    x = x0;
 
    do{

    /*Setting each pixel to the current color. y and x are switched because
    in matrixes the rows comes before the collumns*/
    picture.pixels[y][x] = *currentColor;
    if(dx > dy){

      //Expression derivated from "e + m >= 0.5"
      if(2*e + 2*dy >= dx){
        y += sy;
        e -= dx;
      }
      e += dy;
      x += sx;
    }
    else{

      //Expression derivated from "e + y/m >= 0.5"
      if(2*e + 2*dx*y1 >= dy){
        x += sx;
        e -= dy*y1;
      }
      e += dx*y1;
      y += sy;
    }

    //"x != x1+sx" to x1 have the chance to be printed (and then added sx) 
    }while(x != x1+sx);

    return picture;
}

//Line function to be used in the MAIN file 
Image line(Image picture, Pixel* currentColor, FILE* fileTXT){
    int x0, y0, x1, y1;
    fscanf(fileTXT, "%d %d %d %d\n", &x0, &y0, &x1, &y1);
    return line2(picture, currentColor, x0, y0, x1, y1);
}

Image polygon(Image picture, FILE *fileTXT, Pixel *currentColor){

    /*fx and fy are the coordinates of the first vertice. They will
    be useful for making the last line of the polygon which conects the
    last vertice to the first*/
    int fx, fy, x0, y0, x1, y1, vertices, i;

    fscanf(fileTXT, " %d %d %d", &vertices, &fx, &fy);
    x0 = fx;
    y0 = fy;

    for(i = 0; i < vertices; i++){
        fscanf(fileTXT, " %d %d", &x1, &y1);

        picture = line2(picture, currentColor, x0, y0, x1, y1);

        x0 = x1;
        y0 = y1;
    }

    //Places the file pointer in the next line of the file
    fscanf(fileTXT, "\n"); 

    //Draws the last line
    picture = line2(picture, currentColor, x0, y0, fx, fy);

    return picture; 
}
