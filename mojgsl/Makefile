libge: matrix.o solver.o
	ar rvs libge.a $^
matrix.o: matrix.c matrix.h
	$(CC) -o matrix.o -c matrix.c -lm -lgsl -Lgsl_linalg.h -lgslcblas
solver.o: solver.c solver.h matrix.h
	$(CC) -o solver.o -c solver.c -lm -lgsl -Lgsl_linalg.h -lgslcblas 
.PHONY: clean

clean:
	-rm *.o libge.a


