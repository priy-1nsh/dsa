#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// search in rotated sorted array - 1
int search(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        // identify the sorted half
        // left half sorted
        if (arr[low] <= arr[mid])
        {
            // lie in the sorted part
            if (arr[low] <= target && target <= arr[mid])
            {
                // eliminate right half
                high = mid - 1;
            }
            else
            {
                // doesn't lie in the sorted left half
                // eliminate left half
                low = mid + 1;
            }
        }
        else
        {
            // right half sorted
            // if target lies in this sorted half
            if (arr[mid] <= target && target <= arr[high])
            {
                // eliminate left half
                low = mid + 1;
            }
            else
            {
                // doesn't lie in this sorted half
                // eliminate the right, go left
                high = mid - 1;
            }
        }
    }
    return -1; // if target doesn't exist
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int ans = search(arr, n, target);

    printf("%d", ans);

    return 0;
}