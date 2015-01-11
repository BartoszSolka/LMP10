matrix.o: matrix.c matrix.h
solver.o: solver.c
.PHONY: clean

clean:
	-rm *.o libge.a


	gcc solver.o matrix.o -l/usr/include/gsl/gsl_linalg.h -l/usr/include/gsl/gsl_matrix.h


