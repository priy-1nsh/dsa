#include <bits/stdc++.h>
using namespace std;

// previous smaller element
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int> pse(n);
    for (int i = 0; i < n; i++)
    {
        int found = 0;
        for (int j = i; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                pse[i] = arr[j];
                found = 1;
                break;
            }
            if (found != 1)
                pse[i] = -1;
        }
    }
    return pse;
}

int main()
{
    vector<int> arr = {6, 7, 3, 7, 8, 2, 9, 3, 11, 88};
    int n = arr.size();
    vector<int> ans = prevSmallerElement(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}