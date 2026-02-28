#include <bits/stdc++.h>
using namespace std;

// insertion sort - 0 to n-1, keep swapping with the left elements till it can't be swapped
void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        // will place this jth element in it's correct position by swapping with the
        // elements to its left until it can't be swapped
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

// improved insertion sort with fewer swaps and operations
void insertionSort(vector<int> &arr, int n)
{
    int key = nums[i];
    int j = i - 1;

    while (j >= 0 && nums[j] > key)
    {
        nums[j + 1] = nums[j]; // shift right
        j--;
    }
    nums[j + 1] = key;
}

int main()
{

    return 0;
}