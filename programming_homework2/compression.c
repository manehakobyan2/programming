#include <stdio.h>
#include <string.h>

int main()
{
	//Define variables
	//input string
	char str[]= "aaabbcccc";
	//lenght of the string
	int lenght = strlen(str);
	//placeholder for character
	char ch;
	//n for counting the repitition
	int n= 0;
	//m for placement
	int m = 0;
	//new compressed string
	char new[100];
	//for placement inside the array
	int num=0;

	while(lenght > m)
	{
		//set first character
		ch = str[m];
		//check for match
		while(lenght>m && str[m] ==ch)
		{
			m++;
			n++;
		}
		//write the current character
		new[num++] = ch;
		//Write the count only if its greater then one
		if(n>1)
		{
			num += sprintf(&new[num], "%d", n);
		}
		//set n = 0 for other character
		n = 0;
	}
	//print the strings
	printf("%s\n%s\n",str, new);

	//exit pogram 
	return 0;
}
