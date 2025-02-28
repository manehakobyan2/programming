#include <stdio.h>

int main(){
 //define variables
 double num1, num2, num3;
 char charachter;
//Ask user for input
 printf("Enter expression here(e.g. 1+1): ");
 scanf("%lf %c %lf", &num1, &charachter, &num2);
 
 // Use switch for  the characters
 switch(charachter){

	 case'+':
		 //Caclulate the input
		 num3= num1+num2;
		 //Print the result
		 printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num3);
		 //Break from the switch
		 break;
	case '-':
		 num3= num1-num2;
		 printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num3);
                 break;
	case'*':
		 num3= num1*num2;
		 printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num3);
                 break;
	case '/':
		 //Handeling the case of division by 0
		 if (num2==0){
			 printf("Math Error\n");
			 break;
		 }
		 else{
			 num3= num1/num2;
                         printf("%.2lf /  %.2lf = %.2lf\n", num1, num2, num3);
                         break;
                 }

        // Set default action
	default:
		 printf("Wrong input.\n");
 }
 return 0;
}
