#include <stdio.h>
#include <stdlib.h>

int largestRectangle(int *arr, int n)
{
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int height = arr[i];

        int left = i;
        int right = i;

        // expand left
        while (left - 1 >= 0 && arr[left - 1] >= height)
        {
            left--;
        }

        // expand right
        while (right + 1 < n && arr[right + 1] >= height)
        {
            right++;
        }

        int width = right - left + 1;
        int area = height * width;

        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int ans = largestRectangle(arr, n);
    printf("%d\n", ans);

    free(arr);
    return 0;
}
