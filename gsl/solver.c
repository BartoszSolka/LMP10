#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include "matrix.h"

int
main (void)
{

 

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

