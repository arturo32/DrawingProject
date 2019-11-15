#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "shapes.h"
#include "IO.h"
#include "painting.h"
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]){
 
  /*Pointer to the name of the txt file informed in execution and passed as
  an argument in the main function*/
  char const *fileNameTXT = argv[1];

  //The string that will store the first word of a command in the txt file
  char functionName[10]; 

  //Variable that will store the image in a matrix 
  Image picture;

  //The color that is set in the moment
  Pixel currentColor; 

  //File pointer for the txt file
  FILE *fileTXT; 

  //Opening the txt file for reading
  fileTXT = fopen(fileNameTXT, "r");
  if(fileTXT == NULL){
    printf("Error in opening the txt file.\n");
    exit(EXIT_FAILURE);
  }
 
  /*Setting the "seed" of the rand function to be the current time. This will 
  be useful in the randCurve function*/
  srand(time(NULL)); 
  
  /*Reading the first word of a command and calling its corresponding function
  until the file ends (EOF)*/
  while(fscanf(fileTXT, "%s", functionName) != EOF){
    if (strcmp(functionName, "image") == 0){
      picture = newImage(fileTXT);
    }
    else if (strcmp(functionName, "clear") == 0){
      picture = clear(picture, fileTXT, &currentColor);
    }
    else if (strcmp(functionName, "color") == 0){
      currentColor = color(fileTXT, currentColor);
    }
    else if (strcmp(functionName, "line") == 0){
      picture = line(picture, &currentColor, fileTXT);
    }
    else if (strcmp(functionName, "polygon") == 0){
      picture = polygon(picture, fileTXT, &currentColor);
    }
    else if(strcmp(functionName, "rpolygon") == 0){
      picture = regPolygon(picture, fileTXT, currentColor);
    }   
    else if (strcmp(functionName, "circle") == 0){
      picture = circle(picture, &currentColor, fileTXT);
    }
    else if (strcmp(functionName, "rect") == 0){
      picture = rect(picture, &currentColor, fileTXT);
    }
    else if (strcmp(functionName, "fill") == 0){
      picture = fill(picture, fileTXT, &currentColor);
    }
    else if(strcmp(functionName, "curve") == 0){
      picture = curve(picture, fileTXT, currentColor);
    }
    else if(strcmp(functionName, "randcurve") == 0){
      picture = randCurve(picture, fileTXT, currentColor);
    }    
    else if (strcmp(functionName, "save") == 0){
      save(picture, fileTXT);
    }
  }
  
  //Closing the txt file
  fclose(fileTXT);

  return 0; 
} 
