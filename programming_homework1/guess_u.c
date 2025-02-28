#include <stdio.h>

int main(){
	//Define variables
	int low =1;
	int high =100;
	int guess;
	char c;
	int attempt = 0;
	printf("Think of a number between 1 and 100.\n");

	//Infinite loop till breaking
	while(1)
	{
		//Algorithm for guess
		guess = ((low + high)/2);

		//Ask user if the guess is correct
		printf("Is this your number %d. If it's high type 'h' if low 'l' and if it is correct type 'c'", guess);
	        scanf(" %c", &c);
		//Add the number of attempt to see if it exceeds 7
	        attempt++;	

		//check the input of user
               if (c == 'c'){
                       printf( "I guessed your number in %d attempts. Your number is %d!\n", attempt, guess);
		       return 1;
	       }
		else if (c == 'h')
		{
			//change the high value
			high = guess -1;
		}
		else if (c == 'l')
		{
			//change the low value
			low = guess+1;
		}
	       else
	       {
		       printf("Wrong input.\n");
		       //remove an attempt to not count wrong inputs
		       attempt--;
	        }


	       //if user inputs wrong answers
	       if(high<=low)
	       {
		       printf("No such number\n");
		       return 1;
		}
	}
return 0;
}
