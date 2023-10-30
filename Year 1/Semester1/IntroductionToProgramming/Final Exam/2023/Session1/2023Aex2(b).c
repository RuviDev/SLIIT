#include<stdio.h>

int main(void){
	
	// Declaring the 3 arrays and varibles
	int A[2][3], B[3][3], C[2][3] = {0};
	int i, j, k;
	
	// Get the elements for Array A and store them
	printf("Matrix A (2x3)\n");
	for (i=0; i<2; i++){
		printf("  |Row %d\n", i+1);
		for (j=0; j<3; j++){
			printf("    |Enter the number for column%d : ", j+1);
			scanf("%d", &A[i][j]);
		}
		printf("\n");
	}
	
	// Get the elements for Array B and store them
	printf("\nMatrix B (3x3)\n");
	for (i=0; i<3; i++){
		printf("  |Row%d \n", i+1);
		for (j=0; j<3; j++){
			printf("    |Enter the number for column%d : ", j+1);
			scanf("%d", &B[i][j]);
		}
		printf("\n");
	}
	
	// Perform Matrix Multiplication on A and B, then store the result in array C
	for (i=0; i<2; i++){
		for (j=0; j<3; j++){
			for (k=0; k<3; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	// Display the content of three arrays in tabular format
	printf("Matrix A:\n");
	for (i=0; i<2; i++){
		printf("   ");
		for (j=0; j<3; j++){
			printf("%d   ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatrix B:\n");
	for (i=0; i<3; i++){
		printf("   ");
		for (j=0; j<3; j++){
			printf("%d   ", B[i][j]);
		}
		
		printf("\n");
	}

	printf("\nMatrix C:\n");
	for (i=0; i<2; i++){
		printf("   ");
		for (j=0; j<3; j++){
			printf("%d   ", C[i][j]);
		}
		printf("\n");
	}


	return 0;
}
