#include <bits/stdc++.h>
using namespace std;

void leftRotateByOne(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

void leftRotateByK(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;
    while (k--)
    {
        leftRotateByOne(arr);
    }
}

int main()
{
    vector<int> arr = {1, 5, 4, 2};
    int n = arr.size();
    int k = 2;
    leftRotateByK(arr, k);
    // print the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}