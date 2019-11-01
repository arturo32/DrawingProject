#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "shapes.h"
#include "IO.h"
#include "painting.h"
#include <string.h>

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
    else if (strcmp(functionName, "save") == 0){
      save(picture, fileTXT);
    }
  }
  
  //Closing the txt file
  fclose(fileTXT);

  return 0; 
} 
