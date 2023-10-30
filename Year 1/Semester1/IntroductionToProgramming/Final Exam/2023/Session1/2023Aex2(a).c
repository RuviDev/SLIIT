#include<stdio.h>

int main(void){
	
	// Declare the prices array and Variables
	float prices[10], totalPrice = 0, averagePrice = 0, highestPrice = 0, totoalCost = 0;
	int i, noOfProducts;
	
	for (i=0; i<10; i++){
		
		// Get the prices of the 10 products
		printf("Enter the price of product%d : ", i+1);
		scanf("%f", &prices[i]);
		
		totalPrice += prices[i];
		
		// Find the highest price
		if (prices[i] > highestPrice)
			highestPrice = prices[i];
		
		// find the no of products that cost less than Rs.100
		if (prices[i] < 100.00)
			noOfProducts++;
		
		// Find the total cost of all the products that cost more than Rs.500
		if (prices[i] > 500.00)
			totoalCost += prices[i];
	}
	
	// Calculate the average
	averagePrice = totalPrice / 10.0;
	
	// Display the outputs
	printf("\nAverage Price => %.2f", averagePrice);
	printf("\nHighest Price => %.2f", highestPrice);
	printf("\nNumber of products that cost less than Rs.100.00 => %d", noOfProducts);
	printf("\nTotal cost of all the products that cost more than Rs.500.00 => %.2f", totoalCost);
	
	return 0;
}
