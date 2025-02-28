#include <stdio.h>

//Function to sort in ascending order using pointer and size of an array
int ascending(int *a, int n)
{
	//Define temporary number used for swapping
	int temp;
	for(int i =0;i<n-1; i++)
	{ 
		for (int j=0; j< n-i-1; j++)
		{
			if(*(a+j)>*(a+j+1))
			{
				//Swap
				temp = *(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1) = temp;
			}
		}
	}
}

//Function to sort in descending order
int descending(int *a, int n)
{
        int temp;
        for(int i =0;i<n-1; i++)
        {
                for (int j=0; j< n-i-1; j++)
                {
                        if(*(a+j)<*(a+j+1))
                        {
                                temp = *(a+j);
                                *(a+j)=*(a+j+1);
                                *(a+j+1) = temp;
                        }
                }
        }
}

int main()
{
        //Takes user input
        int n;
	char c;

        printf("Enter number of characters in your sequence: ");
        //Checks for right input made n to be less then 100 just in case
        while(scanf("%d",&n) != 1 || n < 0 || n >=100)
        {
                printf("Wrong input.\nEnter non-negtive number: ");
                while(getchar() != '\n');
        }

        //Define the array size n
        int a[n];

        //Loop trough the array to set the numbers
        for (int i = 0; i <n; i++)
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

	printf("Type 'a' for ascending and 'd' for descending: ");

	//Ask for ascending or descending order
	while(scanf(" %c", &c) != 1 || c != 'a' && c != 'd')
	{
		printf("Wrong input.\nType either 'a' (ascending) and 'd'(descending)): ");
		while(getchar() != '\n');
	}

	//Check wich way to sort
	if (c == 'a')
	{
		//Call the function to sort
		ascending(a, n);
	}
	else if (c == 'd')
	{
		descending(a,n);
	}

	//print the array
	for(int i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

