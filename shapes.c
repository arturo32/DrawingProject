#include "shapes.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

//rect(){}
//circle(){}
//polygon(){}
Image line(Image picture, FILE *fileTXT, Pixel *current_color){
    Line line;
    fscanf(fileTXT, " %d %d %d %d\n", &line.x0, &line.y0, &line.x1, &line.y1);

    int dx, dy, sx, sy, err, e2;
    
    dx = abs(line.x1 - line.x0);
    if(line.x0 < line.x1){
        sx = 1;
    }
    else{
        sx = -1;
    }

    dy = abs(line.y1 - line.y0);
    if (line.y0 < line.y1){
        sy = 1;
    }
    else{
        sy = -1;
    }

    //Essa parte do "err" e do "e2" eu n entendi ainda
    if(dx > dy){   //Ou seja, menor que 1
        err = dx/2;
    }
    else{
        err = -dy/2;
    }


    do{
    picture.pixels[line.x0][line.y0] = *current_color;

    e2 = err;

    if(e2 > -dx){
      err -= dy;
      line.x0 += sx;
    }
    if(e2 < dy){
      err += dx; 
      line.y0 += sy;
    }

    }while(line.x0 != line.x1 || line.y0 != line.y1);

    return picture;
}
