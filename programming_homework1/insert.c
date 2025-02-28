#include <stdio.h>
#include <stdlib.h>

// Function to insert at the beginning
void insertAtBeginning(int **arr, int *n, int k) {
    *n += 1;
    *arr = realloc(*arr, (*n) * sizeof(int));

    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Shift elements to the right
    for (int i = *n - 1; i > 0; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    // Insert K at index 0
    (*arr)[0] = k;
}

// Function to insert at the end
void insertAtEnd(int **arr, int *n, int k) {
    *n += 1;
    *arr = realloc(*arr, (*n) * sizeof(int));

    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Insert K at the last position
    (*arr)[*n - 1] = k;
}

// Function to insert at M-th position (1-based index)
void insertAtMthPosition(int **arr, int *n, int k, int m) {
    if (m < 1 || m > *n + 1) {
        printf("Invalid position!\n");
        return;
    }

    *n += 1;
    *arr = realloc(*arr, (*n) * sizeof(int));

    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Shift elements to the right from M-1 index
    for (int i = *n - 1; i >= m; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    // Insert K at M-1 index
    (*arr)[m - 1] = k;
}

int main() {
    int n, k, m, choice;

    // Get the number of elements
    printf("Enter the number of elements: ");

    while(scanf("%d", &n)!= 1 || n < 0)
    {
	    printf("Wrong input.\nEnter non-negative integer: ");
	    while(getchar() != '\n');
    }

    // Allocate memory dynamically
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements
    for (int i = 0; i <n; i++)
    {
	    //Ask for input and check
            printf("Enter digit %d: ", i+1);
            while(scanf("%d", &arr[i])!= 1)
            {
		    printf("Wrong input.\n");
                    printf("Enter digit %d: ", i+1);
                    while(getchar() != '\n');
            }
     }


    // Get the number to insert
    printf("Enter the number to insert: ");
    while(scanf("%d", &k) != 1)
{
printf("Wrong input.\nEnter a valid number: ");
while(getchar() != '\n');
}

    // Get the operation choice
    printf("Choose insertion method:\n");
    printf("1 - Insert at Beginning\n");
    printf("2 - Insert at End\n");
    printf("3 - Insert at M-th Position\n");

    while(scanf("%d", &choice) !=1)
{ 
	printf("Wrong input.\nEnter an integer.");
	while(getchar() != '\n');
}

    if (choice == 1) {
        insertAtBeginning(&arr, &n, k);
    } else if (choice == 2) {
        insertAtEnd(&arr, &n, k);
    } else if (choice == 3) {
        printf("Enter the position (1-based index): ");
        scanf("%d", &m);
        insertAtMthPosition(&arr, &n, k, m);
    } else {
        printf("Invalid choice!\n");
    }

    // Print updated array
    printf("Updated sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
