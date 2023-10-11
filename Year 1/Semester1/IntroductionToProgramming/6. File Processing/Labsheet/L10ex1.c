#include<stdio.h>
int main(void){
	
	int i, no;
	
	FILE *cfPtr;
	cfPtr = fopen("numbers.txt", "w");
	
	if ( cfPtr == NULL ){
		printf("Fail to create file\n");
		return -1;
	}
	
	for(i=1; i<=5; i++){
		printf("Enter integer number : ");
		scanf("%d", &no);
		
		fprintf(cfPtr, "%d\n", no);
	}
	
	fclose(cfPtr);
	
	
	cfPtr = fopen("numbers.txt", "r");
	fscanf(cfPtr, "%d", &no);
	
	while( !feof(cfPtr) ){  	// eof means "end of file" and used to check whether the end of the file has been reached, if its not reached it returns 0
		printf("%d\t", no);
		fscanf(cfPtr, "%d", &no);
	}
	
	fclose(cfPtr);
	
	return 0;
}
