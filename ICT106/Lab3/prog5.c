#include <stdio.h>
int main()
{
	int min=65;
	int max=90;
	
	printf("Character	Decimal		Hex\n");
	
	for(int i = min; i <= max; i++)
		printf("%4c %15d %14X\n", i, (char)i, (int)i);
}