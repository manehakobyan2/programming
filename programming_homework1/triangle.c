#include <stdio.h>

int main(){
	int n;

	//Ask user for input
	printf("Enter the height of triangle: ");
	if (scanf("%d", &n) != 1 || n < 0){
		printf("Wrong input\n");}
        for (int i =0; i<n; i++)
	{
		for(int j=0; j<i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for (int i =0; i<n; i++)
        {
                for(int j=n; j>i+1; j--)
                {
                        printf(" ");
                }
		for(int j=0; j<i+1; j++)
                {
                        printf("*");
                }

                printf("\n");
        }


return 0;
}
