#include<stdio.h>
int main(void){
	
	int x1 = 1, x2 = 10;
	
	// (i)
	printf("(i)  | x1 ==> ");
	while(x1 > 1){
		printf("  %d", x1);
		x1--;
	}
	
	printf("\n(i)  | x2 ==> ");
	while(x2 > 1){
		printf("  %d", x2);
		x2--;
	}
	
	x1 = 1, x2 = 10;
	
	// (ii)	
	printf("\n\n(ii) | x1 ==> ");
	do{
		printf("  %d", x1);
		x1--;
	}while(x1 > 1);
	
	printf("\n(ii) | x2 ==> ");
	do{
		printf("  %d", x2);
		x2--;
	}while(x2 > 1);
	
	return 0;
	
}
