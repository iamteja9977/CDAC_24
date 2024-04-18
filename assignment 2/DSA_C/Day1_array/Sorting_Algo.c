/*
selectionSort(array, size)
  repeat (size - 1) times
  set the first unsorted element as the minimum
  for each of the unsorted elements
    if element < currentMinimum
      set element as new minimum
  swap minimum with first unsorted position
end selectionSort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef NUM
#define NUM 10
#endif

void selectionSort(int *arr, int);
void bubbleSort(int *arr, int);
void insertionSort(int *, int);

void printArr(int *, int);
void fillArr(int *, int);

void main()
{
    // using random number function to store values randomly.
    srand(time(NULL));
    int arr[NUM];
    fillArr(arr, NUM);
    printf("Before sorting:\n");
    printArr(arr, NUM);

    // selectionSort(arr, NUM);
    // bubbleSort(arr, NUM);
    insertionSort(arr, NUM);
    printf("After sorting:\n");
    printArr(arr, NUM);
}

void selectionSort(int *arr, int size)
{
    printf("Inside selection sort function...\n");
    int i, j, min;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < size - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min != i)
        {
            // swap(arr[min_idx], arr[i]);
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    printf("Exiting selection sort function!\n");
}
// -----------------------------------------------------------------------------------------------------
void bubbleSort(int *arr, int size)
{
    printf("Inside bubble sort function...\n");
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Exiting bubble sort function!\n");
}
//-----------------------------------------------------------------------------------------------------
void insertionSort(int *arr, int size)
{
    printf("Inside insertion sort function...\n");

    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("Exiting insertion sort function!\n");
}
// -----------------------------------------------------------------------------------
void printArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillArr(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % (NUM * 10);
    }
}
