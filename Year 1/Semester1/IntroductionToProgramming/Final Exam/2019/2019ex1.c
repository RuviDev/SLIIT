#include <stdio.h>
int main(void) {
	
	// Declare variables
    int i = 1,pizzaType, pizzaNum;
    char pizzaSize;
    float pizzaPrices[2][2] = {
        {1720.0, 975.0},
        {1820.0, 1000.0}
    };
    float price, totalPrice = 0;

	// Get the user inputs until user inputs (-1) to exit
    while (1) {
    	price = 0;
    	printf("Invoice%d =>\n", i);
        printf("  Enter the pizza type (1, 2), (-1) to exit : ");
        scanf("%d", &pizzaType);
        getchar(); 	// clear non integer inputs
        
        if (pizzaType == -1){
        	printf("  All Invoices Entered\n\n");
        	break;
		}
		
        if (pizzaType != 1 && pizzaType != 2) {
            printf("  => Error, Invalid pizza type\n\n");
            continue;
            i--;
        }

        printf("  Enter the pizza size (M, L) : ");
        scanf(" %c", &pizzaSize);
        
        if (pizzaSize != 'M' && pizzaSize != 'L') {
            printf("  => Error, Invalid pizza size\n\n");
            continue;
            i--;
        }
        
        printf("  Enter the number of pizzas : ");
        scanf("%d", &pizzaNum);
        scanf("%*c");
        
        if (pizzaNum >= 0 && pizzaNum <= 1e-100){
        	printf("  => Error, Invalid pizza size\n\n");
            continue;
            i--;
		}
        
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
        
        printf("  => Total amount: LKR%.2f\n", price);
        totalPrice += price;	// Calculate tht total Price
        printf("\n");
        i++;
    }
    printf("Total price for all orders: LKR%.2f\n", totalPrice);

    char creditCard, loyaltyCustomer, onlineOrder;

	// Ask user for payment method
    printf("\nAre you paying by credit card (Y/N)? ");
    scanf(" %c", &creditCard);
    printf("Are you a loyalty customer (Y/N)? ");
    scanf(" %c", &loyaltyCustomer);
    printf("Is this an online order (Y/N)? ");
    scanf(" %c", &onlineOrder);

    
    // Calculate the highest discount percentage
    float discountPercentage = 0.0;

    if (creditCard == 'Y' || creditCard == 'y') {
        discountPercentage = 20.0; // 10% discount for credit card
    }

    if (loyaltyCustomer == 'Y' || loyaltyCustomer == 'y') {
        if (discountPercentage < 15.0) {
            discountPercentage = 15.0; // 15% discount for loyalty customer (if higher than credit card discount)
        }
    }

    if (onlineOrder == 'Y' || onlineOrder == 'y') {
        if (discountPercentage < 5.0) {
            discountPercentage = 5.0; // 5% discount for online order (if higher than other discounts)
        }
    }

    // Calculate the discounted total amount and Print it
    float discountedPrice = totalPrice - (totalPrice * discountPercentage / 100.0);   
    printf("\nNet Total amount: LKR%.2f\n", discountedPrice);
		
	return 0;
}
