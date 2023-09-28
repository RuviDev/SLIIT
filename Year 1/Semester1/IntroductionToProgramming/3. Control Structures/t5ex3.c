#include<stdio.h>
int main(void)
{
	int i, numstd, highstd[3], numhighstd=0, j;
	float mark, total, hightot;
	
	for(numstd=1; numstd<4; numstd++){
		total = 0;
		printf("\nEnter marks for Student %d:\n", numstd);
		
		for(i=1; i<5; i++){
//			mark = 0;
			printf(" Enter the marks of the Module%d : ", i);
			scanf("%f", &mark);		
			if (mark < 0 || mark > 100) {
                printf(" Invalid marks entered, Marks should be between 0 and 100.\n");
                i--;
                continue;
            }
			total = total + mark;
		}
				
		printf("Total marks for Student%d : %.2f\n", numstd, total);
		
		if (total > hightot) {
            hightot = total;
            numhighstd = 1;
            highstd[0] = numstd;
        } else if (total == hightot) {
            highstd[numhighstd] = numstd;
            numhighstd++;
        }
	}
	
	printf("\nStudents with the highest total marks:\n");
    for(j=0; j<numhighstd; j++){
        printf(" Student %d: %.2f\n", highstd[j], hightot);
    }
	
	return 0;
}

