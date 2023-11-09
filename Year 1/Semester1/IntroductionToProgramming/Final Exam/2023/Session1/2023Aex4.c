#include <stdio.h>
#include <string.h>

int main(void){
	
	int i, itemCode, found;
	char name[10], itemname[10];
	
	FILE *file;
	file = fopen("Items.dat", "w");
	
	if ( file == NULL ){
		printf("Error Creating the file\n");
		return -1;
	}
	
	for (i=0; i<5; i++){
		
		char itemName[10];
		
		printf("Item %d\n", i+1);
		printf("  Enter the Item Code : ");
		scanf("%d", &itemCode);
		printf("  Enter the name of the item : ");
		scanf("%s", itemName);
		
		fprintf(file, "%d  %s\n", itemCode, itemName);
	}
	
	fclose(file);
	
	file = fopen("Items.dat", "r");
	
	printf("\n\nEnter an Name : ");
	scanf("%s", name);
	
	while(fscanf(file, "%d %s", &itemCode, itemname) == 2){
		if (strcmp(itemname, name) == 0){
			printf("Item Code : %d\n", itemCode);
			found = 1;
			break;
		}
	}
	
	if (!found){
		printf("Error, name is not in the file\n");
		return -1;
	}
	
	fclose(file);
	
	return 0;
}
