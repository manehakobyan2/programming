#include <stdio.h>

int main ()
{       // Define variables
        int n, m;
	char ch;
        //Ask for input
        printf("Enter your height, width and symbol  here (i.e. 2 3 $): ");
        //Check the input
        if (scanf("%d %d %c", &n, &m, &ch) != 3 || n< 0 || m<0){
                printf("Wrong input.\n");
                return 1;
        }
	for (int i=0; i<n; i++)
	{      
		for(int j = 0; j<m; j++){
			if (i ==0 || i== n-1 || j ==0 ||j ==m-1)
			{
			printf("%c", ch);}
			else{
				printf(" ");}
		}
		printf("\n");
	}
return 0;
}

