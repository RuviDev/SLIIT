#include <stdio.h>

int main(void) {
    int i, j, k, marks[10];
    float mean;
    int total = 0;

	// Get the user inputs(marks of 10 students)
    for (i = 1; i <= 10; i++) {
        int mark = 0;
        printf("Enter the marks for student %d: ", i);
        scanf("%d", &mark);

        if (mark >= 0 && mark <= 20)
            marks[i] = mark;
        else{
        	printf(" => Marks should be between 0 to 20 <=\n");
        	i--;
		}
    }

    // Display the marks
    for (j = 1; j <= 10; j++) {
        printf("\n%d", marks[j]);
    }

    // Calculate the total marks
    for (k = 1; k <= 10; k++) {
        total += marks[k];
    }
    printf("\n\nTotal Marks : %d", total);
    
    // Calculate the number of elements in the marks array
    int marks_len = sizeof(marks) / sizeof(marks[0]);
    
    // Calculate the mean
    mean = (float)total / marks_len;
    printf("\n\nMean: %.2f", mean);

    return 0;
}

