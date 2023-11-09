#include<stdio.h>

int main(void){
	
	// Declare the image array and other variables
	int i, j, image[5][5], noOftwo = 0;
	
	// Get the values for the image array
	for (i=0; i<5; i++){
		printf("Row %d: \n", i+1);
		for (j=0; j<5; j++){
			printf("  Enter the value of the column %d : ", j+1);
			scanf("%d", &image[i][j]);
		}
	}
	
	printf("\n\n");
	// Display the content of image array in a tabular format
	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			printf("  %d", image[i][j]);
			
			// Find the number of 2 by 2 squares filled with all 1s
			if (image[i][j] == 1 && image[i][j+1] == 1 && image[i+1][j] == 1 && image[i+1][j+1] == 1){
				noOftwo++;
			}
			
		}
		printf("\n");
	}
	
	// Display the number of 2 by 2 squares filled with all 1s
	printf("\nNumber of 2 by 2 squares filled with all 1s = %d", noOftwo);
	return 0;
}
