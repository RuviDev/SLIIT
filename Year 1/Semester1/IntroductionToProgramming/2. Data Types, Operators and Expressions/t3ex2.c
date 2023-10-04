#include <stdio.h>

int main() {
    int num, digit1, digit2, digit3, digit4, digit5;

    // Get the user input
    printf("Enter a five-digit number: ");
    scanf("%d", &num);

    // Separate the digits
    digit1 = num / 10000;
    digit2 = (num % 10000) / 1000;
    digit3 = (num % 1000) / 100;
    digit4 = (num % 100) / 10;
    digit5 = num % 10;

    // Print the digits separated by spaces
    printf("%d %d %d %d %d\n", digit1, digit2, digit3, digit4, digit5);

    return 0;
}

