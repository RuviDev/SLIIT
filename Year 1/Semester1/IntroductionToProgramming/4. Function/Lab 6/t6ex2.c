#include<stdio.h>

float circleArea(float radius);

int main(void){
	float radius, area;
	
	printf("Enter the radius : ");
	scanf("%f", &radius);
	
	area = circleArea(radius);
	printf("Area : %.2f", area);
	
	return 0;
}

float circleArea(float radius){
	float area = 22/7.0 * radius * radius;
	return area;
}
