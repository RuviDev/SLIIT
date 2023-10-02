#include<stdio.h>
int main(void){
	
	// Declare Variables
	int module1, module2;
	float average;
	
	// User Inputs
	printf("Enter the marks for module 1 : ");
	scanf("%d", &module1);
	printf("Enter the marks for module 2 : ");
	scanf("%d", &module2);
	
	average = (module1 + module2) / 2.0;
	printf("Average : %.2f\n", average);

	if (average > 45){
		printf("Pass");
	}else{
		printf("Fail");
	}
	
	return 0;	
	
}
