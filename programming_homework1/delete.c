#include <stdio.h>
#include <stdlib.h>

int main()
{
        //Takes user input
        int n, m;

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

	printf("Enter the position you want to delte: ");
        //Checks for right input made n to be less then 100 just in case
        while(scanf("%d",&m) != 1 || m < 0 || m-1 >n)
        {
                printf("Wrong input.\nEnter correct poition: ");
                while(getchar() != '\n');
        }
	int t=0;
        for(int i = 0; i<n-1; i++)
        {
                if(a[i]==m && t ==0)
                {
                        //if match detected variable is changed to 1
                        t++;
                }
                //move left
                if(t==1)
                {
                        a[i]=a[i+1];
                }

                //Don't print the last as 0 and if match detected
                if(t==1)
                {
                        printf("%d ",a[i]);
                }
                else
                {
                        printf("%d ",a[i]);
                }
        }
        //However I didnt want to write second loop for printing so I'll print it then changed the size
        if(t==1)
	{n--;}
        printf("\n");
return 0;
}
