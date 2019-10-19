all: main

main: painting shapes IO types MAIN.c
	gcc MAIN.c painting.o shapes.o IO.o types.o -o ppm

painting: painting.c
	gcc -c painting.c

shapes: shapes.c
	gcc -c shapes.c

IO: general.c
	gcc -c general.c
	
types: types.c
	gcc -c types.c

clean:
	rm -f *.o

