aprox: main.o splines.o points.o aproksymator_na_bazie.o mojgsl/libge.a
	$(CC) -o aprox  -ggdb main.o splines.o points.o aproksymator_na_bazie.o mojgsl/matrix.o mojgsl/solver.o -lgsl -Lgsl_linalg.h -Lgsl_matrix.c -lgslcblas

intrp: main.o splines.o points.o interpolator.o mojgsl/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L mojgsl

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h mojgsl/solver.h mojgsl/matrix.h
	$(CC) -I mojgsl -c aproksymator_na_bazie.c mojgsl/matrix.c mojgsl/matrix.h -L mojgsl

interpolator.o: makespl.h points.h mojgsl/solver.h
	$(CC) -I mojgsl -c interpolator.c

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
