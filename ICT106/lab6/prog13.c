


int main()
{
	int num1, num2, num3;
	int temp;
	
	printf("Enter 1st number");
	scanf("%d%*c", &num1);
	printf("Enter 2nd number");
	scanf("%d%*C", &num2);
	printf("Enter 3rd number");
	scanf("%d%*c, %num3);

	if(num2 > num1 && num2 > num3)
	temp = num1;
	num1 = num2; 
	num2 = temp;
		if num3 > num2
			temp = num2;
			num2 = num3;
			num3 = temp;
	else
		if num3 > num1 && num3 > num2
			temp = num1
			num1 = num3
			num3 = temp
		if num3 > num2 
			temp = num2
			num2 = num3
			num3 = temp
			
		else
			if(num3 > num2)
				num2 = temp
				num2 = num3 
				num3 = temp
		
	