aprox: main.o splines.o points.o aproksymator_na_bazie.o gsl/libge.a gsl/solver.h
	$(CC) -o  aprox -ggdb  main.o splines.o points.o aproksymator_na_bazie.o gsl/matrix.c gsl/solver.c -lgsl  -Lgsl_linalg.h -Lgsl_matrix.h -lgslcblas

intrp: main.o splines.o points.o interpolator.o gsl/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -lgsl -Lgsl_linalg.h -Lgsl_matrix.h -lgslcblas

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h gsl/solver.h gsl/matrix.h
	$(CC) -c aproksymator_na_bazie.c gsl/matrix.c gsl/solver.c

interpolator.o: makespl.h points.h gsl/solver.h
	$(CC) -c interpolator.c -lgsl -Lgsl_linalg.h -Lgsl_matrix.h

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
