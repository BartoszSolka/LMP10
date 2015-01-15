#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include "matrix.h"
#include <gsl/gsl_matrix.h>
#include <stdlib.h>
#include <math.h>
void
pivot_ge_in_situ_matrix (matrix_t * c)
{
  int i, j, k;
  int cn = (int)c->mat->size1;
  int rn = (int)c->mat->size2;
  double *e = c->mat->data;
  for (k = 0; k < rn - 1; k++) {        /* eliminujemy (zerujemy) kolumnę nr k */
    int piv = k;                /* wybór elementu dominującego - maks. z k-tej kol., poniżej diag */
    for (i = k + 1; i < rn; i++)
      if (fabs (*(e + i * cn + k)) > fabs (*(e + piv * cn + k)))
        piv = i;
    if (piv != k) { 
	printf("%d",k);            /* jeśli diag. nie jest pivtem - wymień wiersze */
      xchg_rows (c, piv-1, k-2);
    }
    for (i = k + 1; i < rn; i++) {      /* pętla po kolejnych
                                           wierszach poniżej diagonalii k,k */
      double d = *(e + i * cn + k) / *(e + k * cn + k);
      for (j = k; j < cn; j++)
        *(e + i * cn + j) -= d * *(e + k * cn + j);
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



