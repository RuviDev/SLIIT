#include<stdio.h>

int main(void){
	int i, j, k, Motion[5];
	
	// Get the user inputs
	for(i=0; i<5; i++){
		printf("Enter the values to the array : ");
		scanf("%d", &Motion[i]);
	}
	
	// Display the elements of the array before rotating
	printf("\nInitial values\t\t");
	for(k=0; k<5; k++){
		printf(" %d", Motion[k]);
	}
	
	// Store the first element in a variable
	int first_element = Motion[0];
	
	// Rotate the value of the array by one position forward
	for(j=0; j<4; j++){
		Motion[j] = Motion[j+1];
	}
	Motion[4] = first_element;
	
	// Display the elements in the array after rotating
	printf("\nAfter rotating\t\t");
	for(k=0; k<5; k++){
		printf(" %d", Motion[k]);
	}
	
	return 0;
}
