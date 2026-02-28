#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int upperBound(int *arr, int n, int target)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int getSmallerEquals(int **mat, int r, int c, int x)
{
    // finding the no. of numbers less than or equal to x
    // in each row
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        count += upperBound(mat[i], c, x);
    }
    return count;
}

int findMiddleScore(int **mat, int r, int c)
{
    // find the low and high
    // low - minimum elt. in the first column j = 1
    // high - maximum elt. in the m-1 column j = m - 1
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        if (mat[i][1] < low)
        {
            low = mat[i][1];
        }
        if (mat[i][c - 1] > high)
        {
            high = mat[i][c - 1];
        }
    }

    int req = r * c / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallerEquals = getSmallerEquals(mat, r, c, mid);
        if (smallerEquals <= req)
        {
            // go right
            low = mid + 1;
        }
        else
        {
            // we want the first number greater than req - that will be the middle element
            high = mid - 1;
        }
    }
    return low;
}

int main()
{

    int r, c;
    scanf("%d %d", &r, &c);

    int **mat = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        mat[i] = (int *)malloc(c * sizeof(int));
    }

    // get the values
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int ans = findMiddleScore(mat, r, c);

    printf("%d", ans);

    // freeing the memory used
    for (int i = 0; i < r; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}