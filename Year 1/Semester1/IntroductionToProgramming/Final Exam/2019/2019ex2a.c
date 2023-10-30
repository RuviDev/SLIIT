#include<stdio.h>
#define SIZE 10

int main(void){
	
	// Declare Variables
	int i, fib[SIZE] = {0, 1};
	
	for(i=0; i<SIZE; i++){
		fib[i+2] = fib[i] + fib[i+1];
	}
	
	printf("|");
	for(i=0; i<SIZE; i++){
		printf("%d  |", fib[i]);
	}
	
	return 0;
}
