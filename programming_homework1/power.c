#include <stdio.h>

int main (){
	//Define variable
        int num1;
	//Ask input
        printf("Enter your number here: ");
	//Check for wrong input
        if (scanf("%d", &num1) != 1|| num1<0) 
       	{       printf("Wrong input or negative number(not power of 2).\n");
                return 0;
       	}
	//Use the loop to devide number
        while (num1 != 0)
	{

		if ((num1 % 2) != 0 && num1 != 1)
		{
			printf("Not power of 2.\n");
			break;
		}
		else if( num1 == 1){
	                 printf("Your number is power of 2.\n");}
		num1= num1/2;

        }
	return 0;
}
