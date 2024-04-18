// C Program to Reverse an Array by Printing it from The Last Element to the First Element

#include <stdio.h>
#define N 100

int main() {
    int arr[N];

    int n;
    // Inputting the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Inputting the array
    printf("Enter an array: ");
    for (int i = 0; i< n; i++){
        scanf("%d", &arr[i]);
    }

    // Printing the reverse of the array
    printf("Reversed array: ");
    for (int i = n-1; i>=0; i--){
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
#include <stdio.h>
#define N 1000

void reverse(int *arr, int l, int r){
    if(l < r){
        int temp;
        temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        reverse(arr, l + 1, r - 1);
    }
}

int main()
{
    int arr[N];

    int n;
    // Inputting the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Inputting the array
    printf("Enter an array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Reversing the array by swapping using a recursive function
    reverse(arr, 0, n-1);

    // Printing the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
*/

