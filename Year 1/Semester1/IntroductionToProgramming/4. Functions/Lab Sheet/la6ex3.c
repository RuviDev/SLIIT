#include<stdio.h>

float circleArea(float radius);
float circlePeri(float radius);
float recArea(float width, float length);

int main(void){
	float radius, height, cyl_area;
	
	printf("Enter the radius : ");
	scanf("%f", &radius);
	printf("Enter the height : ");
	scanf("%f", &height);
	
	cyl_area = recArea(height, circlePeri(radius)) + (2.0 * circleArea(radius));
	
	printf("Cylinder Area : %.2f", cyl_area);
	
	return 0;
}

float circleArea(float radius){
	float area = 22/7.0 * radius * radius;
	return area;
}

float circlePeri(float radius){
	float perimeter = 2.0 * 22/7.0 * radius;
	return perimeter;
}

float recArea(float width, float length){
	float rec_area = length * width;
	return rec_area; 
}
