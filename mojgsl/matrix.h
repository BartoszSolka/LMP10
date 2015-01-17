#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_cblas.h>
#include <gsl/gsl_matrix.h>
typedef struct {
	gsl_matrix *mat;
} matrix_t;

matrix_t * make_matrix (int rn, int cn );

matrix_t * read_matrix( FILE *in );

void write_matrix( matrix_t *, FILE *out );

void put_entry_matrix( matrix_t *, int i, int j, double val );

void add_to_entry_matrix( matrix_t *, int i, int j, double val );

double get_entry_matrix( matrix_t *, int i, int j );

matrix_t * copy_matrix( matrix_t *s );

matrix_t * transpose_matrix( matrix_t * s );

void xchg_rows( matrix_t *m, int i, int j );

void xchg_cols( matrix_t *m, int i, int j );

matrix_t * mull_matrix( matrix_t *, matrix_t * );

matrix_t * ge_matrix( matrix_t * );

int bs_matrix( matrix_t * );

#endif
