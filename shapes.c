#include "shapes.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

//rect(){}
//circle(){}
//polygon(){}
Image line(Image picture, FILE* fileTXT, Pixel* current_color){

    int dx, dy, sx, sy, err, e2;
    Line line;
    fscanf(fileTXT, "%d %d %d %d\n", &line.x0, &line.y0, &line.x1, &line.y1);
    
    /*Calculating the differences between the x's and y's
    (they will tell the slope of the line) and checking if the line
    is going from the left to the right (add 1 to x0) or from the right to
    the left (add -1 to x0) and if it is going from the top to the bottom
    (add 1 to y0) or from the bottom to the top (add -1 to y0). All of this
    is to find the octant that the line is placed to follow the Bresenham's
    Algorithm*/
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

    //If the slope is less than 1
    if(dx > dy){   
        err = dx/2;
    }
    //If the slope is greater than 1
    else{
        err = -dy/2;
    }

    do{
    /*Setting each pixel to the current color. y and x are switched because
    in matrixes the rows comes before the collumns*/
    picture.pixels[line.y0][line.x0] = *current_color;

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

Image polygon(Image picture, FILE *fileTXT, Pixel *current_color){
    
    Polygon poly;
    Line line;
    int x, y, cont = 0;

    fscanf(fileTXT, " %d %d %d", &poly.qtdLinhas, &poly.x0, &poly.y0);
    line.x0 = poly.x0;
    line.y0 = poly.y0;

    do{
        fscanf(fileTXT, " %d %d", &x, &y);
        line.x1 = x;
        line.y1 = y;

        picture = line_after_read(picture, line, current_color);

        line.x0 = x;
        line.y0 = y;
        
        cont++;

        if (cont == poly.qtdLinhas - 1){
            fscanf(fileTXT, "\n"); //Colocar o ponteiro na próxima linha
        }  
    } while (cont < poly.qtdLinhas - 1);

    line.x1 = poly.x0;
    line.y1 = poly.y0;

    picture = line_after_read(picture, line, current_color);

    return picture; 
}

Image line_after_read(Image picture, Line line, Pixel *current_color){
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
    picture.pixels[line.y0][line.x0] = *current_color;

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
