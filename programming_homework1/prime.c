#include <stdio.h>

int main ()
{       // Define variables
	int n;
	//Ask for input
	printf("Enter your number here: ");
	//Check the input
	if (scanf("%d", &n) != 1){
		printf("Wrong input.\n");
		return 1;
	}
	//If the number is negative change to positive
	if (n<0){n = -n;}
	//Check for corner cases
        if(n<=2){printf("Not prime\n");}

	//Devide the numer get the answer
	for(int i = 2; i<n; i++){
		if(n%i==0)
		{
			printf("Not prime\n");
			break;
		}
                else if(i == n-1 && n%i != 0)
		{
			printf("Prime!\n");
		}
	}
         
	return 0;
}
