#include <stdio.h>
#define SIZE 4

int main(void) {
	// Declare Variables
    char itemID[4], itemName[10];
    int quantity;
    
    // Open a file for writing
    FILE *cfPtr;
    cfPtr = fopen("purchase.txt", "w");
    
    if (cfPtr == NULL) {
        printf("Failed to create file\n");
        return -1;
    }
    
    // Write header to the file(comment this when appending)
    fprintf(cfPtr, "ItemID\t\t Name\t\t Quantity(kg)\t Price_for_1kg");
    
    // Get the user inputs until user enters (e) to exit
    while (1) {
        int unitPrice;
        printf("Enter the Item ID / (e) to exit : ");
        scanf(" %s", &itemID);
        
        // Check for the exit condition
        if (itemID[0] == 'e' && itemID[1] == '\0')
            break;
        
        printf("Enter the Item Name : ");
        scanf(" %s", &itemName);
        printf("Enter the Quantity : ");
        scanf("%d", &quantity);
        printf("Enter the Price for 1 KG : ");
        scanf("%d", &unitPrice);
        printf("\n");
        
        // Write item details to the file
        fprintf(cfPtr, "\n%s\t\t %s\t\t %12d\t %13d", itemID, itemName, quantity, unitPrice);
    }
    
    fclose(cfPtr);
    
    
    // Reopen the file for reading
    cfPtr = fopen("purchase.txt", "r");

	// 2D arrays to store data read from the file
    char charData[SIZE][2][16], header[4][16];
    int i, intData[SIZE][3], total = 0;

	// Read and store the header and then details in the arrays
    fscanf(cfPtr, "%s %s %s %s", header[0], header[1], header[2], header[3]);
    for (i = 0; i < SIZE; i++) {
        fscanf(cfPtr, "%s %s %d %d", charData[i][0], charData[i][1], &intData[i][0], &intData[i][1]);
        intData[i][2] = intData[i][0] * intData[i][1];	// Price = quantity * unitPrice
        total += intData[i][2];		// Calculate and store the total price
    }

    fclose(cfPtr);

    // Print the header and item details
    printf("Item\t\tQuantity\t Unit Price\t Price(Rs.)\n");
    for (i = 0; i < SIZE; i++) {
        printf("%s\t\t%d\t\t %d\t\t %d\n", charData[i][1], intData[i][0], intData[i][1], intData[i][2]);
    }

    // Print the total price
    printf("Total\t\t\t\t\t\t %d\n", total);

    return 0;
}

