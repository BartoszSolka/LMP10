#include <stdlib.h>
#include "matrix.h"
#include <gsl/gsl_matrix.h>


matrix_t trans_to_gsl(matrix_t * norm){

	int rn;
	int cn;
	int j=1;
	int i=cn+1;
	int k=1;
	rn=norm->rn;
	cn=norm->cn;

	gsl_matrix * m = gsl_matrix * gsl_matrix_alloc (rn, cn);
	gsl_vector * v = gsl_vetor_alloc (rn); 

		for(k;k<rn;k++)
	          for(j=1;j<cn;j++){
		    gsl_matrix_set(m,k,j,norm->e[k*j]);
		  }

		for(j=1;j<rn;j++)
		  gsl_vector_set(v,j,norm->e[i*j]);
	
	
}


matrix_t trans_to_norm(matrix_t gsl){
	



}
