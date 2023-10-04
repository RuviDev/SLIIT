#include<stdio.h>
int main(){
	
	// Declare Variables
	int pizzaType, pizzaNum;
	char pizzaSize;
	float pizzaPrices[2][2] = {
			{1720.0, 975.0},
			{1820.0, 1000.0}
	};
	float price, totalPrice;
	
	// Get the user inputs until the user enters -1
	while(1){
		price = 0;
		printf("Input pizza type : ");
		scanf("%d", &pizzaType);
		if (pizzaType != 1 && pizzaType != 2) {
			if (pizzaType == -1){
	    	break;
			}
	        printf("Invalid pizza type\n\n");
	        continue;
	    }
		
		printf("Input the pizza size : ")	;
		scanf(" %c", &pizzaSize);
		if (pizzaSize != 'L' && pizzaSize != 'M') {
	        printf("Invalid pizza size\n\n");
	        continue;
	    }
		
		printf("Input the number of pizzas : ");
		scanf("%d", &pizzaNum);
		
		// Calculate the total amount based on pizza type, size, and quantity
        if (pizzaType == 1) {
            if (pizzaSize == 'L') {
                price += pizzaPrices[0][0] * pizzaNum;
            } else if (pizzaSize == 'M') {
                price += pizzaPrices[0][1] * pizzaNum;
            }
        } else if (pizzaType == 2) {
            if (pizzaSize == 'L') {
                price += pizzaPrices[1][0] * pizzaNum;
            } else if (pizzaSize == 'M') {
                price += pizzaPrices[1][1] * pizzaNum;
            }
        }
        
        printf(" => Total amount: LKR%.2f\n\n", price);
        totalPrice += price;
        
    } // End of while
    

    // Ask user for payment method
    char creditCard, loyaltyCustomer, onlineOrder;

    printf("\nAre you paying by credit card (Y/N)? ");
    scanf(" %c", &creditCard);

    printf("Are you a loyalty customer (Y/N)? ");
    scanf(" %c", &loyaltyCustomer);

    printf("Is this an online order (Y/N)? ");
    scanf(" %c", &onlineOrder);

    
    // Calculate the highest discount percentage
    float discountPercentage = 0.0;

    if (creditCard == 'Y') {
        discountPercentage = 20.0; // 10% discount for credit card
    }

    if (loyaltyCustomer == 'Y') {
        if (discountPercentage < 15.0) {
            discountPercentage = 15.0; // 15% discount for loyalty customer (if higher than credit card discount)
        }
    }

    if (onlineOrder == 'Y') {
        if (discountPercentage < 5.0) {
            discountPercentage = 5.0; // 5% discount for online order (if higher than other discounts)
        }
    }

    // Calculate the discounted total amount
    float discountedPrice = totalPrice - (totalPrice * discountPercentage / 100.0);
    
    printf("\nNet Total amount: LKR%.2f\n", discountedPrice);
		
	return 0;	
}
