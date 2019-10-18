all: main

main: painting shapes general MAIN.c
	gcc MAIN.c painting.o shapes.o general.o -o ppm

painting: painting.c
	gcc -c painting.c

shapes: shapes.c
	gcc -c shapes.c

general: general.c
	gcc -c general.c

clean:
	rm -f *.o

