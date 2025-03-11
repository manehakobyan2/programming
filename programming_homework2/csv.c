#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//Open the file 
	FILE *file = fopen("currency.csv", "r");
	//Check if the file exists
	if (file == NULL)
	{
		printf("Error: could not open the file\n");
		return 1;
	}
	//take input from user
	int n;
	printf("Enter column number: ");
	//check the input
	while(scanf("%d", &n) != 1)
	{
		printf("Wrong input.\n");
		while(getchar() != '\n');
	}
	//Take input for search value
	char str[100];
	printf("Search value: ");
	scanf("%s", str);
	//Define array for line
	char line[1024];
	//print the header of the file
	if(fgets(line, sizeof(line), file))
	{
		printf("%s\n", line);
	}
	//if there is nothing print empty file
	else
	{
		printf("Empty file.");
		fclose(file);
		return 1;
	}
	//Read every row
	while(fgets(line, sizeof(line), file))
	{
		//Set a count for number of columns
		int count = 1;
		//make a copy of the line for printing later
		char *copy=strdup(line);
		//get first column
		char *token = strtok(line, ",\n");
		//iterate trough colums
		while(token != NULL)
		{
			//if the column is the same as user's
			if(count == n)
			{
				//check for a match with search value
				if(strcmp(token, str) == 0)
				{
					printf("%s\n", copy);
				}
			}
			//change it to next value
			token = strtok(NULL, ",\n");
			//move to next column
			count++;
		}
	}

	//close the file
	fclose(file);
	printf("If the line is empty means there are no matches.\n");
	//exit
	return 0;
}
