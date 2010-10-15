#include <stdio.h>

int main()
{
char binary[16];
int input;
int value = 1;
int total = 0;
int i = 0;
int c = 15;

	printf("Enter 16bit binary string: ");
	for(;i < 16; i++)
	{
		input = getchar();
		binary[i] = input;
	}

	for(;c >= 0; c--)
	{
		if (binary[c] == '1')
		{
			total = total + value;
		}
		value = value * 2;
	}
	printf("Equals : %d", total);

return(0);
}