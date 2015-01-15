#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_cblas.h>
matrix_t * make_matrix (int rn, int cn){
	matrix_t *matrix = malloc(sizeof(*matrix));
	matrix->mat = gsl_matrix_alloc(rn, cn);
	return matrix;
}

void
free_matrix (matrix_t * m)
{
  gsl_matrix_free(m->mat);
  free(m);
}

void
put_entry_matrix (matrix_t * m, int i, int j, double val)
{
	gsl_matrix_set(m->mat,i,j,val);
}

void
add_to_entry_matrix (matrix_t * m, int i, int j, double val)
{
	double x=0;
	x=gsl_matrix_get(m->mat,i,j);
	x+=val;
	gsl_matrix_set(m->mat,i,j,x);

}

double
get_entry_matrix (matrix_t * m, int i, int j )
{
	return gsl_matrix_get(m->mat,i,j);
}

matrix_t *
read_matrix (FILE * in)
{
  int rn, cn;
  int i, j;
  double x;
  matrix_t *new_mat;
  if (fscanf (in, "%d %d", &rn, &cn) != 2)
    return NULL;

  if ((new_mat = make_matrix (rn, cn)) == NULL)
    return NULL;
  for (i = 0; i < rn; i++)
    for (j = 0; j < cn; j++)
      if (fscanf (in, "%lf", &x) != 1) {
        free_matrix (new_mat);
        return NULL;
      }
      else{
	gsl_matrix_set(new_mat->mat,rn,cn,x);
      }

  return new_mat;
}

void
write_matrix (matrix_t * m, FILE * out)
{
	gsl_matrix_fprintf(out,m->mat,"%f");
}

matrix_t 
*copy_matrix (matrix_t * s)
{
	matrix_t *new_matrix;
	gsl_matrix_set_zero(new_matrix->mat);
	gsl_matrix_memcpy(new_matrix->mat,s->mat);
	return new_matrix;
}

matrix_t *
transpose_matrix (matrix_t * s)
{
  matrix_t *d = NULL;
  if (s != NULL)
    d = make_matrix((int)s->mat->size1, (int)s->mat->size2);
  gsl_matrix_memcpy(d->mat,s->mat);
  gsl_matrix_transpose(d->mat);
  return d;
}

void
xchg_rows (matrix_t * m, int i, int j)
{
	gsl_matrix_swap_rows(m->mat,i,j);
}

void
xchg_cols (matrix_t * m, int i, int j)
{
	gsl_matrix_swap_columns(m->mat,i,j);
}

matrix_t *
mull_matrix (matrix_t * a, matrix_t * b)
{
  if (a == NULL || b == NULL || a->mat->size1 != b->mat->size2)
    return NULL;
  else {
    matrix_t *c = make_matrix ((int)a->mat->size1, (int)b->mat->size2);
    gsl_matrix_mul_elements(c->mat,b->mat);
  return c;
  }
}

matrix_t *
ge_matrix (matrix_t * a)
{
  matrix_t *c = copy_matrix (a);
  if (c != NULL) {
    int i, j, k;
    int cn = (int)c->mat->size1;
    int rn = (int)c->mat->size2;
    double *e = c->mat;
    for (k = 0; k < rn - 1; k++) {      /* eliminujemy (zerujemy) kolumnę nr k */
      for (i = k + 1; i < rn; i++) {    /* pętla po kolejnych
                                           wierszach poniżej diagonalii k,k */
        double d = *(e + i * cn + k) / *(e + k * cn + k);
        for (j = k; j < cn; j++)
          *(e + i * cn + j) -= d * *(e + k * cn + j);
      }
    }
  }
  return c;
}

int
bs_matrix (matrix_t * a)
{
  if (a != NULL) {
    int r, c, k;
    int cn = (int)a->mat->size1;
    int rn = (int)a->mat->size2;
    double *e = a->mat;

    for (k = rn; k < cn; k++) { /* pętla po prawych stronach */
      for (r = rn - 1; r >= 0; r--) {   /* petla po niewiadomych */
        double rhs = *(e + r * cn + k); /* wartość prawej strony */
        for (c = rn - 1; c > r; c--)    /* odejmujemy wartości już wyznaczonych niewiadomych *
                                           pomnożone przed odpowiednie współczynniki */
          rhs -= *(e + r * cn + c) * *(e + c * cn + k);
        *(e + r * cn + k) = rhs / *(e + r * cn + r);    /* nowa wartość to prawa strona / el. diagonalny */
      }
    }
    return 0;
  }
  else
    return 1;
}

