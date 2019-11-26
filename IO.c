#include "IO.h"
#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAGIC_NUMBER "P3"
#define MAX_VALUE 255


Image newImage(FILE *fileTXT){
	
	int i, height, width;
    Image picture; 

    fscanf(fileTXT," %d %d\n",  &width, &height);

	picture.height = height;
	picture.width = width;
    
    //Dynamicly allocating the matrix of Pixels
    picture.pixels = (Pixel**)(malloc(height * sizeof(Pixel*)));
    if(picture.pixels == NULL){
    	printf("Error in creating matrix\n");
        //Stops the entire program
    	exit(EXIT_FAILURE);
    }

    for(i = 0; i < height; i++){
    	picture.pixels[i] = (Pixel*)(malloc(width * sizeof(Pixel)));
    	if(picture.pixels[i] == NULL){
			printf("Error in creating matrix\n");
            //Stops the entire program
    		exit(EXIT_FAILURE);
    	}
    }
   
    return picture;
}


void save(Image picture, FILE *fileTXT){ 

    FILE* ppmimg; 
    int i, j;
    char imageName[50];
    
    //Reading the string that will be the name of the ppm file
    fscanf(fileTXT, " %s\n", imageName); 

    //Creating the ppm file while it is opening for writing
    ppmimg = fopen(imageName, "w"); 
    if(ppmimg == NULL){
       printf("Error in creating ppm file.\n");
       exit(EXIT_FAILURE);
    }
  
    //Writing Magic Number to the file 
    fprintf(ppmimg, "%s\n", MAGIC_NUMBER);  
  
    //Writing the size of the image 
    fprintf(ppmimg, "%d %d\n", picture.width, picture.height); 
  
    //Writing the maximum RGB value 
    fprintf(ppmimg, "%d\n", MAX_VALUE);

    /*Writing the colour values in the matrix to the file while "freeing" the 
    memory stored in the dynamic allocation*/
    for (i = 0; i < picture.height; i++){ 
        for (j = 0; j < picture.width; j++){
          fprintf(ppmimg, "%d %d %d ", picture.pixels[i][j].R, picture.pixels[i][j].G, picture.pixels[i][j].B); 
        } 
        free(picture.pixels[i]);
        fprintf(ppmimg, "\n"); 
    }
    
    free(picture.pixels);
    
    fclose(ppmimg);
}



