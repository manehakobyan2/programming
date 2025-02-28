#include <stdio.h>
//Adding for toupper and tolower functions
#include <ctype.h>

int main()
{
	//Getting a string
	char s[100];
	printf("Enter your text here: ");
	fgets(s, sizeof(s), stdin);
	
	//Asking for lower or upper case
	int choice;
	printf("Choose an option.\n1.Convert uppercase.\n2.Convert lowercase.\nEnter: ");

	//Asking for input 
	while(scanf("%d", &choice) != 1 || choice != 1 && choice != 2)
	{
		printf("Wrong input.\nEnter valid iput(1 or 2): ");
		while(getchar() != '\n');//clearing
	}
	//Check for choice
	if(choice == 1)
	{
		//convert each to uppercase
		for (int i =0; s[i] != '\0';i++)
		{
			s[i] = toupper(s[i]);
		}
	}
	else 
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			//convert each to lower
			s[i]=tolower(s[i]);
		}
	}
	//Print the string
	printf("%s\n", s);
	return 0;
}
