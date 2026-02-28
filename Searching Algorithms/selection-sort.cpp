#include <bits/stdc++.h>
using namespace std;

// find the minimum element for each i and swap
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minimumIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minimumIndex] > arr[j])
            {
                minimumIndex = j;
            }
        }
        // if the minimum Index is still i - then nothing to swap
        if (minimumIndex != i)
            swap(arr[i], arr[minimumIndex]);
    }
}

int main()
{

    return 0;
}