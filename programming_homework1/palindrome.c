#include <stdio.h>

int main (){
	//Define variables
        int digit;
        int num1 = 0;
        int num2;
	//Ask for input
        printf("Enter your number here: ");
	//Check for wrong input
        if (scanf("%d", &digit) != 1) {
                printf("Wrong input.\n");
                return 0;
        }
	//Copy the number
	num2 = digit;
        //reverse the number
        while (digit != 0){
                num1 = num1*10 +digit%10;
                digit= digit /10;
        }
	//Check if reverse is equal to the input
	if (num1==num2){
		printf("Your number is palindrome.\n");}

	else{printf("Not palindrome. \n");}

return 0;
}

