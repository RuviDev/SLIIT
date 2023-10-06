#include<stdio.h>

int add(int no1, int no2);
int multiply(int no1, int no2);
int square(int number);

int main(void){
	int answer = square(add(multiply(3, 4), multiply(5, 7)));
	printf("Answer : %d", answer);
	
	return 0;
}

int add(int no1, int no2){
	return no1 + no2;
}

int multiply(int no1, int no2){
	return no1 * no2;
}

int square(int number){
	return number * number;
}
