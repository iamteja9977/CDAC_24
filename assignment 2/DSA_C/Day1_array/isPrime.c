// if not prime assign "0" to it.
#include <stdio.h>
#include <math.h>

// preprocessor directives that can be set by CLI
#ifndef NUM
#define NUM 10
#endif

void printArr(int *, int);
void fillArr(int *, int);
int isPrime(int);
void processArr(int *arr, int size);

int main()
{
    int arr[NUM] = {0}; // partial initialization
    printArr(arr, NUM);
    printf("Enter the first value:");
    scanf("%d", &arr[0]);
    fillArr(arr, NUM);
    printf("Udated array :");
    printArr(arr, NUM);

    // retain only prime numbers in that array:
    printf("Retaining only prime numbers:");
    processArr(arr, NUM);
    printArr(arr, NUM);
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

int isPrime(int num)
{
    int sq_rt = sqrt(num);

    if (num == 1 || num == 0)
    {
        return 0;
    }
    for (int i = 2; i <= sq_rt; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void processArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]) == 0)
        {
            arr[i] = 0;
        }
    }
}
