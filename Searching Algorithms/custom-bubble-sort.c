#include <stdio.h>
#include <stdlib.h>

// bubble sort usual
// i : 0 -> n-2
// j : 0 -> n-2-i

// bubble sort custom
// bubbleSort(arr, low, high)
// i : low -> high-1
// j : low -> high-1-(i-low)

// if u want to sort an array from a given low to a given high - you can use
// mergeSort as well - mergeSort(arr, n, low, high);

void bubbleSort(int *arr, int low, int high)
{
    for (int i = low; i <= high - 1; i++)
    {
        // optimized - didSwap
        int didSwap = 0;
        for (int j = low; j <= high - 1 - (i - low); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                didSwap = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (didSwap == 0)
            break;
    }
}

int main()
{

    return 0;
}