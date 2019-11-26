all: main

main: painting shapes IO MAIN.c
	gcc MAIN.c painting.o shapes.o IO.o -o ppm -lm

painting: painting.c
	gcc -c painting.c

shapes: shapes.c
	gcc -c shapes.c

IO: IO.c
	gcc -c IO.c

clean:
	rm -f *.o

