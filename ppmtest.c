   #include <stdio.h>
   #include <stdlib.h>
   #include "tipos.h"
   #include "shapes.h"
   #include "general.h"
   #include "painting.h"
  
   #define MAGIC_NUMBER "P3" //PPM
   #define MAX_VALUE 255

   int main(){

    int i, j, k, size_x, size_y, temp = 0;

    //Isso abaixo será parte de uma função dentro de uma biblioteca
    printf("Quantos pixels na vertical e horizontal você deseja na sua imagem? (separe os dois valores por espaço)\n");
    scanf("%d %d" , &size_x, &size_y);

    //Declarando uma matriz do tipo Pixel para armazenar imagens ppm
    Pixel **image;
    
    image = (Pixel**)(malloc(size_x * sizeof(Pixel*)));
    if(image == NULL){
    	printf("Erro na inicialização de image.\n");
    	return 1;
    }

    for(i = 0; i < size_x; i++){
    	image[i] = (Pixel*)(malloc(size_y * sizeof(Pixel)));
    	if(image[i] == NULL){
    		printf("Erro na inicialização de image[%d].\n", i);
    		return 1;
    	}
   	}
    //Forming a yellow rectangle inside a black square
    for (i = 0; i < size_x; ++i){
      for (j = 0; j < size_y; ++j){
        Pixel p;
        if(i > (size_x/4) && j > (size_y/4) && i < (size_x * 3/4) && j < (size_y * 3/4)){
          p.R = 255;
          p.G = 255;
          p.B = 0;
        }
        else{
          p.R = 0;
          p.G = 0;
          p.B = 0;
        }
        image[i][j] = p;
      }
    }
    

    FILE* ppmimg; 

    //Creating a file ready to be written with a name of "myimg.ppm"
    ppmimg = fopen("myimg.ppm", "wb"); 
    if(ppmimg == NULL){
       printf("ERORRR\n");
       return 1;
    }
  
    // Writing Magic Number to the File 
    fprintf(ppmimg, "%s\n", MAGIC_NUMBER);  
  
    // Writing the size of the image 
    fprintf(ppmimg, "%d %d\n", size_x, size_y);  
  
    // Writing the maximum RGB value 
    fprintf(ppmimg, "%d\n", MAX_VALUE);

    for (i = 0; i < size_x; i++) { 
        for (j = 0; j < size_y; j++) {

          // Writing the colour values in the 3D array to the file 
          fprintf(ppmimg, "%d %d %d ", image[i][j].R, image[i][j].G, image[i][j].B); 
        } 
        free(image[i]);
        fprintf(ppmimg, "\n"); 
    }
    
    free(image);
    
    fclose(ppmimg);

    return 0; 
} 
