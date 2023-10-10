#include<stdio.h>

int main(void){
	int i, arr[10] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
	
	printf("Element\t");
	printf("  Value\t ");
	printf("Histogram\n\n");
	
	for(i=0; i<10; i++){
		printf("%d\t", i);
		printf("  %d\t ", arr[i]);
		
		int j;
		for(j=1; j<=arr[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
