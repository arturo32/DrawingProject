#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "shapes.h"
#include "IO.h"
#include "painting.h"
#include <string.h>
  
int main(int argc, char const *argv[]){
 
  int count=0, height, weight;
  char const *fileNameTXT; //Nome do arquivo txt que será aberto
  char function[10], imageName[10]; //Rever o tamanho das variaveis
  FILE *fileTXT; //Ponteiro para o arquivo txt
  Image picture; //Imagem que será criada e manipulada
  Pixel pixel; //Pixel que será passado como parâmetro para a função clear

  fileNameTXT = argv[1];

  fileTXT = fopen(fileNameTXT, "r");
  if(fileTXT == NULL){
    printf("ERORRR\n");
    exit(EXIT_FAILURE);
  }
  
  //Testar esse while usando o fgets
  /*
  while (cont < 3){
    
  } */
  
  
  //A leitura do arquivo está errada
  //Pesquisando sobre funções de leitura
  fscanf(fileTXT,"%s %d %d", function, &weight, &height);
  picture = newImage(weight, height); //Creating the image

  fscanf(fileTXT, "%s %c %c %c", function, &pixel.R, &pixel.G, &pixel.B);
  picture = clear(picture, pixel); //Clear the image and set all pixels with a specific pixel

  fscanf(fileTXT, "%s %s", function, imageName); //Ler a função save e o nome da imagem ppm
  save(picture, imageName); //Saving the image

    
  fclose(fileTXT);

  return 0; 
} 
