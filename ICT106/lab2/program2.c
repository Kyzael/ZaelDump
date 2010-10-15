#include <stdio.h>
int main()
{
	int alpha = 0;
	int line = 1;
	int test;
	char input;
	
	printf("\nEnter a string of words and Lines to count. Ctrl + D to end input.\n");
	
	do
	{
		
		input = getchar();
		
		if(input == EOF)
			printf("\nCounting ...\n");
		else
			if(input == '\n')
				line++;
			else 
					alpha++;
			
	}while(input != EOF);
	
	printf("\nNumber of lines %d\n", line);
	printf("Number of characters %d\n", alpha);
	
	return(0);
	}
