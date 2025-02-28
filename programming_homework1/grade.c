#include <stdio.h>

int main ()
{
	//Define variables
	double grade;
	
	while(grade != -1){
		//Ask user for input
		printf("Enter your grade(if you want to escape type -1): ");
		//Check if the input is correct
		 if(scanf("%lf",&grade) != 1)
                {
                        printf("Wrong input. \n");
                        while (getchar() != '\n');
			continue;
                }

                //Check if the user wants to stop
		if (grade == -1){break;}
                //Check the grade
		if (grade >100 || grade<0){
			printf("Invalid grade. Please enter valid  number\n");
			continue;}
		else if(grade<=60){
			printf("You got a F :( \n");}
		else if(grade<=70){
                        printf("You got a D.\n");}
		else if (grade < 80){
			printf("You got a C\n");}
		else if (grade<90){
			printf("You got a B\n");}
		else{
			printf("You got an A :)\n");}
	}	
	
	return 0;
}
