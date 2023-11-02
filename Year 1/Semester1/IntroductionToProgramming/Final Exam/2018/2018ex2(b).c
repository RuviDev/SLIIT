#include<stdio.h>

int main(void){
	
	// Declare the LED array and other variables
	char LED[4][4];
	int i, j;
	
	// Get the colours of the LED bulbs
	for (i=0; i<4; i++){
		printf("Enter the Colours(R, G, B) of Row %d :\n", i+1);
		for (j=0; j<4; j++){
			printf("  Column %d : ", j+1);
			scanf(" %c", &LED[i][j]);
		}
		printf("\n\n");
	}
	
	// Display the colours of the LED display
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("%c  ", LED[i][j]);
		}
		printf("\n");
	}
	
	// Find the red bulb positions and display the positions
	printf("\nRed LED bulb positions\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if (LED[i][j] == 'R'){
				printf("[%d,%d] ", i, j);
			}
		}
	}
	
	return 0;
}
