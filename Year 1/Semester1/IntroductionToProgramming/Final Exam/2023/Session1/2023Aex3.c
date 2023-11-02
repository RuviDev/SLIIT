#include<stdio.h>
#include<assert.h>

// Function Prototypes
double PayableAmount(char vehicleType, int NumDays);
double paymentAfterTax(double payment);
void testpaymentAfterTax();

int main(void){
	char vehicleType;
	int NumDays;
	
	// Get the user inputs
	printf("Enter vehicle Type (a or b) : ");
	scanf(" %c", &vehicleType);
	printf("Enter number of rental days : ");
	scanf("%d", &NumDays);
	
	// Find the payableAmount after the discount and the finalAmount after the tax
	double payableAmount = PayableAmount(vehicleType, NumDays);
	if (payableAmount == -1.0)
		return -1;

	double finalAmount = paymentAfterTax(payableAmount);
	
	// Display the payableAmount and finalAmount
	printf("Payable amount after discount: %.2f\n", payableAmount);
	printf("Payable amount after tax: %.2f\n", finalAmount);
	
	testpaymentAfterTax(); // Test the paymentAfterTax Function
	
	return 0;
}

// Function to calculate the payable amount with the discount
double PayableAmount(char vehicleType, int NumDays){
	double rentalRate, discount, payableAmount;
	
	// Find the rental Rate for the vehicle Type
	if (vehicleType == 'a')
		rentalRate = 5000;
	else if (vehicleType == 'b')
		rentalRate = 8000;
	else{
		printf("  => Invalid vehicle type\n");
		return -1.0;
	}	
	
	// Calculate the discount
	if (NumDays >= 1 && NumDays <= 3){
		discount = 0.0;
	}else if (NumDays >= 4 && NumDays <= 6){
		discount = 0.1;
	}else if (NumDays >= 7){
		discount = 0.2;
	}else{
		printf("  => Invalid Number of Days\n");
		return -1.0;
	}
	
	payableAmount = rentalRate * (double)NumDays * (1 - discount);
	return payableAmount;
}

// Function to calculate the final payable amount with the tax
double paymentAfterTax(double payment){
	
	if (payment > 15000)
		return payment * 1.10;
	else if (payment >= 10000)
		return payment * 1.05;
	else
		return payment;
}

// Function to test paymentAfterTax function
void testpaymentAfterTax(){
	assert(paymentAfterTax(9000) == 9000);
	assert(paymentAfterTax(10000) == 10500);
	assert(paymentAfterTax(16000) == 17600);
}
