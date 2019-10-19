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
    
    Image picture = newImage(size_x, size_y);      

    FILE* ppmimg; 

    //Creating a file ready to be written with a name of "myimg.ppm"
    ppmimg = fopen("myimg.ppm", "w"); 
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
          fprintf(ppmimg, "%d %d %d ", picture.pixels[i][j].R, picture.pixels[i][j].G, picture.pixels[i][j].B); 
        } 
        free(picture.pixels[i]);
        fprintf(ppmimg, "\n"); 
    }
    
    free(picture.pixels);
    
    fclose(ppmimg);

    return 0; 
} 
