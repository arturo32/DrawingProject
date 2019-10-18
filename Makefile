all: main

main: painting shapes general ppmtest.c
	gcc ppmtest.c painting.o shapes.o general.o -o exec

painting: painting.c
	gcc -c painting.c

shapes: shapes.c
	gcc -c shapes.c

general: general.c
	gcc -c general.c

clean:
	rm -f *.o

