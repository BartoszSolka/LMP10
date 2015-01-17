#ifndef SOLVER_H
#define SOLVER_H


#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include "matrix.h"
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_cblas.h>
#include <math.h>


void
pivot_ge_in_situ_matrix (matrix_t * c);

int
piv_ge_solver (matrix_t * eqs);

#endif
