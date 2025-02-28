#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//Seed the number generator
	srand(time(NULL));
	// Assigne the number to generate a number from 1 to 100
	int num1 = rand() % 100 +1;
	//Define variables
	int num2;
	//Make while loop to run till breaking
	while(1)
	{
		//Ask user for input
		printf("Enter your guess(from 1 to 100): ");
		//Check for input to be corrcet
                if(scanf("%d", &num2) != 1)
                {
                printf("Wrong type of guess!\n");
		//break the loop
                return 1;
                }

		//Check the number
		if (num1> num2)
		{ 
			printf("too low\n");
		}
		else if(num1< num2)
		{
			printf("too high\n");
		}
		else
		{
			printf("Correct guess!\n");
			//break the loop
			return 1;
		}
}

return 0;
}
