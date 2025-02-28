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
        int b[n];
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

        //Copy each number in array
        for(int i=0; i <n; i++)
        {
		b[i]=a[i];
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i =0, j= n-1; i<n;i++, j--)
	{
		a[i]=b[j];
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}



