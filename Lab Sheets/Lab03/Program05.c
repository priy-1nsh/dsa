#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// find the first and the last occurence
int findFirstOccurence(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            first = mid;
            // go left
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            // go right
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int findLastOccurence(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            last = mid;
            // for the last occurence, go right
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            // go left
            high = mid - 1;
        }
        else
        {
            // go right
            low = mid + 1;
        }
    }
    return last;
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

    int first = findFirstOccurence(arr, n, target);
    int last = findLastOccurence(arr, n, target);

    printf("%d %d", first, last);

    return 0;
}