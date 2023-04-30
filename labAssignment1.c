// Dear students,

// Write programs in C to understand working of pointers. Call by Value and Call by Reference. 
// a) Write a  program to swap values of two variables using call by value.
// b) Write a  program to swap values of two variables using call by reference.
// c) Write a  program with a function that modified some values of an array.  Print the entire array from function and main function for comparision. Find out if array is called by value or call reference by default.
// d) Write a  program to swap equal length array values of two variables using call by value.
// e) Write a  program to swap equal length array values of two variables using call by reference.


// a) Write a  program to swap values of two variables using call by value
    // #include<stdio.h>
    // void swap(int x, int y)
    // {
    //     int temp = x;
    //     x = y;
    //     y = temp;

    //     printf("The new value of x is %i \n", x);
    //     printf("The new value of y is %i \n", y);
    // }
    // int main(void)
    // {
    //     int x, y;
    //     printf("Enter the value of x and y \n");
    //     scanf("%i%i", &x, &y);

    //     printf("Original value of x is %i \n", x);
    //     printf("Original value of y is %i \n", y);

    //     swap(x, y);
    //     return 0;
    // }


// b) Write a  program to swap values of two variables using call by reference.
// #include<stdio.h>
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main(void)
// {
//     int a, b;

//     printf("Enter value of a and b : \n");
//     scanf("%i%i", &a, &b);

//     printf("The original value of a is %i \n", a);
//     printf("The original value of b is %i \n", b);

//     swap(&a, &b);

//     printf("The new value of a is %i \n", a);
//     printf("The new value of b is %i \n", b);
//     return 0;
// }


// c) Write a  program with a function that modified some values of an array.
// #include<stdio.h>
// void modify(int arr[], int n)
// {
//     printf("Array inside modify() function: \n");
//     for(int i = 0; i < n; i++)
//     {
//         arr[i] *= 2;
//         printf("%2d ", arr[i]);
//     }
//     printf("\n");
// }
// int main(void)
// {
//     int n;
//     printf("Enter the size of the array: \n");
//     scanf("%i", &n);
//     int arr[n];
//     printf("Enter the elements of the array: \n");
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%i", &arr[i]);
//     }
//     printf("Array before modification : \n");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", arr[i]);
//     }
//     printf("\n");
//     modify(arr, n);
//     printf("Array after modification : \n");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", arr[i]);
//     }
//     return 0;
// }


// d) Write a  program to swap equal length array values of two variables using call by value.
// #include<stdio.h>
// #include<math.h>
// struct arr
// {
//     int arr1[5];
//     int arr2[5];
// };

// void swapArray(struct arr x, int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         int temp = x.arr1[i];
//         x.arr1[i] = x.arr2[i];
//         x.arr2[i] = temp;
//     }
//     printf("Elements after swap is swapArray() function \n");
//     printf("Array 1: ");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", x.arr1[i]);
//     }
//     printf("\n");
//     printf("Array 2 : ");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", x.arr2[i]);
//     }
// }

// int main(void)
// {
//     int n = 5;
//     struct arr x;
//     for(int i = 0; i < n; i++)
//     {
//         x.arr1[i] = i;
//         x.arr2[i] = (i * 10);
//     }
//     printf("\n");
//     printf("Element before swap in main function : \n");
//     printf("Array 1 : ");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", x.arr1[i]);
//     }
//     printf("\n");
//     printf("Array 2 : ");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", x.arr2[i]);
//     }
//     printf("\n");
//     swapArray(x, n);
//     printf("\n");
//     printf("Elements after swap in main function : \n");
//     printf("Array 1 : ");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", x.arr1[i]);
//     }
//     printf("\n");
//     printf("Array 2 : ");
//     for(int i = 0; i < n; i++)
//     {
//         printf("%i ", x.arr2[i]);
//     }
//     printf("\n");
//     return 0;
// }


// e) Write a  program to swap equal length array values of two variables using call by reference.
#include<stdio.h>
void swapArray(int arr1[], int arr2[], int n)
{
    if(n == 0)
    {
        return;
    }
    int temp = arr1[0];
    arr1[0] = arr2[0];
    arr2[0] = temp;

    swapArray(arr1 + 1, arr2 + 1, n - 1);
}
int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {11, 13, 15, 17, 19, 21, 23, 25, 27, 29};

    int n = sizeof(arr1)/ sizeof(arr1[0]);
    swapArray(arr1, arr2, n);

    printf("Array 1 : ");
    for(int i = 0; i < n; i++)
    {
        printf("%4i ", arr1[i]);
    }
    printf("\n");
    printf("Array 2 : ");
    for(int i = 0; i < n; i++)
    {
        printf("%2i ", arr2[i]);
    }
    printf("\n");
    return 0;
}