#include <stdio.h>
#include <string.h>

int main()
{
	//Define size of string
	char str[100];
	//Ask user for input
	printf("Enter your string: ");
	scanf("%s", str);

	//set pointer start to start of string
	char *start = str;
	//end to end of the string
        char *end = strlen(str)-1 + str;
        char temp;
	//Do the reversing
        while(end > start)
        {
                temp = *start;
                *start = *end;
                *end = temp;
                start++;
                end--;
        }
	//print the reversed string
	printf("Reversed string: %s\n", str);

	return 0;
}
