#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pair
{
    int index;
    int value;
} Pair;

// merge function
void merge(Pair *arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int size = high - low + 1;
    Pair temp[size];

    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left].value <= arr[right].value)
        {
            temp[k] = arr[left];
            k++;
            left++;
        }
        else
        {
            temp[k] = arr[right];
            right++;
            k++;
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
        arr[i] = temp[k];
    }
}

// merge sort algorithm to sort the given array for pairs based on value
void mergeSort(Pair *arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

// void findPair
void findPair(int *arr, int n, int k)
{
    // make an array of pairs
    Pair *pairArr = (Pair *)malloc(n * sizeof(Pair));

    // store values alongwith the index of the array
    for (int i = 0; i < n; i++)
    {
        pairArr[i].index = i;
        pairArr[i].value = arr[i];
    }

    // apply merge sort on this array of Pairs
    mergeSort(pairArr, 0, n - 1); // sort by value

    // finding the min and max Index in the original array
    int i = 0;
    while (i < n)
    {
        int j = i;
        int minIdx = pairArr[i].index;
        int maxIdx = pairArr[i].index;

        // traverse the equal elements
        while (j < n && pairArr[j].value == pairArr[i].value)
        {
            if (pairArr[j].index < minIdx)
                minIdx = pairArr[j].index;
            if (pairArr[j].index > maxIdx)
                maxIdx = pairArr[j].index;
            j++;
        }

        if (maxIdx - minIdx > k)
        {
            printf("%d %d\n", minIdx, maxIdx);
            free(pairArr);
            return;
        }
        i = j;
    }
    // if no pair found
    printf("-1\n");
    free(pairArr);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));

    // accepting input into array
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findPair(arr, n, k);

    free(arr);
    return 0;
}