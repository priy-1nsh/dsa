#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// function prototypes at the top
void mergeSort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);

// merge sort in C - O(NlogN)
void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge(int *arr, int low, int mid, int high)
{
    int left = low;            // eg. 2
    int right = mid + 1;       // eg. 4
    int size = high - low + 1; // 2, 3, 4 = 3 items so (4 - 2 + 1)
    int temp[size];
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k] = arr[left];
            left++;
            k++;
        }
        else
        {
            temp[k] = arr[right];
            k++;
            right++;
        }
    }

    while (left <= mid)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }

    while (right <= high)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }

    // copy temp into arr
    for (int i = low, k = 0; i <= high; i++, k++)
    {
        // copy temp from 0 to whatever into arr from low to high
        arr[i] = temp[k];
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

    mergeSort(arr, 0, n - 1);
}