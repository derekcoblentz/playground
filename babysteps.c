
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <math.h>

int main(){
	gsl_matrix *matrix = gsl_matrix_alloc(3, 4);

	printf("Rows: %zu\n", matrix->size1);
	printf("Columns: %zu\n", matrix->size2);

	for(int i = 0; i < matrix->size1; i++){
		for(int j = 0; j < matrix->size2; j++){
			gsl_matrix_set(matrix, i, j, i+j);
		}
	}

	for(int i = 0; i < matrix->size1; i++){
		for(int j = 0; j < matrix->size2; j++){
			printf("Value at (%d, %d) is: %f\n", i, j, gsl_matrix_get(matrix, i, j));
		}
	}

	gsl_matrix_free(matrix);
	
	return 0;
}
