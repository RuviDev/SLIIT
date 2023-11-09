#include <stdio.h>

int main(void) {
    FILE *file;
    file = fopen("customer.dat", "r");

    if (file == NULL) {
        printf("Error Opening the file");
        return -1;
    }

    int i = 0, j, customerID[3];
    char customerName[3][9], teleNo[3][10];

    while (!feof(file)) {
        fscanf(file, "%d %s %s", &customerID[i], &customerName[i], &teleNo[i]);
        i++;
    }

    fclose(file);

    file = fopen("customer.dat", "a");

    for (i = 0; i < 2; i++) {
        int custID;
        char custName[9], telNo[10];

        printf("Customer %d\n", i + 1);
        printf("  Enter the Customer ID : ");
        scanf("%d", &custID);
        printf("  Enter the Name : ");
        scanf("%s", custName);
        printf("  Enter the Telephone Number : ");
        scanf("%s", telNo);

        int exist = 0;
        for (j = 0; j < 3; j++) {
            if (custID == customerID[j]) {
                printf("   => Customer Already Exists\n\n");
                exist = 1;
                i--;
                break;
            }
        }

        if (!exist) {
        	printf("   => Customer Appended\n\n");
            fprintf(file, "%-3d %-9s %-10s\n", custID, custName, telNo);
        }
    }

    fclose(file);

    return 0;
}
