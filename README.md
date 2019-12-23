# Drawing Project
Final project of the course Introduction to Programming Techniques, taught by professor Gustavo Girão in the Bachelor of IT at the University of Rio Grande do Norte. 2019.2

## About
Our project is a <a href="http://netpbm.sourceforge.net/doc/ppm.html">PPM</a> image generator in C. It is possible to draw lines, curves, polygons, paint from instructions written in a txt file.
It is important to notice that our program works like a big matrix, i.e., the point (0.0) is in the left top corner; the bigger the first coordinate value, more to the right it will be and the bigger the second coordinate value, more to the bottom it will be.

## Types
 * **Pixel** Type used to create a pixel matrix to represent the PPM image and to store the current color that is set in the entire code. It consists of 3 *unsigned char* variables, one for each RGB value.

 * **Image** Type used to store the image as a matrix of Pixels and its width and height.
 
## Functionalities
### Painting functions
Inside the `painting.c` file are the functions related with the change of color of the pixels.

* **Clear** Cleans the image setting all its pixels to a specific color. It receives 3 integer values representing a RGB color.

   `clear <R_value> <G_value> <B_value>`

* **Set color** Receives 3 integer values representing a RGB color and set it as the current color that will be used in other functions.

   `color <R_value> <G_value> <B_value>`

* **Fill** Receives an initial point (xy pair) and from it, fills an area (with the current color defined in the previous function) until it finds a pixel with a different RGB color than the initial point or until it finds the edges of the image. <b>CAUTION: Don't use this function in big areas (bigger than 500 by 500 pixels), it can cause stack overflow.</b>

   `fill <incial_x> <inicial_y>`

### Shapes functions
Inside the `shapes.c` file are the functions related with the drawing of shapes and lines.

* **Line** This function draws a line from two points received (pair xy) by the user using the <a href="https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html">Bresenham's Algorithm</a>.

   `line <<inicial_x> <inicial_y> <final_x> <final_y>`

* **Circle** Draws a circle from its center (xy pair) and its radius using the <a href="https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/">Bresenham's Circle Algorithm</a>. 

   `circle <center_x> <center_y> <radius>`

* **Rectangle** Draws a rectangle from its left top vertex (xy pair) and it height and width. 

   `rect <left_top_vertex_x> <left_top_vertex_y> <height> <width>`
   
* **Polygon** Draws a polygon defined by a list of points. The first parameter is the number n of points followed by the n points (xy pair).

   `polygon <n_number_of_points> <point_1_x> <point_1_y> <point_2_x> <point_2_y> ... <point_n_x> <point_n_y>`

### Input and Output functions
The functions that aren't about manipulation of the image, but with its reading and creation of files are found inside the `IO.c` file.

* **Create image** Creates a new image matrix, with hight and width given by the user.

   `image <height> <width>`
   
* **Save image** Saves the image matrix as a PPM file in the program directory. It receives the name of the file followed by the extension *.ppm*.

   `save <name_of_the_image.ppm>`

## How to compile
On Linux, type in the terminal (in the program directory):
```
make
./ppm config.txt
```
*ppm* is the name of the executable file and *config.txt* is the name of the file that have the instructions for the construction of the image.

Example of a *config.txt* file:
```
image 600 400
clear 0 0 0
color 100 170 200
line 0 400 600 200
polygon 3 0 400 300 200 600 400
circle 200 100 50
color 180 30 50
fill 300 300
save test.ppm
```
Note: The *config.txt* file must have this 3 instructions: *image*, *clear* and *save*;

## Extras

* **Bézier curve** The function that draws quadratic Bézier curves receives 3 points (xy pair): the starting point, the inflexion point and the final point. It's mainly based on <a href="https://www.youtube.com/watch?v=mAi2-LTC2CA">linear interpolation</a>.
   
   Actually, there are two functions in this program that draws Bézier curves. The first one needs, as said before, 3 points given by the user:
  
   `curve <starting_x> <starting_y> <inflexion_x> <inflexion_y> <final_x> <final_y>`
  
   The second one is a "random curve generator". It receives the number of curves that it will produce and their starting point. The other 2 points will be random for each curve:
  
   `randcurve <number_of_curves> <starting_x> <starting_y>`

* **Regular Polygons** Draws a regular polygon from the number of its sides, its radius (of its circumscribed circle), rotation angle and its center. The rotation angle (counterclockwise) is given in degrees and converted to radian. It works dividing the circle in n equal angles and uses sine and cosine to find the vertexes of a regular polygon with n sides. In the end, it uses the line function to draw lines between the vertexes.

   `rpolygon <number_of_sides> <radius> <rotation> <central_x> <central_y>`

## What we would have done differently 

* **Fill function** As stated before, our fill function only works on small areas because of the stack overflow caused by the numerous calls of the recursive function. We would have liked to have implemented a data structure like *queue* using dynamic memory allocation instead of the recursive function but this subject is beyond the scope of our course and we didn't have enough time to study further. 

## Authors
* <a href="https://github.com/artursantiago">Artur Santiago</a>
* <a href="https://github.com/arturo32">Arturo Fonseca</a>

### What each one have done

* **Artur Santiago**
  * Modularization
  * Polygons
  * Circles
  * Rectangles
  * Documentation

* **Arturo Fonseca**
  * Regular polygons
  * Bézier curves
  * Lines
  * Fill
