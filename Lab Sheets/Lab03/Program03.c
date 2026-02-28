#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// koko eating bananas

// function to find the maximum element of the array
int findMax(int *arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

// function to calculate totalHours based on speed
int getTotalHours(int *arr, int n, int bananasPerHour)
{
    int totalHours = 0;
    for (int i = 0; i < n; i++)
    {
        totalHours += (int)ceil((double)arr[i] / (double)bananasPerHour);
    }
    return totalHours;
}

// binary search on arr to get min k
int minimumEatingSpeed(int *arr, int h, int n)
{
    int low = 1, high = findMax(arr, n);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalHours = getTotalHours(arr, n, mid);

        if (totalHours <= h)
        {
            // good
            // move even left to get smaller speed
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    int n, h;
    scanf("%d %d", &n, &h);

    int *piles = (int *)malloc(n * sizeof(int));

    // take user input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &piles[i]);
    }

    int ans = minimumEatingSpeed(piles, h, n);

    printf("%d", ans);

    return 0;
}