#include<stdio.h>

int main(void){
	
	// Declare variables
	int packageID, noOfGuests;
	
	
	while(1){ // Run the program until user input -99 as the package ID
		float total;
		char birthdayCake, fireworks, photograph;
		
		// Get package ID and check the validity of the package ID
		printf("Enter package ID: ");
		scanf("%d", &packageID);
		
		if (packageID == -99)
			break;
		else if (packageID < 1 || packageID > 4){
			printf("Invalid package ID\n");
			return -1;
		}
		
		// Get the no of guests	
		printf("Enter no of guests: ");
		scanf("%d", &noOfGuests);
		
		// Ask the user for other facilities according to the different packages
		if (packageID == 3){
			printf("Do you need a 1kg bithday cake: ");
			scanf(" %c", &birthdayCake);
			printf("Do you need fireworks: ");
			scanf(" %c", &fireworks);
		}
		
		if (packageID == 4){
			printf("Do you need a photograph: ");
			scanf(" %c", &photograph);
		}
		
		// Calculate the total according to the package user chose
		switch (packageID){
			case 1:
				total = noOfGuests * 450.00;
				break;
				
			case 2:
				if (noOfGuests > 0 && noOfGuests <= 15){
					total = noOfGuests * 570.00;
					break;
				}
				else if (noOfGuests > 15 && noOfGuests <= 30){
					total = noOfGuests * 640.00;
					break;
				}
				else{
					printf(" => Invalid no of Guests\n\n");
					continue;
				}
				
			case 3:
				total = noOfGuests * 800.00;
				if ( birthdayCake == 'Y' )
					total += 2800.00;
				if ( fireworks == 'Y' )
					total += 2400.00;
				break;
				
			case 4:
				total = noOfGuests * 1050.00;
				if ( photograph == 'Y' ){
					total += noOfGuests * 900.00;
					total -= (float)total * 0.15;
				}
				break;
			
			default:
				printf("Invalid package type\n");
				return -1;
		}
		
		// Display the package ID and the total charge for the event
		printf("\nYou have selected package ID: %d\n", packageID);
		printf("Total charge for the event: %.2f\n\n", total);
		
	}
	
	return 0;
}
