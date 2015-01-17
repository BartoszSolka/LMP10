aprox: main.o splines.o points.o aproksymator_na_bazie.o mojgsl/libge.a
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L mojgsl -l ge -lgsl -lgslcblas
 
intrp: main.o splines.o points.o interpolator.o mojgsl/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L mojgsl
 
prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o
 
aproksymator_na_bazie.o: makespl.h points.h mojgsl/solver.c mojgsl/matrix.c
	$(CC) -I mojgsl -c aproksymator_na_bazie.c
 
interpolator.o: makespl.h points.h mojgsl/solver.h mojgsl/matrix.h
	$(CC) -I mojgsl -c interpolator.c
 
.PHONY: clean
 
clean:
	-rm *.o aprox intrp prosta
