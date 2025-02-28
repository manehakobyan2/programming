#include <stdio.h>

int main()
{
	//Define array size 10 
	int a[10];
	//Define min and max values
	int min, max;
        //Ask for input for the first integer
	printf("Enter integer 1: ");
        //Check the input
	while(scanf("%d", &a[0]) != 1)
	{
		printf("Wrong input\n");
		printf("Enter integer 1: ");
		//Clear input buffer
		while(getchar() != '\n');
	}
	//Set min and max as first integer of array
	min = a[0];
	max= a[0];


	//Loop trough the array to set the numbers
	for (int i = 1; i <10; i++)
	{
	     //Ask for input and check
	     printf("Enter digit %d: ", i+1);
	      while(scanf("%d", &a[i])!= 1)
	      { 
	        printf("Wrong input.\n");
	        printf("Enter digit %d: ", i+1);
                while(getchar() != '\n');
              }		
	}

	//Loop through array
	for(int i = 0; i<10; i++)
	{
		//Check for greater number then max and smaller number for min
		if(max<a[i])
		{
			max= a[i];
		}
		else if(min>a[i])
		{
			min = a[i];
		}
	}

	printf("Minimum: %d\nMaximum: %d\n", min, max);
	return 0;
}
