#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findPeak(int *arr, int n)
{
    if (n == 0)
        return 0; // single element in the array is itself the peak
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            // decreasing
            // go left
            high = mid - 1;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            // increasing
            // go right
            low = mid + 1;
        }
        else
        {
            // go anywhere
            low = mid + 1;
        }
    }
    return -1; // safe return statement - never gets executed
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    // accept the integers
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", findPeak(arr, n));
    return 0;
}