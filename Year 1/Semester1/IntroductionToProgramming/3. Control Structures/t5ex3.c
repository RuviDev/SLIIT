#include<stdio.h>
int main(void)
{
	// Declare variables
	int i, numstd, highstd[3], numhighstd=0, j;
	float mark, total, hightot;
	
	// Loop for three students
	for(numstd=1; numstd<4; numstd++){
		total = 0;		// Initialize the total marks for each student
		printf("\nEnter marks for Student %d:\n", numstd);
		
		// Loop for four modules
		for(i=1; i<5; i++){
			printf(" Enter the marks of the Module%d : ", i);
			scanf("%f", &mark);
			
			// Check if the entered marks are valid	
			if (mark < 0 || mark > 100) {
                printf(" Invalid marks entered, Marks should be between 0 and 100.\n");
                i--;		// Decrement i to re-enter the same module's marks
                continue;
            }
			total = total + mark;
		}
				
		printf("Total marks for Student%d : %.2f\n", numstd, total);
		
		// Check if the current student has the highest total marks so far
		if (total > hightot) {
            hightot = total;
            numhighstd = 1;
            highstd[0] = numstd;
        } else if (total == hightot) {
        	// If the current student's total marks equal the highest total, add them to the list
            highstd[numhighstd] = numstd;
            numhighstd++;
        }
	}
	
	// Display students with the highest total marks
	printf("\nStudents with the highest total marks:\n");
    for(j=0; j<numhighstd; j++){
        printf(" Student %d: %.2f\n", highstd[j], hightot);
    }
	
	return 0;
}

