#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include "solver.h"
#include "matrix.h"
#include <gsl/gsl_matrix.h>
#include <stdlib.h>
#include <math.h>
void
pivot_ge_in_situ_matrix (matrix_t * c)
{
  size_t i, j, k;
  double *x, *y,*z,*f,*a;
  size_t cn = c->mat->size2;
  size_t rn = c->mat->size1;
  double d;
  for (k = 0; k < rn-1; k++) {        /* eliminujemy (zerujemy) kolumnę nr k */
	size_t piv = k;
	for (i = k + 1; i < rn; i++){
	x=gsl_matrix_ptr(c->mat,i,k);
	y=gsl_matrix_ptr(c->mat,piv,k);
	if (fabs(*(x)) > fabs(*(y)))
        piv = i;}
    if (piv != k) {             /* jeśli diag. nie jest pivtem - wymień wiersze */
      xchg_rows (c, piv, k);
    }
    for (i = k + 1; i < rn; i++) {   
      
	x=gsl_matrix_ptr(c->mat,i,k);
        f=gsl_matrix_ptr(c->mat,k,k);
      d = *(x) / *(f);
      for (j = k; j < cn; j++){
        z=gsl_matrix_ptr(c->mat,i,j);
	a=gsl_matrix_ptr(c->mat,k,j);  
	*z-=d* *(a);
      }
    }
  }
}




int
piv_ge_solver (matrix_t * eqs)
{
  if (eqs != NULL) {
    pivot_ge_in_situ_matrix (eqs);
    if (bs_matrix (eqs) == 0) {
	return 0;
    }
    else {
      return 1;
    }
  }
  else
    return 1;
}

	

