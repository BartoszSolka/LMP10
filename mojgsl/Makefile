libge: matrix.o solver.o
	ar rvs libge.a $^

matrix.o: matrix.c matrix.h
solver.o: solver.c solver.h
.PHONY: clean

clean:
	-rm *.o libge.a


