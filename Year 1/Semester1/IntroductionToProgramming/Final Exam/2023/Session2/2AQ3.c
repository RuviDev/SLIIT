#include<stdio.h>
#include<assert.h>

// Function Prototypes
double payementAmount(int date, char cardType, double amount);
void displayLoyaltytype(double payment);
void testpayementAmount();

int main(void){
	
	// Declare variables
	int date;
	char cardType;
	double amount, totalAmount;
	
	// Get the user inputs
	printf("Enter the Date : ");
	scanf("%d", &date);
	printf("Enter the Card Type : ");
	scanf(" %c", &cardType);
	printf("Enter the Amount : ");
	scanf("%lf", &amount);
	
	// print the total Payable amount using the payementAmount function
	totalAmount = payementAmount(date, cardType, amount);
	printf("\nTotal Payable Amount after discount : %.2f\n", totalAmount);
	
	displayLoyaltytype(totalAmount); // Display the Loyalty card type obtained
	
	testpayementAmount(); // test the payementAmount function
	
	return 0;
}

// Function to alculate Total payable amount after deducting discount
double payementAmount(int date, char cardType, double amount){
	double discount = 0.0, totalPayable;
	
	// Find the discount
	switch (date){
		case 23:
			if (cardType == 'a')
				discount = 0.2;
			break;
		case 24:
			if (cardType == 'b')
				discount = 0.25;
			break;
		case 25:
			if (cardType == 'c')
				discount = 0.3;
			break;
		case 26:
			if (cardType == 'b' || cardType == 'c')
				discount = 0.2;
			break;
		default:
			discount = 0.0;
			break;
	}
	
	// Calculate and return the totalPayable amount
	totalPayable = amount * (1 - discount);
	return totalPayable;
}

// Function to display the card type obtained by each customer
void displayLoyaltytype(double payment){
	if (payment > 25000)
		printf("Gold\n");
	else if(payment > 10000 && payment < 25000)
		printf("Silver\n");
	else if(payment < 10000)
		printf("Bronze\n");
}

// Function to debug the implemented payementAmount function
void testpayementAmount(){
	assert(payementAmount(23, 'a', 10000) == 8000);
	assert(payementAmount(23, 'c', 10000) == 10000);
	assert(payementAmount(26, 'b', 10000) == 8000);
}
