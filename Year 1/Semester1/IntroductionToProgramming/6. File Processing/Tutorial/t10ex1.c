#include <stdio.h>
#define SIZE 5

int main(void) {
    FILE *file = fopen("number.dat", "r");

    if (file == NULL) {
        printf("Error opening the file");
        return -1;
    }

    int numArr[SIZE];
    fscanf(file, "%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);
    fclose(file);

    FILE *appendFile = fopen("number.dat", "a");

    int i, number, exist = 0;
    printf("Enter the number: ");
    scanf("%d", &number);

    for (i = 0; i < SIZE; i++) {
        if (numArr[i] == number) {
            printf("Error, Number already exists\n\n");
            exist = 1;
        }
    }
    if (!exist)
        fprintf(appendFile, " %d", number);

    fclose(appendFile);

    FILE *readFile = fopen("number.dat", "r");

    int no;
    while (fscanf(readFile, "%d", &no) == 1) {
        printf("%d\t", no);
    }

    fclose(readFile);

    return 0;
}

