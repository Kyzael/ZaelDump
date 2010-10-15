#include <stdio.h>

int main()
{
	float amnt;
	float expenses;
	int year = 2010;
	float interest;
	float tax;
	float inflation;
	float income;

	printf("Enter savings amount: ");
		scanf("%f%*c", &amnt);
	printf("Enter yearly expenses: ");
		scanf("%f%*c", &expenses);
	printf("Enter interest rate: ");
		scanf("%f%*c", &interest);
			interest = interest * 0.01; 
	printf("Enter income tax: ");
		scanf("%f%*c", &tax);
			tax = 1 - (tax* 0.01);
	printf("Enter inflation: ");
		scanf("%f%*c", &inflation);
			inflation = 1 + (inflation * 0.01);
			

			
	printf("Year    Savings        	Interest   Expenses ", year);
	while(amnt > expenses)
	{	
		income = amnt * interest;
		income = income * tax;
		amnt = amnt + income;
		amnt = amnt - expenses;
		expenses = expenses * inflation;
		printf("\n%d    %7.2f    %8.2f    %12.2f", year, amnt,  income, expenses);
		
		year++;
	}
	
	printf("\nOut of Money in %d", year);
	return(0);
}
	