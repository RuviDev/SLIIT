#include<stdio.h>
#include<assert.h>

int qualityPoints(int marks);

int main(void){
	// Boundary statements
	assert(qualityPoints(100) == 4);
	assert(qualityPoints(90) == 4);
	assert(qualityPoints(80) == 3);
	assert(qualityPoints(70) == 2);
	assert(qualityPoints(60) == 1);
	assert(qualityPoints(50) == 0);
	
	// Middle statements
	assert(qualityPoints(95) == 4);
	assert(qualityPoints(85) == 3);
	assert(qualityPoints(75) == 2);
	assert(qualityPoints(65) == 1);
	assert(qualityPoints(55) == 0);

	return 0;
}

int qualityPoints(int marks){
	if(marks >= 90 && marks <= 100)
		return 4;
	else if(marks >= 80 && marks <= 89)
		return 3;
	else if(marks >= 70 && marks <= 79)
		return 2;
	else if(marks >= 60 && marks <= 69)
		return 1;
	else if(marks < 60)
		return 0;
}
