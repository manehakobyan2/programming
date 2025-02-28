#include <stdio.h>

int main()
{
	//Define variables
	int n;
	int a[4]={0};

	//Ask for input and check
	printf("Enter a digit in range of 0 to 15: ");
	while(scanf("%d", &n) != 1 || n< 0 || n>15)
	{
		printf("Wrong input. Enter a number that is greater then 0 and less then 15.\n");
		printf("Enter a digit: ");
		while(getchar() !='\n');
	}

        //check for each substract and add 1
	if(n>=8)
	{
		n=n-8;
		a[0]=1;
	}
	if(n>=4)
	{
		n=n-4;
		a[1]=1;
	}
	if(n>=2)
	{
		n =n-2;
		a[2]=1;
	}
	if(n>=1)
	{
		n=n-1;
		a[3]=1;
	}
	printf("Your digit in binary is: ");

	//print the input
	for(int i =0; i < 4; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
return 0;
}
