#include <stdio.h>
#include <string.h>

int main()
{
	char s_1[100], s_2[100];
	printf("Enter first word: ");
	fgets(s_1, sizeof(s_1), stdin);

	printf("Enter second  word: ");
        fgets(s_2, sizeof(s_1), stdin);
	s_1[strcspn(s_1, "\n")] =0;
	s_2[strcspn(s_2, "\n")] =0;


	if(strstr(s_1, s_2) != NULL || strstr(s_2, s_1) != NULL)
	{
		printf("\"%s\" and \"%s\" are anagrams.\n", s_1, s_2);
	}
	else
	{
		printf("\"%s\" and \"%s\" are not anagrams.\n", s_1, s_2);
	}
	return 0;
}


