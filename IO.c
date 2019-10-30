#include "IO.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAGIC_NUMBER "P3" //PPM
#define MAX_VALUE 255


Image newImage(FILE *fileTXT){
	
	int i, j, height, width;
    Pixel pixel; //Pixel que será passado como parâmetro para a função clear
    Image picture; //Imagem que será criada e manipulada

    fscanf(fileTXT," %d %d\n",  &width, &height);

	picture.height = height;
	picture.width = width;
    
    picture.pixels = (Pixel**)(malloc(height * sizeof(Pixel*)));
    if(picture.pixels == NULL){
    	printf("Error in creating matrix\n");
    	exit(EXIT_FAILURE);
    }

    for(i = 0; i < height; i++){
    	picture.pixels[i] = (Pixel*)(malloc(width * sizeof(Pixel)));
    	if(picture.pixels[i] == NULL){
			printf("Error in creating matrix\n");
            //stops the entire program
    		exit(EXIT_FAILURE);
    	}
    }
   
    return picture;

}


void save(Image picture, FILE *fileTXT){ 

    FILE* ppmimg; 
    int i, j;
    char imageName[10]; //Rever tamanho da variavel
    
    fscanf(fileTXT, " %s\n", imageName); //Ler a função save e o nome da imagem ppm

    //Creating a file ready to be written with a name of "myimg.ppm"
    ppmimg = fopen(imageName, "w"); 
    if(ppmimg == NULL){
       printf("Error in creating ppm file.\n");
       exit(EXIT_FAILURE);
    }
  
    // Writing Magic Number to the File 
    fprintf(ppmimg, "%s\n", MAGIC_NUMBER);  
  
    // Writing the size of the image 
    fprintf(ppmimg, "%d %d\n", picture.width, picture.height); //width and then height  
  
    // Writing the maximum RGB value 
    fprintf(ppmimg, "%d\n", MAX_VALUE);

    for (i = 0; i < picture.height; i++) { 
        for (j = 0; j < picture.width; j++) {
          // Writing the colour values in the 3D array to the file 
          fprintf(ppmimg, "%d %d %d ", picture.pixels[i][j].R, picture.pixels[i][j].G, picture.pixels[i][j].B); 
        } 
        free(picture.pixels[i]);
        fprintf(ppmimg, "\n"); 
    }
    
    free(picture.pixels);
    
    fclose(ppmimg);
}


Pixel color(FILE *fileTXT, Pixel currentColor){

    fscanf(fileTXT, " %hhu %hhu %hhu\n", &currentColor.R, &currentColor.G, &currentColor.B);

    return currentColor;
}
