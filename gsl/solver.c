#include <stdio.h>
#include "gsl/gsl_linalg.h"
#include "matrix.h"
#include "solver.h"
#include "gsl/gsl_matrix.h"


void
pivot_ge_in_situ_matrix (matrix_t * c)
{
  int i, j, k;
  int cn = (int)c->mat->size1;
  int rn = (int)c->mat->size2
  double *e = c->mat;
  for (k = 0; k < rn - 1; k++) {        /* eliminujemy (zerujemy) kolumnę nr k */
    int piv = k;                /* wybór elementu dominującego - maks. z k-tej kol., poniżej diag */
    for (i = k + 1; i < rn; i++)
      if (fabs (*(e + i * cn + k)) > fabs (*(e + piv * cn + k)))
        piv = i;
    if (piv != k) {             /* jeśli diag. nie jest pivtem - wymień wiersze */
      xchg_rows (c, piv, k);
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
    pivot_ge_in_situ_matrix (eqs->mat);
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



matrix_t solve(matrix_t
 gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, 3, 3);

  gsl_vector_view b
    = gsl_vector_view_array (b_data, 3); 

  gsl_permutation * p = gsl_permutation_alloc (3);

  gsl_linalg_LU_decomp (&m.matrix, p, &s);

  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);


  gsl_permutation_free (p);
  gsl_vector_free (x);
  return 0;
}

