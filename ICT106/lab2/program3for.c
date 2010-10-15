#include <stdio.h>

int main()
{
	int num;

	printf("Enter a number ");
	
	scanf("%d%*c", &num);
	
	for (;num > 0; num--)
	{
		for (int i = 0; i < num; i++)
		{
			printf("%d ", num);
		}
		printf("\n");
	}
	return(0);
}
	