#include <stdio.h>
#include <string.h>
#define SIZE 4

int main(void) {
	// Declare Variables
    char accNo[15], nicNo[7], custName[15];
    int i, found = 0;

    FILE *file;
    file = fopen("account.txt", "w");

	// Check if the file couldn't be opened.
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

	// Write a header line to the file
    fprintf(file, "Account_Number\t\tNIC_Number\t\tCustomer_Name\t\tAccount_Balance\n");
    printf("| All the Inputs width should be between 8 bytes to 15 bytes, except for Customer_Name (should be below 7 bytes) |\n\n");
    
	// Get the customer details using a for loop
	for (i = 0; i < SIZE; i++) {
        float accBalance;
        printf("Customer%d Info =>\n", i + 1);
        printf("  Enter the Account Number : ");
        scanf(" %s", accNo);
        printf("  Enter the NIC Number : ");
        scanf(" %s", nicNo);
        printf("  Enter the Customer Name : ");
        scanf(" %s", custName);
        printf("  Enter the Account Balance : ");
        scanf(" %f", &accBalance);
        printf("\n");

		// Write customer details to the file.
        fprintf(file, "%s\t\t%s\t\t%s\t\t\t%15.2f\n", accNo, nicNo, custName, accBalance);
    }

    fclose(file); // Close the file

	// Reopen the file for reading.
    file = fopen("account.txt", "r");

	// Declare arrays to store data from the file
    char header[6][24], charAcc[SIZE][3][16];
    float intAcc[SIZE];

	// Read and store the header and the Customer details
    fscanf(file, "%s %s %s %s", header[0], header[1], header[2], header[3]);
    for (i = 0; i < SIZE; i++) {
        fscanf(file, "%s %s %s %f", charAcc[i][0], charAcc[i][1], charAcc[i][2], &intAcc[i]);
    }
    
    fclose(file); // Close the file

	// Ask for an Account number to check the account balance
    printf("Enter the Account number to check the Account Balance: ");
    scanf(" %s", accNo);
	
	// Check whether the input account number is in the charAcc array and print the account balance if it's found
    for (i = 0; i < SIZE; i++) {
        if (strcmp(charAcc[i][0], accNo) == 0) {
            printf("  Account Balance: %.2f\n", intAcc[i]);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Invalid Account Number\n");

	// Open transcation.txt file
    FILE *file2 = fopen("transaction.txt", "r");

    if (file2 == NULL) {
        printf("Error Opening the file\n");
        return -1;
    }

	// Declare arrays to store transaction details
    char transTypeArr[4][2];
    float transAmntArr[4];
    
    // Read and store the header and the transaction details
    fscanf(file2, "%s %s", header[4], header[5]);
    for (i = 0; i < 4; i++) {
        fscanf(file2, "%s %f", transTypeArr[i], &transAmntArr[i]);
    }

    fclose(file2); // Close the transaction.txt file
    
	// Update the account balances for deposits and withdrawals
    printf("\nUpdated Balance of,\n");
    for (i = 0; i < SIZE; i++) {
        if (strcmp(transTypeArr[i], "D") == 0)
            intAcc[i] += transAmntArr[i];
        if (strcmp(transTypeArr[i], "W") == 0)
            intAcc[i] -= transAmntArr[i];

		// Print updated account balances
        printf("	Account No %s => %.2f\n", charAcc[i][0], intAcc[i]);
    }

    return 0;
}
