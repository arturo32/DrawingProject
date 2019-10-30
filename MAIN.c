#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "shapes.h"
#include "IO.h"
#include "painting.h"
#include <string.h>

int main(int argc, char const *argv[]){
 
  int count=0, height, width;
  char const *fileNameTXT; //Nome do arquivo txt que será aberto
  char functionName[10];  //Rever o tamanho das variaveis
  Image picture;
  Pixel currentColor; //Cor que está sendo usada
  FILE *fileTXT;  //Ponteiro para o arquivo txt
 

  fileNameTXT = argv[1];

  fileTXT = fopen(fileNameTXT, "r");
  if(fileTXT == NULL){
    printf("Error in opening the txt file.\n");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fileTXT, "%s", functionName) != EOF){
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
  
  fclose(fileTXT);

  return 0; 
} 
