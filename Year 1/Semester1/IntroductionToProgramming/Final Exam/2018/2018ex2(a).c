#include<stdio.h>
#include<string.h>

struct Transactions{
	int accNumber;
	char name[20];
	char transType;
	double amount;
};

int main(void){
	
	// Create an array to store details of customer transactions
	struct Transactions custTransactions[5];
	
	// Initialize the array with sample data
	int i;
	for (i=0; i<5; i++){
		
		printf("Enter Details of the Customer %d :\n", i+1);
		
		printf("  Account Number : ");
		scanf("%d", &custTransactions[i].accNumber);
		
		printf("  Name : ");
		scanf(" %s", &custTransactions[i].name);
		
		printf("  Transaction Type : ");
		scanf(" %c", &custTransactions[i].transType);		
		// Check the validity of transType
		if (custTransactions[i].transType != 'D' && custTransactions[i].transType != 'W' && custTransactions[i].transType != 'd' && custTransactions[i].transType != 'w'){
			printf("   => Invalid Transaction Type\n\n");
			i--;
			continue;
		}
		
		printf("  Amount : ");
		if(scanf("%lf", &custTransactions[i].amount) != 1){	 // Check the validity of the amount
			getchar();
			printf("   => Invalid Amount\n\n");
			i--;
			continue;
		}
		
		printf("\n");
	}
	
	// Declare Variables for calulations
	double totalDeposit = 0.0;
	double totalWithdrawal = 0.0;
	char maxDepositName[20];
	char minWithdrawName[20];
	double maxDepositAmount = 0.0;
	double minWithdrawAmount = custTransactions[0].amount;
	
	for (i=0; i<5; i++){
		
		// Calculate the total Deposit and Withdrawal Amounts
		if (custTransactions[i].transType == 'D' || custTransactions[i].transType == 'd'){
			totalDeposit += custTransactions[i].amount;
			
			// Find the maximum deposit amount and the customers name
			if (custTransactions[i].amount > maxDepositAmount){
				maxDepositAmount = custTransactions[i].amount;	
				strcpy(maxDepositName, custTransactions[i].name);
			}
		}
		
		if (custTransactions[i].transType == 'W' || custTransactions[i].transType == 'w'){
			totalWithdrawal += custTransactions[i].amount;
			
			// Find the minimum withdrawal amount and the customers name
			if (custTransactions[i].amount < minWithdrawAmount){
				minWithdrawAmount = custTransactions[i].amount;				
				strcpy(minWithdrawName, custTransactions[i].name);
			}
		}			
	}
	
	// Print the calculated information
    printf("Total deposit amount: %.2lf\n", totalDeposit);
    printf("Total withdrawal amount: %.2lf\n", totalWithdrawal);
    printf("Name of the customer with the maximum deposit amount: %s\n", maxDepositName);
    printf("Name of the customer with the minimum withdrawal amount: %s\n", minWithdrawName);
	
	return 0;
	
}
