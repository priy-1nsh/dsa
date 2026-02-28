#include <bits/stdc++.h>
using namespace std;

int quick(vector<int> &arr, int low, int high);
void quickSort(vector<int> &arr, int low, int high);

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int partitionIndex = quick(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
}

int quick(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] < pivot)
            i++;
        while (j >= low + 1 && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // put pivot in correct position
    return j;
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 3};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";
}
