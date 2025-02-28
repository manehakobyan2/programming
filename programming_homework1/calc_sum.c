#include <stdio.h>

int main(){
	//Define variables
	int N;
	int sum =0;
        //Ask input
	printf("Enter your number: ");
	//Scan and check if the input is integer
	if(scanf("%d",&N) !=1 || N<1 || N> 1000)
	{printf("Please input a number between 1 and 1000.\n");
	return 1;}
        // Repeat till the i is less greater then N
	for (int i = 0; i<N; i++)
	{
		//Check if the number is divisable by 3 or 5
		if(i%3 == 0 || i%5==0)
		{
			sum = sum + i;
		}
	}
	printf("%d\n", sum);
	return 0;
        	
}
