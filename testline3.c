#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAGIC_NUMBER "P3" //PPM
#define MAX_VALUE 255
#define IMAGE_SIZE 1000

void line(int x0, int y0, int x1, int y1, int*** image) {
  int dx = abs(x1-x0);
  int dy = abs(y1-y0);
  if(dy > dx){
    int temp = x0;
    x0 = y0;
    y0 = temp;

    temp = x1;
    x1 = y1;
    y1 = temp;

  }

  int p = 2*dy-dx;
  printf("%d\n", p);
 
  do{
    if(dy > dx){
      for(int i = 0; i < 3; i++)
        image[x0][y0][i] = 0;
    }
    else{
      for(int i = 0; i < 3; i++)
        image[y0][x0][i] = 0;
    }

    x0++;
    if(p < 0){
      p += 2*dy;
    }
    else{
      p += 2*dy-2*dx;
      y0++;
    }

  }while(x0 < x1);
}

int main(){

  int i, j, k, temp = 0;
  
  //42
  
  // Suppose the 3D Array to be converted to Image is as given below 
  //É MELHOR CRIAR UMA STRUCT PARA ARMAZENAR CADA PIXEL (3 VALORES)!

  int ***image;
  
  image = (int***)(malloc(sizeof(int**)*IMAGE_SIZE));
  if(image == NULL){
  	printf("EEEROO\n");
  	return 1;
  }

  for(i = 0; i < IMAGE_SIZE; i++){
  	image[i] = (int**)(malloc(sizeof(int*)*IMAGE_SIZE));
  	if(image[i] == NULL){
  		printf("EERROR\n");
  		return 1;
  	}
  	for(j = 0; j < IMAGE_SIZE; j++){
  		image[i][j] = (int*)(malloc(sizeof(int)*3));
  		if(image[i][j] == NULL){
  			printf("errorrr\n");
  			return 1;
  		}
  	}
 	}

  int xp1 = 50;
  int yp1 = 50;
  int xp2 = 400;
  int yp2 = 100;

  for (i = 0; i < IMAGE_SIZE; ++i){
    for (j = 0; j < IMAGE_SIZE; ++j){
    	for(k = 0; k < 3; k++){
        		image[i][j][k] = 255;
       	       	
      }
    }
  }
  line(100, 100, 800, 200, image);
 


  

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
  fprintf(ppmimg, "%d %d\n", IMAGE_SIZE, IMAGE_SIZE);  

  // Writing the maximum gray value 
  fprintf(ppmimg, "%d\n", MAX_VALUE);

  int count = 0; 
  for (i = 0; i < IMAGE_SIZE; i++) { 
      for (j = 0; j < IMAGE_SIZE; j++) {
      	for(k = 0; k < 3; k++){ 
	           temp = image[i][j][k]; 

          	// Writing the colour values in the 3D array to the file 
          	fprintf(ppmimg, "%d ", temp); 
      	}
          free(image[i][j]);	
      } 
      free(image[i]);
      fprintf(ppmimg, "\n"); 
  }



  free(image);


  fclose(ppmimg);



  return 0; 
} 