#include <stdio.h>

int main(){
	//Define varibles
	int num1;
	int num2 = 0;
	//Ask for input
	printf("Enter your input: ");
	if(scanf("%d", &num1) != 1){
		printf("Wrong input.\n");
		return 0;
	}
	if (num1 < 0){
		num1 = -num1;}

	while(num1 != 0)
	{
		num2= num2 + num1%10;
		num1= num1/10;
	}
	printf("This is the sum of your digits %d\n", num2);
	return 0;
}
