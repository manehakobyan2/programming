#include <stdio.h>

// function takes input the pointer of array and size
int increase(int *a, int n)
{
	//Loops trough to get if its in ascending order
	 for (int i=0; i <n-1; i++)
        {
                if(*(a+i)<=*(a+i+1))
                {
                        continue;
                }
                else
                {
                        return 1;
                }
        }
	return 0;
}

//Same for this just decreasing
int decrease(int *a,int n)
{
	for (int i=0; i <n-1; i++)
        {
                if(*(a+i)>=*(a+i+1))
                {
                        continue;
                }
                else
                {
                        return 1;
                }
        }
        return 0;
}



int main()
{
	//Takes user input
        int n;

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

	//Check if any of the functions returned 0
        if (decrease(a, n) == 0 || increase(a, n) == 0)//Pass first character  and size
	{
		printf("Yes.\n");
	}
	else 
	{
		printf("No.\n");
	}
	return 0;
}




