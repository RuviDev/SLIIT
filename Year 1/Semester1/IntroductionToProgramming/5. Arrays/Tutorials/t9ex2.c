#include<stdio.h>

int main(void){
	
	// Declare Variables
	int matrix1[4][4] = {{5, 7, 8, 10},
						 {9, 3, 0, 6},
						 {8, 1, 9, 2},
						 {4, 7, 2, 1}};
	int matrix2[4][4] = {{2, 2, 1, 3},
						 {8, 1, 3, 1},
						 {1, 2, 2, 4},
						 {3, 1, 1, 2}};
	int i, j, matrix3[4][4];					  
	
	// Add matrix1 and matrix2 to matrix3	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	
	// Display the matrix3
	int k, l;
	for(k=0; k<4; k++){
		printf("| ");
		for(l=0; l<4; l++){
			printf("%2d ", matrix3[k][l]);
		}
		printf("|\n");
	}		
				  
	return 0;
}
