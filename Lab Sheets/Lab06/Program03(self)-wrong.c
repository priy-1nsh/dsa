#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int largestRectagle(int *arr, int n)
{
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        int el = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < el)
            {
                break;
            }
            else
            {
                count++;
            }
        }

        int area = el * count;
        if (area > maxArea)
            maxArea = area;
    }
    return maxArea;
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

    int ans = largestRectagle(arr, n);
    printf("%d", ans);

    return 0;
}