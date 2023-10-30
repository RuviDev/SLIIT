#include<stdio.h>
#include<assert.h>
#define SIZE 5

// Function Prototypes
float calAnnualInterest(float interestRate, float amount);
float findTotalAmount(float interestRte, float amount);
void testTotalAmount();

int main(void){
	
	testTotalAmount();	// Ensure the findTotalAmount function works properly
	
	// Declare Variables
	int i;
	float initialAmount, anualInterest;
	
	// Get the user inputs
	printf("Enter Initial Amount to be invested\t : ");
	scanf("%f", &initialAmount);
	printf("Enter Anual Interest Rate(in percentage) : ");
	scanf("%f", &anualInterest);
	
	// Print the total amount earned at the end of each year
	for(i=0; i<SIZE; i++){
		float total = findTotalAmount(anualInterest, initialAmount);
		printf("\nAmount after year %d  : %.2f", i+1, total);
		initialAmount = total;
	}
	
	return 0;
}


// Function to calculate annual interest
float calAnnualInterest(float interestRate, float amount){
	if (amount >= 1000000)
		interestRate += 0.5;
	return amount * (interestRate / 100.0);
}

// Function to find the total amount after applying annual interest
float findTotalAmount(float interestRate, float amount){
	return calAnnualInterest(interestRate, amount) + amount;
}

// Function to test the findTotalAmount function using assert statements
void testTotalAmount(){
	assert(findTotalAmount(5, 1000000) == 1055000);
	assert(findTotalAmount(5, 100000) == 105000);	
}
