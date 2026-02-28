#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (didSwap == 0)
            break;
    }
}

void zigzagSort(int *arr, int n)
{
    int K = 1;     // condn - K++
    int front = 1; // condn - front = -front
    int i = 0;
    int j = n;
    while ((i + K) <= j && (j - K) >= i)
    {
        if (front == 1)
        {
            // sort from front
            bubbleSort(arr, i, i + K - 1);
            i = i + K;
        }
        else if (front == -1)
        {
            bubbleSort(arr, j - K, j - 1);
            j = j - K;
        }
        K++;
        front = -front;
    }
    if (j - K < i || i + K > j)
        bubbleSort(arr, i, j - 1);
}

int main()
{

    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // get the numbers in the array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    zigzagSort(arr, n);

    // print array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}