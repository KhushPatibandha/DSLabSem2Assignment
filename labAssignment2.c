// Question-1 Write a program to assign memory locations using malloc function for an int array on n elements. Print address of each element and value.

#include<stdlib.h>
#include<stdio.h>
int main(void)
{
    int n;
    printf("Enter the size of your array");
    scanf("%i", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    printf("\nenter the %i elements of array: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }
    printf("The array elements are : \n");
    for(int i = 0; i < n; i++)
    {
        printf("Address of element %i : %p, value : %i \n", i, &arr[i], arr[i]);
    }
    free(arr);
    return 0;
}


// Question-2 Write a program to assign memory locations using malloc and calloc function for an int array and char of n elements. Print address of each element and value. Free the memory in end.

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n;
    printf("Enter the size of your array: \n");
    scanf("%i", &n);
    int *int_arr = (int*) malloc(n * sizeof(int));
    char *char_arr = (char*) calloc(n, sizeof(char));

    printf("Enter the elements of integer array: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%i", &int_arr[i]);
    }
    printf("Enter the elements of character array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%c", &char_arr[i]);
    }
    printf("The integer array elements are: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Address of element %i: %p, value: %i \n", i, &int_arr[i], int_arr[i]);
    }
    printf("The character array elements are: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Address of element %i: %p, value, %c \n", i, &char_arr[i], char_arr[i]);
    }
    free(int_arr);
    free(char_arr);
    return 0;
}


// Question-3 Write a program to assign memory locations using calloc function for an int array. Ask new array size from users and use realloc to change the allocated memory size of the same int array. Print address if each element and value. Free the memory in end.

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n;
    printf("Enter the initial size of your array \n");
    scanf("%i", &n);

    int *int_arr = (int*) calloc(n, sizeof(int));
    printf("Enter the elements of the integer array: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%i", &int_arr[i]);
    }
    printf("The origianl integer array elements are: \n");

    for(int i = 0; i < n; i++)
    {
        printf("Address of element %i: %p, value: %i\
        n", i, &int_arr[i], int_arr[i]);
    }
    int changed_size;
    printf("\nEnter the new size of the array \n");
    scanf("%i", &changed_size);
    int_arr = (int*) realloc(int_arr, changed_size * sizeof(int));
    printf("Enter the changed elements of the integer array: \n");

    for(int i = n; i < changed_size; i++)
    {
        scanf("%i", &int_arr[i]);
    }
    printf("The resized integer array elements are: \n");
    for(int i = 0; i < changed_size; i++)
    {
        printf("Address of element %i: %p, value: %i \n", i, &int_arr[i],int_arr[i]);
    }
    free(int_arr);
    return 0;
}