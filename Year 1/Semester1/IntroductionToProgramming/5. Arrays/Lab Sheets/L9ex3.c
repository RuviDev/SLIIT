#include<stdio.h>
int main(void){
	
	// Declare Variables
	int i, j, mark[3][3];  //[students][marks]
	
	// Get user Inputs
	for(i=0; i<3; i++){
		printf("Enter marks of Student%d\n", i+1);
		for(j=0; j<3; j++){
			printf("  Enter the marks of Module%d : ", j+1);
			scanf("%d", &mark[i][j]);
		}
		printf("\n");
	}
	
	// Calculate the averages and store them in the average array
	float average[3][1];	
	for(i=0; i<3; i++){
		float total = 0;
		for(j=0; j<3; j++){
			total += mark[i][j];
		}
		average[i][0] = total / 3.0;
	}
	
	// Display the Averages
	printf("\n\nStudent No\t Exam Scores\t\tAverage\n\n");
	for(i=0; i<3; i++){
		printf("%d\t\t", i+1);
		for(j=0; j<3; j++){
			printf(" %3d  ", mark[i][j]);
		}
		printf(" \t%.2f\n", average[i][0]);
	}
	
	return 0;
}
