#include <stdio.h>
#include <string.h>
#define SIZE 5

int main(void) {

    int i;
    char patientName[15], appointmentType;

    FILE* CfPtr;
    CfPtr = fopen("appointment.dat", "w");

    if (CfPtr == NULL) {
        printf("Error Creating the file\n");
        return -1;
    }

    for (i = 0; i < SIZE; i++) {
        printf("Enter the name of the patient %d : ", i + 1);
        scanf("%s", patientName);

        printf("Enter the first Letter of the appointment type (C, T, S) : ");
        scanf(" %c", &appointmentType);
        printf("\n");

        fprintf(CfPtr, "%-15s %c\n", patientName, appointmentType);
    }

    fclose(CfPtr);

    CfPtr = fopen("appointment.dat", "r");

    if (CfPtr == NULL) {
        printf("Error Opening the file\n");
        return -1;
    }

    int noOfConsulting = 0, noOfScanning = 0, noOfTesting = 0;
    char name[15], type;

    while (fscanf(CfPtr, "%s %c", name, &type) == 2) {
        if (type == 'C')
            noOfConsulting++;
        if (type == 'S')
            noOfScanning++;
        if (type == 'T')
            noOfTesting++;
    }

    printf("Appointment Type   Number of Patients\n");
    printf("Consulting\t   %d\n", noOfConsulting);
    printf("Scanning\t   %d\n", noOfScanning);
    printf("Testing\t\t   %d\n", noOfTesting);

    fclose(CfPtr);

    return 0;
}

