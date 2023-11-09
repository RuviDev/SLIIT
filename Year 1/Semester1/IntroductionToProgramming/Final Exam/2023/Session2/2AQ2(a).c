# include<stdio.h>
# define SIZE 8

int main(void){
	
	// Declare the array marks and other variables
	int i, stdCount = 0;
	float  marks[SIZE], total, average, highestMark = 0.0, lowestMark = 100.0;
	
	// Get marks of 8 students and store them in the marks array
	for (i=0; i<SIZE; i++){
		printf("Enter the marks of student %d : ", i+1);
		scanf("%f", &marks[i]);
		
		total += marks[i]; // Calulate the total marks
		
		// Find the highest and lowest marks
		if (marks[i] > highestMark){
			highestMark = marks[i];
		}
		if (marks[i] < lowestMark){
			lowestMark = marks[i];
		}
	}
	
	// Calculate the average marks
	average = total / SIZE;
	
	// Find the no of student who obtained marks higher than the average marks
	for (i=0; i<SIZE; i++){	
		if (marks[i] > average)
			stdCount++;
	}
	
	// Display the outputs
	printf("\nAverage mark: %.1f", average);
	printf("\nHighest mark : %.1f", highestMark);
	printf("\nNumber of students who obtained marks higher than the average mark: %d", stdCount);
	printf("\nThe difference between highest and lowest marks of the students: %.1f", highestMark - lowestMark);
	
	return 0;
}
