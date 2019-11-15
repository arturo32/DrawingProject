#include "shapes.h"
#include "painting.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>


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

    /*"x != x1+sx" to x1 have the chance to be printed (and then added sx).
    The same goes for "y != y1+sy. Both of them are in a "and" expression
    to prevent cases like horizontal lines in which y never changes and 
    vertical lines in which x never changes*/ 
    }while(x != x1+sx && y != y1+sy);

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

Image circle(Image picture, Pixel* currentColor, FILE* fileTXT){

  int d,r,x,y,centerX,centerY;

  fscanf(fileTXT, " %d %d %d\n", &centerX, &centerY, &r);

  d=3-2*r;
  x=0;
  y=r;

  while(x<=y){
    picture = paintPointsInAllOctants(centerX, centerY, x, y, currentColor, picture);

    if(d<=0){
      d=d+4*x+6;
    }
    else{
      d=d+4*x-4*y+10;
      y--;
    }

    x++;
  }
  return picture;
}

Image rect(Image picture, Pixel* currentColor, FILE* fileTXT){

  int x0, y0, height, width, i;
  fscanf(fileTXT, " %d %d %d %d\n", &x0, &y0, &height, &width);
  
  picture = line2(picture, currentColor, x0 , y0, x0 + width, y0);
  picture = line2(picture, currentColor, x0 + width, y0, x0+width, y0 + height);
  picture = line2(picture, currentColor, x0 + width, y0 + height, x0, y0 + height);
  picture = line2(picture, currentColor, x0, y0 + height, x0, y0);
  
  return picture;
}

Image regPolygon(Image picture, FILE *fileTXT, Pixel currentColor){
 
  /*n is the number os sides os the polygon and s varies between 1 and n. 
  x and y are the center of the polygon*/
  int n, r, x, y, s, vx, vy, vx2, vy2;
  s = 1;

  fscanf(fileTXT, " %d %d %d %d\n", &n, &r, &x, &y);

  while(s != n){

    //"M_PI/2" rotates the polygon 90° to the left 
    vx = r*cos(2*M_PI*s/n - M_PI/2) + x;
    vy = r*sin(2*M_PI*s/n - M_PI/2) + y;
    s++;
    vx2 = r*cos(2*M_PI*s/n - M_PI/2) + x;
    vy2 = r*sin(2*M_PI*s/n - M_PI/2)+ y;
    line2(picture, &currentColor, vx, vy, vx2, vy2);
  }
 
  vx = r*cos(2*M_PI*1/n - M_PI/2) + x;
  vy = r*sin(2*M_PI*1/n - M_PI/2) + y;
  line2(picture, &currentColor, vx, vy, vx2, vy2);
  
  return picture;
}

Image curve(Image picture, FILE *fileTXT, Pixel currentColor){

  //r is the number of curves that will be coming from the point (x, y)
  int x, y, i, x2, y2, x3, y3;
  fscanf(fileTXT, " %d %d %d %d %d %d\n", &x, &y, &x2, &y2, &x3, &y3);
  int finalx, finaly;
  double t = 0.0001;

  //Calculating the points of the Bèzier quadratic curve
  do{
    finalx = powf(1-t, 2)*x + (1-t)*2*t*x2 + t*t*x3;
    finaly = powf(1-t, 2)*y + (1-t)*2*t*y2 + t*t*y3;
    for(int k = 0; k < 3; k++)
      picture.pixels[finaly][finalx] = currentColor;
    t = t + 0.0001;
  }while(finalx != x3);

  return picture;
}

Image randCurve(Image picture, FILE *fileTXT, Pixel currentColor){

  //r is the number of curves that will be coming from the point (x, y)
  int r, x, y, i, x2, y2, x3, y3;
  fscanf(fileTXT, " %d %d %d\n", &r, &x, &y);
  int finalx, finaly;

  /*Setting random values to the coordinates of the Bèzier quadratic curve
  and calculating your points one by one*/
  for(i = 0; i < r; i++){
    double t = 0.0001;
    x2 = rand()%picture.width; 
    y2 = rand()%picture.height; 
    x3 = rand()%picture.width; 
    y3 = rand()%picture.height; 

    do{
      finalx = powf(1-t, 2)*x + (1-t)*2*t*x2 + t*t*x3;
      finaly = powf(1-t, 2)*y + (1-t)*2*t*y2 + t*t*y3;
      for(int k = 0; k < 3; k++)
        picture.pixels[finaly][finalx] = currentColor;
      t = t + 0.0001;
    }while(finalx != x3);
  }

  return picture;
}
