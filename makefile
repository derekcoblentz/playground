
a.out: babysteps.o
	gcc -L/usr/local/lib babysteps.o -lgsl -lgslcblas -lm
	rm babysteps.o
matrix.o: babysteps.c
	gcc -Wall -I/usr/local/include -c babysteps.c

.PHONY: clean

clean:
	rm babysteps.o a.out
