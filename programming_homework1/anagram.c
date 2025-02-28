#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Convert both strings to lowercase
    for (char *p = str1; *p; p++) *p = tolower(*p);
    for (char *p = str2; *p; p++) *p = tolower(*p);

    // If lengths are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        printf("The strings are NOT anagrams.\n");
        return 0;
    }

    // Sort both strings using pointers (Bubble Sort)
    int len = strlen(str1);
    for (char *i = str1; i < str1 + len - 1; i++) {
        for (char *j = i + 1; j < str1 + len; j++) {
            if (*i > *j) {
                swap(i, j);
            }
        }
    }
    
    for (char *i = str2; i < str2 + len - 1; i++) {
        for (char *j = i + 1; j < str2 + len; j++) {
            if (*i > *j) {
                swap(i, j);
            }
        }
    }

    // Compare sorted strings
    if (strcmp(str1, str2) == 0) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are NOT anagrams.\n");
    }

    return 0;
}
	

