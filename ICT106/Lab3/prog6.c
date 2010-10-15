#include <stdio.h>
int main()
{
int x;
int result = 1;
	printf("Enter x value: ");
	scanf("%d%*c", &x);

	printf("f(%d) = ",x);
	
	if(x != 0)
	{
		for(;x>0; x--)
		{
		printf("%d",x);
			result = x*result;
			if(x != 1)
				printf("*");
			else
			printf(" =");
		}
			
	}
	printf(" %d", result);
}