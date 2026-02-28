// group-sorting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int *arr, int n, int low, int high);
int calcHighIndex(int *arr, int n, int currentIValue, int stepsK);
void groupSort(int *arr, int n);

void bubbleSort(int *arr, int n, int low, int high)
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

int calcHighIndex(int *arr, int n, int currentIValue, int stepsK)
{
    if (currentIValue + stepsK - 1 > n - 1)
        return n - 1;
    return currentIValue + stepsK - 1;
}

void groupSort(int *arr, int n)
{
    int i = 0;
    int k = 1; // steps
    while (i < n)
    {
        // gotta sort chunks of size k each time and move i to highIndex + 1
        int highIndex = calcHighIndex(arr, n, i, k);
        bubbleSort(arr, n, i, highIndex);
        i = highIndex + 1;
        k++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    groupSort(arr, n);

    // print array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}