
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <math.h>


// You can multiply matrices if columns of first equal rows of second
// (R1 x C1) * (R2 x C2) = (R1 x C2)  in terms of how many rows and columns

int main(){
	gsl_matrix *matrix = gsl_matrix_alloc(3, 4);
	gsl_matrix *matrix2 = gsl_matrix_alloc(4, 1);
	gsl_matrix *matrix3 = gsl_matrix_alloc(3, 1);

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

	printf("\n\nWorking with matrix2 now...\n\n");

	for(int i = 0; i < matrix2->size1; i++){
		for(int j = 0; j < matrix2->size2; j++){
			gsl_matrix_set(matrix2, i, j, 10);
		}
	}
	
	for(int i = 0; i < matrix2->size1; i++){
		for(int j = 0; j < matrix2->size2; j++){
			printf("Value at (%d, %d) is: %f\n", i, j, gsl_matrix_get(matrix2, i, j));
		}
	}

	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, matrix, matrix2, 0.0, matrix3);

	printf("\nm3 value is: %f\n\n", gsl_matrix_get(matrix3, 0, 0));
	printf("\nm3 value is: %f\n\n", gsl_matrix_get(matrix3, 1, 0));
	printf("\nm3 value is: %f\n\n", gsl_matrix_get(matrix3, 2, 0));

	gsl_matrix_free(matrix);
	gsl_matrix_free(matrix2);
	gsl_matrix_free(matrix3);
	
	return 0;
}
