libge: matrix.o solver.o
	ar rvs libge.a $^ 

matrix.o: matrix.c matrix.h
	$(CC) -L/usr/local/lib -c matrix.c -lgsl -lgslcblas -lm
solver.o: solver.c solver.h matrix.h
	$(CC) -L/usr/local/lib -c solver.c -lgsl -lgslcblas -lm
.PHONY: clean

clean:
	-rm *.o libge.a

