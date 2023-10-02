#include<stdio.h>
int main(void){
	
	// Declare Variables
	int age;
	char gender;
	
	printf("Enter the Gender(M / F) : ");
	scanf("%c", &gender);
	printf("Enter the Age : ");
	scanf("%d", &age);
	
	if (age >= 65 && gender == 'M'){
		printf("SeniorMale");
	}else if (age >= 65 && gender == 'F'){
		printf("SeniorFemale");
	}
	
	return 0;	
	
}
