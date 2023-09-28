#include<stdio.h>
int main(void)
{
	int i=10,no, count;
	float sum, avg;
	
	while(i<=20){
		printf("%d\t", i);
		i++;
	}
	
	while(1){
		printf("\nEnter the Number : ");
		scanf("%d", &no);
		if(no<0){
			break;
		}
		printf("%d", no);
		sum = sum + no;
		count++;
	}
	avg = sum / (float)count;
	
	printf("\nSum : %.3f", sum);
	printf("\nAverage : %.3f", avg);
	
	return 0;
}
