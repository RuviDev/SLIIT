#include<stdio.h>
int main(void)
{
	int i=10,no, count;
	float sum, avg;
	
//	Display numbers from 10 to 20
	while(i<=20){
		printf("%d\t", i);
		i++;
	}
	
//	Prompt the user to enter series of numbers from the keyboard and display the numbers.
//	If user enters a negative number stop reading the numbers.
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
	
//	sum and average of the positive numbers entered.
	avg = sum / (float)count;
	
	printf("\nSum : %.3f", sum);
	printf("\nAverage : %.3f", avg);
	
	return 0;
}
