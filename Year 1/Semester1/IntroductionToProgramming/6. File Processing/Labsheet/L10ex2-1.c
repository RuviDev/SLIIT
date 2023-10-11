#include <stdio.h>
#define SIZE 4

int strToInteger(char str[]);

int main(void) {
    // Declare Variables
    char itemID[4], itemName[10];
    int i, j, quantity;
    
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

    // 2D array to store data read from the file
    char data[SIZE+1][4][42];
    
    // Read and store the header and then details
    fscanf(cfPtr, "%s %s %s %[^\n]s", data[0][0], data[0][1], data[0][2], data[0][3]);
    for (i = 1; i <=SIZE; i++) {
        fscanf(cfPtr, "%s %s %s %[^\n]s", data[i][0], data[i][1], data[i][2], data[i][3]);
    }
    
    fclose(cfPtr);
    
    // Initialize variables for calculations
    int Arr[SIZE][3], total = 0;
    
    // Convert data to integers and calculate total price
    for (j = 0; j < SIZE; j++) {
        Arr[j][0] = strToInteger(data[j + 1][2]); // Quantity
        Arr[j][1] = strToInteger(data[j + 1][3]); // unitPrice
        Arr[j][2] = Arr[j][0] * Arr[j][1];        // Price
        total += Arr[j][2];
    }
    
    // Print the table of item details
    printf("Item\t\tQuantity\t Unit Price\t Price(Rs.)\n");
    for (i = 0; i < SIZE; i++) {
        printf("%s\t\t%d\t\t %d\t\t %d\n", data[i + 1][1], Arr[i][0], Arr[i][1], Arr[i][2]);
    }
    
    // Print the total price
    printf("Total\t\t\t\t\t\t %d", total);
    
    return 0;
}

// Function to convert a string to an integer
int strToInteger(char str[]) {
    int i, result = 0;
    for (i = 0; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

