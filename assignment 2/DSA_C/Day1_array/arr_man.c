// array manipulation
#include <stdio.h>
// preprocessor directives that can be set by CLI
#ifndef NUM
#define NUM 5
#endif

void printArr(int *, int);
void fillArr(int *, int);

int main()
{
    int arr[NUM] = {0}; // partial initialization
    printArr(arr, NUM);
    printf("\nEnter the number from where your new array starts: ");
    scanf("%d", &arr[0]);
    fillArr(arr, NUM);
    printArr(arr, NUM);
     printf("\n");
}

void fillArr(int *arr, int size)
{
int i;
    for (i = 1; i < size; ++i)
    {
        arr[i] = arr[0] + i;
    }
   
}

void printArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
