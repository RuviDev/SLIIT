#include<stdio.h>
#define SIZE 4	// How many reviewers

int main(void){
	
	// Declare Varaibles
	int i, j, rating, ratings[3][SIZE], total, bestMovie;
	float avgArr[3], highestAverage = 0;
	
	// Get the movie ratings from the reviewers and store them in the ratings array
	for(i=0; i<3; i++){
		printf("Movie %d:\n", i+1);
		for(j=0; j<SIZE; j++){
			printf("  Enter the rating of the reviewer%d : ", j+1);
			scanf("%d", &rating);
			getchar();	// clear non integer inputs
			
			// Check the validity of the ratings
			if (rating > 0 && rating <= 10)
				ratings[i][j] = rating;
			else{
				printf("   Invalid Rating\n");
				j--;
				
			}			
		}
		printf("\n");
	}
	
	// Print the ratings array in tabular format
	for (i=0; i<3; i++){
		int total = 0;
		for(j=0; j<SIZE; j++){			
			printf("%d\t", ratings[i][j]);
			total += ratings[i][j];
		}
		printf("\n");
		
		avgArr[i] = total / (float)SIZE;	// Calculate and store the average rating for each movie
				
		// Find the highest average movie
		if (highestAverage < avgArr[i]){
			highestAverage = avgArr[i];
			bestMovie = i+1;
		}
	}
	
	// Print the average rating for each movie
	for (i=0; i<3; i++){
		printf("\nMovie %d, Average rating : %.2f", i+1, avgArr[i]);
	}
	
	// print the highest average movie
	printf("\n\nMovie %d received the highest average rating of %.2f", bestMovie, avgArr[bestMovie-1]);
	
	return 0;
}
