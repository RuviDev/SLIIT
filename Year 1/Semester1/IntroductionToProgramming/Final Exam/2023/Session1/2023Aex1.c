#include<stdio.h>

int main(void){
	
	// Declare Variables
	int sawanPrices[3] = {7000, 10000, 12000};
	int i = 0;
	
	while( i<5 ){
		
		// Declare Variables
		int sawanType, noOfSawans, totalAmount;
		char orderType, moreOrders;
		float payAmount;
		
		// Get the sawanType and noOfSawans and Check the validity of sawanType
		printf("Sawan Type: ");
		scanf("%d", &sawanType);
		
		if ( sawanType != 1 && sawanType != 2 && sawanType != 3 ){
			printf(" => Invalid Sawan Type\n\n");
			continue;
		}
			
		printf("No of Sawans: ");
		scanf("%d", &noOfSawans);
		
		// Calculate the total Amount
		totalAmount = sawanPrices[sawanType - 1] * noOfSawans;
		
		// Get the orderType
		printf("Order Type: ");
		scanf(" %c", &orderType);
		
		// Calculate the amount to be paid after the discount and display it
		switch ( orderType ){
			case 'I':
				payAmount = (float)totalAmount + (totalAmount * 0.05);
				break;
			case 'T':
				payAmount = (float)totalAmount;
				break;
			case 'D':
				payAmount = (float)totalAmount + (totalAmount * 0.1);
				break;
			default:
				printf(" => Invalid order Type\n");
				return -1;
		}
		
		printf("Amount to be paid: %.2f\n", payAmount);
		
		// Ask if theres more Orders
		printf("Do you want to input the next order details: ");
		scanf(" %c", &moreOrders);
		
		// Check if theres any more orders and if not terminate the program
		if ( moreOrders == 'Y' ){
			printf("\n");
			i++;
			continue;
		}else if ( moreOrders == 'N' )
			return 0;
		else{
			printf(" => Error");
			return -1;
		}
	}
	
	return 0;
}
