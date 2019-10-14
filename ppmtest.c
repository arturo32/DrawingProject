   #include <stdio.h>
   #include <stdlib.h>
  
   #define MAGIC_NUMBER "P3" //PPM
   #define MAX_VALUE 255
   #define IMAGE_SIZE 1000

   int main(){

    int i, j, k, temp = 0;
  
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

    

    // Forming a white square inside a black square
    // Play here to form your own images!
    for (i = 0; i < IMAGE_SIZE; ++i){
      for (j = 0; j < IMAGE_SIZE; ++j){
      	for(k = 0; k < 3; k++){
        	if(i>250 && j >250 && i<750 && j <750 && k < 2){
          		image[i][j][k] = 255;
        	}
        	else{
         	 	image[i][j][k] = 0;
      		}
        }
      }
    }
    

    FILE* pgmimg; 

    //Creating a file ready to be written with a name of "myimg.pgm"
    pgmimg = fopen("myimg.ppm", "wb"); 
  
    // Writing Magic Number to the File 
    fprintf(pgmimg, "%s\n", MAGIC_NUMBER);  
  
    // Writing the size of the image 
    fprintf(pgmimg, "%d %d\n", IMAGE_SIZE, IMAGE_SIZE);  
  
    // Writing the maximum gray value 
    fprintf(pgmimg, "%d\n", MAX_VALUE);

    int count = 0; 
    for (i = 0; i < IMAGE_SIZE; i++) { 
        for (j = 0; j < IMAGE_SIZE; j++) {
        	for(k = 0; k < 3; k++){ 
 	           temp = image[i][j][k]; 
  
            	// Writing the colour values in the 3D array to the file 
            	fprintf(pgmimg, "%d ", temp); 
        	}
            free(image[i][j]);	
        } 
        free(image[i]);
        fprintf(pgmimg, "\n"); 
    }



    free(image);


    fclose(pgmimg);



    return 0; 
} 
