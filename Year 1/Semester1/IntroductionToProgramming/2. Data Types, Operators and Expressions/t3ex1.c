#include<stdio.h>
int main(){
	
	// Declare variables
	float radius, diameter, circum;
	
	// Get the user inputs(radius)
	printf("Enter the radius of the circle : ");
	scanf("%f", &radius);
	
	diameter = radius * 2.0;
	circum = 2.0 * 22/7.0 * radius;
	
	printf("\nDiameter of the Circle : %.2f\n", diameter);
	printf("Circumference of the Circle : %.2f", circum);
	
	return 0;
}
