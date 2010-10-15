#include <stdio.h>

/* Prototypes */
void getInput(float input[], int size);
float getSmallestNumber(float input[], int size);
float getLargestNumber(float input[], int size);
float calculateAverage(float input[], int size);
void outputOriginalNumbers(float input[], int size);
/* End of Prototypes */

int main()
{
	float input[10];
	float smallest;
	float largest;
	float average;
	int inputsize = sizeof(input) / sizeof(int);

	getInput(input, inputsize);
	smallest = getSmallestNumber(input, inputsize);
	largest = getLargestNumber(input, inputsize);
	average = calculateAverage(input, inputsize);
	printf("Original values: ");
	outputOriginalNumbers(input, inputsize);
	
	printf("\nAverage is : %0.2f", average);
	printf("\nSmallest is : %0.2f", smallest);
	printf("\nLargest is : %0.2f", largest);

return(0);
}

void getInput(float input[], int size)
{
	
	for(int i = 0; i < size; i++)
	{
		printf("Enter Number %d :", i +1);
		scanf("%f%*c", &input[i]);
	}
}

float getSmallestNumber(float input[], int size)
{
     	
	float smallest = input[0];
	
	for(int i = 1; i < size; i++)
	{
		if( input[i] < smallest)
			smallest = input[i];
	}
	return(smallest);
}

float getLargestNumber(float input[], int size)
{
	float largest = input[0];
	
	for(int i = 1; i < size; i++)
	{
		if( input[i] > largest)
			largest = input[i];
	}
	return(largest);
}

float calculateAverage(float input[], int size)
{
	float sum = 0;
	float average;
	
	for(int i = 0; i < size; i++)
	{
		sum = sum + input[i];
	}

	average = sum / size;

	return(average);
}

void outputOriginalNumbers(float input[], int size)
{
	
	for(int i = 0; i < size; i++)
	{
		printf("%0.2f, ", input[i]);
	}
}
