#include <stdio.h>

//Function that takes input a number and returns 0 or 1
int binary(int num)
{
	//checking if the number consists of only 0 and 1
	while(num>0)
	{
		if(num%10 != 0 &&  num%10 != 1)
		{
			return 1;
		}
		num= num/10;
	}
	return 0;
}


int main()
{
	//defining variables
	int num;
	int digit = 0;
	int power = 1;

	//Asking user for input
	printf("Enter your binary number here: ");
	//Verifying input if input is incorrect asking again
	while(scanf("%d", &num) != 1 || binary(num) == 1)
	{
		printf("%d\n", binary(num));
		printf("Wrong input.\nPlease enter a valid number only '0' and '1': ");
		while(getchar() != '\n');//Cleaning the buffer
	}

	//Counting from binary to inetegr
	while(num>0)
	{
		if (num%10 == 1)
		{
			digit += power;
		}

		num = num/10;
		power = power*2;
	}
	//Printing the number
	printf("Your digit is %d.\n", digit);


	return 0;
}
