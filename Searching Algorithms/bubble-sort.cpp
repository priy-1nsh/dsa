#include <bits/stdc++.h>
using namespace std;

// move the biggest element to the right by adjacent swaps
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didSwap = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
    }
}

int main()
{

    return 0;
}