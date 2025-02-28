#include <stdio.h>

int main ()
{
	//Define variables
	int num1, num2;
	int digit;
        //Ask for input
	printf("Enter the numbers you want to concatenate:  ");
	//Check for correct input
	if (scanf("%d %d", &num1, &num2) != 2 || num2<0 ||num1< 0){
		printf("Wrong input.\n");
		return 1;}
	//Copy number
	digit = num2;
	//Calculate the digits of num1 and multiply by 10 the second one
	while(digit != 0){
		digit = digit/10;
		num1= num1*10;
	}
	//Add the second number 
	num1 = num1 + num2;
	printf("%d\n", num1);
	return 0;
}
