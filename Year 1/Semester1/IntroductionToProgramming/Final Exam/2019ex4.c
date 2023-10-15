#include<stdio.h>
#include<string.h>
#define SIZE 5

// Function Prototypes
int exist(char *loyaltyNumber);
void appendLoyalty(char *loyaltyNumber, char *name);

int main(void){
	
	int i;
	for(i=0; i<SIZE; i++){
		char loyaltyNumber[10], name[20];
		
		// Get the user inputs
		printf("Enter the Name : ");
		scanf(" %s", &name);
		printf("Enter the Loyalty number : ");
		scanf(" %s", &loyaltyNumber);
		
		// Check if the loyalty number already exists, if not append loyalty data to the file
		if(exist(loyaltyNumber)){
			printf("  =>Already Exist\n\n");
			i--;
		}else{
			printf("  =>Appending data\n\n");
			appendLoyalty(loyaltyNumber, name);
		}
	}
	
	return 0;
}

// Function to check if a loyalty number exists in the loyalty.dat file
int exist(char *loyaltyNumber){
	FILE *file = fopen("loyalty.dat", "r");
	
	while (!(feof(file))){
		char loyaltyData[2][100];		
		fscanf(file, "%s %s", loyaltyData[0], loyaltyData[1]);
		
		// Return 1, if the loyalty number matches to a number in the file
		if(strcmp(loyaltyNumber, loyaltyData[0]) == 0){
			fclose(file);
			return 1;
		}
	}
	fclose(file);	
	return 0;
}

// Function to append loyalty data to the loyalty.dat file
void appendLoyalty(char *loyaltyNumber, char *name){
	FILE *file = fopen("loyalty.dat", "a");
	fprintf(file, "%-12s %s\n", loyaltyNumber, name);
	fclose(file);
}
