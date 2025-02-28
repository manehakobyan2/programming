#include <stdio.h>

int main()
{
	int n;
	printf("Enter number of characters in your sequence: ");
	while(scanf("%d",&n) != 1 || n < 0 || n >100)
	{
		printf("Wrong input.\nEnter non-negtive number: ");
		while(getchar() != '\n');
	}
	int a[n];
	int sum = 0;
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

	//Get each number in array
	for(int i=0; i <n; i++)
	{
		//Add the numbers
		sum +=a[i];
	}
	//Print the sum
	printf("The sum of sequence is %d\n", sum);

	return 0;
}
