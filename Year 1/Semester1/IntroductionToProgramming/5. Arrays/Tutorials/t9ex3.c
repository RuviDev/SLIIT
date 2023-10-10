#include <stdio.h>
int main(void) {
	
    // Declare Variables
    int salesperson_no, product_no, slip_no = 1;
    float value, totalsales;
    float product[5][4] = {0}; // (5 products x 4 salespeople)

	// Get the user inputs while user input -1
    while (1) {
        printf("Slip Number %d\n", slip_no);

        printf("   Enter the Salesperson number(1-4), (-1) to exit : ");
        scanf("%d", &salesperson_no);    
        if (salesperson_no == -1)
            break;       
        printf("   Enter the Product number (1-5) : ");
        scanf("%d", &product_no);
        printf("   Enter the total dollar value of that product sold that day : ");
        scanf("%f", &value);

        // Check the validity of the data
        if (salesperson_no >= 1 && salesperson_no <= 4 && product_no >= 1 && product_no <= 5 && value >= 0)
            product[product_no-1][salesperson_no-1] += value;
        else {
            printf("   => Invalid entry, Enter valid data\n\n");
            slip_no--;
        }
        slip_no++;
    }
    printf("\n");

    // Display products and salespersons who sold them
    int i, j;
    for (i=0; i<5; i++) {
    	int k = 0;
        printf("Product%d:\n", i+1);
        for (j=0; j<4; j++) {
            if (product[i][j] != 0.0){
            	printf("   | Saleperson%d: $%.2f\n", j+1, product[i][j]);
            	k=1;
			}
        }
        if(k == 0)
        	printf("   | No Sales\n");
    }
    
    // Calculate and display total sales for each product
    printf("\n\nTotal sales for each product:\n");
    for(i=0; i<5; i++) {
        float totalsales = 0;
        for (j=0; j<4; j++) {
            totalsales += product[i][j];
        }
        printf("  Product %d: $%.2f\n", i+1, totalsales);
    }

    return 0;
}

