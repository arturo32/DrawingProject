   #include <stdio.h>
   #include <stdlib.h>
   #include "types.h"
   #include "shapes.h"
   #include "IO.h"
   #include "painting.h"
  
   #define MAGIC_NUMBER "P3" //PPM
   #define MAX_VALUE 255

   int main(int argc, char const *argv[]){
 
    int i, j, k, size_x, size_y, temp = 0;

    

    //ANALISAR DEPOIS
    printf("parametros: %d\n", argc);
    for(i=0;i<argc;i++)
      printf("%s\n", argv[i]);

    

    //Isso abaixo será parte de uma função dentro de uma biblioteca
    scanf("%d %d" , &size_x, &size_y);
    
    Image picture;  
    picture.image = newImage(size_x, size_y);
    if(picture.image == NULL){
    	return 1;
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
          fprintf(ppmimg, "%d %d %d ", picture.image[i][j].R, picture.image[i][j].G, picture.image[i][j].B); 
        } 
        free(picture.image[i]);
        fprintf(ppmimg, "\n"); 
    }
    
    free(picture.image);
    
    fclose(ppmimg);

    return 0; 
} 
