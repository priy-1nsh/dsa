#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// bitwise strength sort

// function to calculate the strength
int strength(int num)
{
    int strength = 0;
    while (num > 0)
    {
        strength += (num % 2);
        num = num / 2;
    }
    return strength;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// bubble sort modified to sort the arr
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didSwap = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strength(arr[j]) < strength(arr[j + 1]))
            {
                swap(&arr[j], &arr[j + 1]);
                didSwap = 1;
            }
            else if ((strength(arr[j]) == strength(arr[j + 1])) && arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    // unique integers
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    // print the array sorted
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}