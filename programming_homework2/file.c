#include <stdio.h>
#include <stdlib.h>

//Define filec own  file for c program 
#define filec "file.c"

int main()
{
	//Open the file for reading 
	FILE *file = fopen(filec, "r");
	//check for the value of pointer 
	if (file == NULL)
	{
		printf("Error could not open file\n");
		return 1;
	}
	//Define variables for raw column and charcter
	int row = 1;
	int col = 0;
	char ch;
	//Print the header
	printf("Locations of '{' or '}' in %s\n", filec);
	printf("Character | Line | Column\n");
	printf("-------------------------\n");

	//Read the file character by character
	while((ch=fgetc(file)) != EOF)
	{
		//Add the column
		col++;
		//Chceck for character
		if (ch == '{' || ch == '}')
		{
			printf("     %c     |  %d   |    %d   \n", ch, row, col);
		}
		//If line has ended add number to row and make column 0
		if (ch =='\n')
		{
			row++;
			col = 0;
		}
	}
	//close the file
	fclose(file);
	//Exit program 
	return 0;
}

