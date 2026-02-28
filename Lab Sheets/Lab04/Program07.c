#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// kth missing number
int kMissingNumber(int *arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1); // number of missing numbers =
        // number available - what should have been there starting from 1
        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return k + high + 1; // or low + k
}

int main()
{

    return 0;
}