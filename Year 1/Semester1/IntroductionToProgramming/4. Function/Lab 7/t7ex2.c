#include<stdio.h>
#include<math.h>
#include<assert.h>

double hypotenuse(double side1, double side2);
void testHypotenuse();

int main(void){
	printf("%.1lf\n", hypotenuse(3.0, 4.0));
	testHypotenuse();
	
	return 0;
}

double hypotenuse(double side1, double side2){
	double hypo = sqrt((side1 * side1) + (side2 * side2));
	return hypo;
}

void testHypotenuse(){
	assert(hypotenuse(3.0, 4.0) == 6.0);
	assert(hypotenuse(5.0, 12.0) == 13.0);
	assert(hypotenuse(8.0, 15.0) == 17.0);
}
