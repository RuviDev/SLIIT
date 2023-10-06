#include<stdio.h>
#include<string.h>


int main (void){
	int i, j, k, marks[11];
	float mean;
	
	for (i=1; i<=10; i++){
		int mark=0;
		printf("Enter the marks for student %d : ", i);
		scanf("%d", &mark);
		
		if (mark >= 0 && mark <= 20)
			marks[i] = mark;
		else
			i--;
	}
	
	// Display the marks
	for (j=1; j<=10; j++){
		printf("\n%d", marks[j]);
	}
	
	// Calculate the mean
	int total;
	for (k=1; k<=10; k++){
		total += marks[k];
	}
	mean = total / strlen(marks);
	printf("\nMean : %.2f", mean);
	
	return 0;
}
