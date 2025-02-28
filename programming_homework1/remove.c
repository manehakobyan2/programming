#include <stdio.h>

int main()
{
	int a[10];
	int n;
	printf("Enter your array here(10 digits)\n");

	//Go trough each number of array
	for (int i = 0; i <10; i++)
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
	
	//Ask for the number they needs to be eliminated
	printf("Which number you would like to eliminate? ");
	while(scanf("%d", &n) != 1)
	{
		printf("Wrong input. Please enter an integer: ");
		while(getchar() != '\n');
	}

	//get one variable to see if match was detcted
	int t=0;
	for(int i = 0; i<10; i++)
	{
		if(a[i]==n && t ==0)
		{
			//if match detected variable is changed to 1
			t++;
		}
		//move left
		if(t==1)
		{
			a[i]=a[i+1];
		}

		//print last as 0 and if match detected
		if(t==1)
		{
			printf("%d ",(i == 9) ? 0: a[i]);
		}
		else
		{
			printf("%d ",a[i]);
		}
	}
	//Should set the last digit to 0 after the loop ends
	//However I didnt want to write second loop for printing so I'll print it then changed it
	if(t==1)
	{a[9]=0;}
	printf("\n");
return 0;
}
