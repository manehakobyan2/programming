#include <stdio.h>

int main()
{
	//Make an array of size 10 and set to 0 to count the occurence of the number
	int a[10]={0};
	int n;

	printf("Sequence of numbers.\n");
	//infinte loop till breaks
	while(1)
	{
		//Take input
		printf("Number: ");
		scanf("%d", &n);
		//break the loop if minus 1
		if(n == -1)
		{
			break;
		}
		//check to be in range and add 1 in the n-1th place
		else if(n >= 1 && n<=10)
		{
			a[n-1]++;
		}
		else
		{
			printf("Wrong input.\n");
			//clear the buffer to not get infinite loop
			while(getchar() != '\n');
		}
	}

	//go trough the array and print
	for(int i =0; i < 10; i++)
	{
		printf("Number %d occures %d times.\n", i + 1, a[i]);
	}

	return 0;
}
