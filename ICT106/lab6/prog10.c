#include <stdio.h>

void compareString(char str1[], char str2[]);
void findEmbeddedString(char str1[], char str2[]);

int main()
{
	char str1[15];
	char str2[15];
	
	printf("Enter first string!");
	scanf("%s", &str1);
	printf("Enter second string");
	scanf("%s", &str2);
	
	compareString(str1, str2);
	findEmbeddedString(str1, str2);
		
	return(0);
	}
	
	void compareString(char str1[]; char str2[])
	{
		int test = 1;
		int start = 0;
		int end = (14);
		int i = end;
		
		while(test == 1 && start != end)
			{
			if(str1[start] != str2[i])
				test = 0;
				
				start++;
				i--;
			}
			
			if(test == 1)
				printf("Strings are equal!");
			else
				printf("Strings are not equal!");
				
		return();
        }

	void findEmbeddedString(char str1[], char str2[])
	{
		int test = 1;
		int str1start = 0;
		int str1end = (14);
		int str2start = 0;
		int str2end = (14);
		int counter = 0;
		
		for(; str1start < str1end;)
			
			str1start = counter;
			
				do
				{
					if(str1[str1start] == str2[str2start])
					{
						str1start++;
						str2start++;
					}
					else
					{
						test = 0;
						str2start = 0;
						counter++;
					}
				}while( test == 1 && str2start != str2end);
				
			if(test == 1) 
				{
				printf("String 2 is embedd in string1");
				int position = str1start - str2end;
				printf("Starting at %d", position);
				}
                return();
        }
				
			
			
			
			