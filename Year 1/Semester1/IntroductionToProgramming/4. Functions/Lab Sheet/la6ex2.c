#include <stdio.h>

float calBonus(float basicSal);

int main(void){
	float salary, netSalary, bonusAmount;
	
	float x = 7.8;
	float y;
	y = 2.0 * x;
	printf("%.2f", y);
	
//	printf("Enter basic salary : ");
//	scanf("%f", &salary);
//	
//	bonusAmount = calBonus(salary);
//	netSalary = salary + bonusAmount;
//	
//	printf("Net salary : %.2f\n", netSalary);
	
	return 0;
	
	}
	
float calBonus(float basicSal){		//Function implementation
	float bonus;
	
	if(basicSal > 20000){
		bonus = basicSal * 2.0;
	}
	else
		bonus = basicSal / 2.0;
		return bonus;
}
